#include "DialogFormAttendanceEvents.h"
#include "ErrorLabel.h"

DialogFormAttendanceEvents::DialogFormAttendanceEvents(QString employeeSelected, IDatabaseManager* _db,  QWidget* parent)
	: QDialog(parent), employeeSelected(employeeSelected), db(_db)
	, ui(new Ui::DialogFormAttendanceEventsClass())
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Form Attendance Events"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->radio_in_out->setChecked(true);


	QDate today = QDate::currentDate();
	QTime timeCheckinDefault(9, 0, 0);
	ui->dateTime_checkin->setDisplayFormat("dd/MM/yyyy hh:mm:ss");
	ui->dateTime_checkin->setDateTime(QDateTime(today, timeCheckinDefault));

	QTime timeCheckoutDefault(17, 0, 0);
	ui->dateTime_checkout->setDisplayFormat("dd/MM/yyyy hh:mm:ss");
	ui->dateTime_checkout->setDateTime(QDateTime(today, timeCheckoutDefault));

	ui->hours->setText("8.00");

	connect(ui->submit, &QPushButton::clicked, this, &DialogFormAttendanceEvents::handleSubmit);
	connect(ui->cancelButton, &QPushButton::clicked, this, [this]() {this->accept(); });

	connect(ui->dateTime_checkin, &QDateTimeEdit::dateTimeChanged, this, &DialogFormAttendanceEvents::handleCheckTimeCheckInOut);
	connect(ui->dateTime_checkout, &QDateTimeEdit::dateTimeChanged, this, &DialogFormAttendanceEvents::handleCheckTimeCheckInOut);

	connect(ui->radio_in_out, &QRadioButton::toggled, this, [this](bool checked) {
		if (checked) {
			ui->dateTime_checkin->setDisabled(false);
			ui->dateTime_checkout->setDisabled(false);
		}
		});

	connect(ui->radio_in, &QRadioButton::toggled, this, [this](bool checked) {
		if (checked) {
			ui->hours->setText("");
			ui->dateTime_checkout->setDisabled(true);
			ui->dateTime_checkin->setDisabled(false);
		}
		});

	connect(ui->radio_out, &QRadioButton::toggled, this, [this](bool checked) {
		if (checked) {
			ui->hours->setText("");
			ui->dateTime_checkin->setDisabled(true);
			ui->dateTime_checkout->setDisabled(false);
		}
		});

}

DialogFormAttendanceEvents::~DialogFormAttendanceEvents()
{
	delete ui;
}

Ui::DialogFormAttendanceEventsClass* DialogFormAttendanceEvents::getUi() {
	return ui;
}

void DialogFormAttendanceEvents::handleSubmit() {

	QString errorMsg = handleCheckTimeCheckInOut();

	if (!errorMsg.isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  " + errorMsg);
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	emit submit(employeeSelected, isEditMode, this);

}
void DialogFormAttendanceEvents::setMode(bool _isEditMode) {
	isEditMode = _isEditMode;

	if (_isEditMode) {
		ui->radio_in->setDisabled(true);
		ui->radio_in_out->setDisabled(true);
		ui->radio_out->setDisabled(true);
	}
	else {
		ui->radio_in->setDisabled(false);
		ui->radio_in_out->setDisabled(false);
		ui->radio_out->setDisabled(false);
	}
}
void DialogFormAttendanceEvents::setValue(const QList<AttendanceEventModel>& events) {
	QDate dateCheckin = QDate::fromString(events.at(0).getDateEvent(), "dd/MM/yyyy");
	QTime timeCheckin = QTime::fromString(events.at(0).getTime(), "hh:mm:ss");
	ui->dateTime_checkin->setDateTime(QDateTime(dateCheckin, timeCheckin));
	if (events.size() == 2) {
		QDate dateCheckout = QDate::fromString(events.at(1).getDateEvent(), "dd/MM/yyyy");
		QTime timeCheckout = QTime::fromString(events.at(1).getTime(), "hh:mm:ss");
		ui->dateTime_checkout->setDateTime(QDateTime(dateCheckout, timeCheckout));
		ui->radio_in_out->setChecked(true);
	}
	else {
		ui->radio_in->setChecked(true);
	}
}

QString DialogFormAttendanceEvents::handleCheckTimeCheckInOut() {
	db->connectToDatabase();
	QDateTime now = QDateTime::currentDateTime();

	QDateTime checkin = ui->dateTime_checkin->dateTime();
	QDateTime checkout = ui->dateTime_checkout->dateTime();

	QString errorMsg = "";

	if (ui->radio_in_out->isChecked()) {
		EmployeeModel employee = db->getEmployeeRepository()->getById(employeeSelected);

		if (checkin.date() < employee.getStartDateOfWork()) {
			errorMsg = tr("  Event time must be later than the start of working date.");
			ui->hours->setText(errorMsg);
			ui->hours->setStyleSheet("color: red; font-weight: bold");
			return errorMsg;
		}

		if (checkin.date() != checkout.date()) {
			errorMsg = tr("The 'IN' event and the 'OUT' event must be on the same date.");
			ui->hours->setText(errorMsg);
			ui->hours->setStyleSheet("color: red; font-weight: bold");
			return errorMsg;
		}

		if (checkin >= checkout) {
			errorMsg = tr("The 'IN' event must be followed by 'OUT' event.");
			ui->hours->setText(errorMsg);
			ui->hours->setStyleSheet("color: red; font-weight: bold");
			return errorMsg;
		}

		if (checkout > now || checkin > now) {
			errorMsg = tr("Cannot add event in the future time.");
			ui->hours->setText(errorMsg);
			ui->hours->setStyleSheet("color: red; font-weight: bold");
			return errorMsg;
		}

		ui->hours->setStyleSheet("color: black; font-weight: bold");
		qint64 seconds = checkin.secsTo(checkout);
		double hours = seconds / 3600.0;

		QString formattedHours = QString::number(hours, 'f', 2);
		ui->hours->setText(formattedHours);

		db->closeDatabase();
		return "";
	}
	else if (ui->radio_in->isChecked()) {
		if (checkin > now) {
			errorMsg = tr("Cannot add event in the future time.");
			ui->hours->setText(errorMsg);
			ui->hours->setStyleSheet("color: red; font-weight: bold");
			return errorMsg;
		}
	}
	else if (ui->radio_out->isChecked()) {
		if (checkout > now) {
			errorMsg = tr("Cannot add event in the future time.");
			ui->hours->setText(errorMsg);
			ui->hours->setStyleSheet("color: red; font-weight: bold");
			return errorMsg;
		}
	}
	ui->hours->setStyleSheet("color: black; font-weight: bold");
	ui->hours->setText("");
	return "";
}