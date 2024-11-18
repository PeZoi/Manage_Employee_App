#include "DialogFormEmployee.h"
#include "ManageDepartment.h"
#include "IriTracker.h"
#include "ErrorLabel.h"
#include "DepartmentModel.h"
#include "EmployeeModel.h"
#include <QBuffer>
#include <QThread>
#include <QDebug>


DialogFormEmployee::DialogFormEmployee(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui.password->setDisabled(true);
	ui.confirm_password->setDisabled(true);

	ui.password->setEchoMode(QLineEdit::Password);
	ui.confirm_password->setEchoMode(QLineEdit::Password);

	connect(ui.submit, SIGNAL(clicked()), this, SLOT(handleSubmit()));
	connect(ui.cancelButton, &QPushButton::clicked, this, &DialogFormEmployee::onClickCancel);
	connect(ui.select_avatar, &QPushButton::clicked, this, [this]() {
		emit uploadAvatar(this, isEditMode_employee);
		});

	connect(ui.scan_left, &QPushButton::clicked, this, [this]() {
		processStreaming();
		side = "LEFT";
		});

	connect(ui.scan_right, &QPushButton::clicked, this, [this]() {
		processStreaming();
		side = "RIGHT";
		});

	connect(ui.is_allow_password, &QCheckBox::toggled, this, [this](bool checked) {
		if (checked) {
			ui.password->setDisabled(false);
			ui.confirm_password->setDisabled(false);
		}
		else {
			ui.password->setDisabled(true);
			ui.confirm_password->setDisabled(true);
		}
		});
}

DialogFormEmployee::~DialogFormEmployee()
{
	this->deleteLater();
	captureThread = nullptr;
	iriTracker = nullptr;
}
void DialogFormEmployee::onClickCancel() {
	this->deleteLater();
}

void DialogFormEmployee::handleSubmit() {
	QString id = ui.id->text();
	QString firstName = ui.first_name->text();
	QString lastName = ui.last_name->text();
	QString password = ui.password->text();
	QString confirmPassword = ui.confirm_password->text();
	QString department = ui.department->currentText();
	QDate dateOfBirth = ui.date_of_birth->date();
	QDate startDateOfWork = ui.start_date_of_work->date();
	QString email = ui.email->text();
	QString phoneNumber = ui.phone_number->text();
	QString address = ui.address->toPlainText();
	bool isAllowPassword = ui.is_allow_password->isChecked();
	bool isEnabled = ui.is_enabled->isChecked();


	if (id.trimmed().isEmpty() || firstName.trimmed().isEmpty() || lastName.trimmed().isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  All required fields must be filled in");
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	if (isAllowPassword && (password.trimmed().isEmpty() || confirmPassword.trimmed().isEmpty())) {
		ErrorLabel* error = new ErrorLabel("  The password field cannot be left empty");
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	if (isAllowPassword && (password.length() < 4)) {
		ErrorLabel* error = new ErrorLabel("  Password must be at least 4 characters long.");
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	if (isAllowPassword && (password != confirmPassword)) {
		ErrorLabel* error = new ErrorLabel("  Passwords do not match");
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	DepartmentModel _department = DepartmentModel();
	_department.setName(department);

	EmployeeModel employee = EmployeeModel(
		id,
		firstName,
		lastName,
		password,
		_department,
		dateOfBirth,
		startDateOfWork,
		"",
		!isEnabled,
		avatarPath,
		"STAFF",
		email,
		phoneNumber,
		address,
		isAllowPassword,
		"",
		""
	);

	emit submit(employee, isEditMode_employee, this);
}

void DialogFormEmployee::setMode(bool _isEditMode) {
	isEditMode_employee = _isEditMode;
	avatarPath = "";
	iri_rightPath = "";
	iri_leftPath = "";
	ui.avatar->setScene(NULL);

	ui.tabWidget->setCurrentIndex(0);

	ui.id->setDisabled(_isEditMode);

	ui.id->clear();
	ui.first_name->clear();
	ui.last_name->clear();
	ui.password->clear();
	ui.confirm_password->clear();
	ui.department->setCurrentIndex(0);
	ui.date_of_birth->setDate(QDate::currentDate());
	ui.start_date_of_work->setDate(QDate::currentDate());
	ui.email->clear();
	ui.phone_number->clear();
	ui.address->clear();
	ui.is_allow_password->setChecked(false);
	ui.is_enabled->setChecked(false);

}

void DialogFormEmployee::setValue(EmployeeModel employee) {
	ui.id->setText(employee.getId());
	ui.first_name->setText(employee.getFirstName());
	ui.last_name->setText(employee.getLastName());
	ui.password->setText(employee.getPassword());
	ui.confirm_password->setText(employee.getPassword());
	ui.department->setCurrentText(employee.getDepartment().getName());
	ui.date_of_birth->setDate(employee.getDateOfBirth());
	ui.start_date_of_work->setDate(employee.getStartDateOfWork());
	ui.email->setText(employee.getEmail());
	ui.phone_number->setText(employee.getPhoneNumber());
	ui.address->setPlainText(employee.getAddress());
	ui.is_allow_password->setChecked(employee.getIsAllowPassword());
	ui.is_enabled->setChecked(!employee.getIsEnabled());

	idSelected = employee.getId();
	avatarPath = employee.getAvatar();

	QPixmap avatar;
	avatar.load(avatarPath);

	QGraphicsScene* scene = new QGraphicsScene(this);
	scene->addPixmap(avatar);

	ui.avatar->setScene(scene);
	ui.avatar->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

Ui::DialogFormEmployeeClass DialogFormEmployee::getUi() {
	return ui;
}

void DialogFormEmployee::processStreaming() {
	// Tạo thread mới cho quá trình capture
	captureThread = new QThread();
	iriTracker = new IriTracker();

	// Kết nối tín hiệu từ IriTracker đến updateFrame trong UI thread
	connect(iriTracker, &IriTracker::newImageCaptured, this, &DialogFormEmployee::updateFrame);

	// Kết nối tín hiệu captureFinished để dừng thread khi quá trình capture hoàn tất
	connect(iriTracker, &IriTracker::captureFinished, captureThread, &QThread::quit);

	// Di chuyển IriTracker vào thread để xử lý capture
	iriTracker->moveToThread(captureThread);

	// Kết nối captureThread đã được bắt đầu để gọi run trong IriTracker
	connect(captureThread, &QThread::started, iriTracker, &IriTracker::run);

	// Kết nối để tự động xóa IriTracker khi hoàn tất
	connect(iriTracker, &IriTracker::captureFinished, iriTracker, &QObject::deleteLater);
	connect(captureThread, &QThread::finished, captureThread, &QObject::deleteLater);

	// Bắt đầu thread
	captureThread->start();
}
void DialogFormEmployee::updateFrame(const unsigned char* imageData, int imageLen, int imageWidth, int imageHeight) {
	if (imageData && imageWidth > 0 && imageHeight > 0) {
		// Tạo QImage từ dữ liệu raw
		QImage image(imageData, imageWidth, imageHeight, QImage::Format_Grayscale8);
		QPixmap pixmap = QPixmap::fromImage(image);
		//ui.testLabel->setPixmap(pixmap.scaled(ui.testLabel->size(), Qt::KeepAspectRatio));

		if (side == "LEFT") {
			ui.iri_left->setPixmap(pixmap.scaled(ui.iri_left->size(), Qt::KeepAspectRatio));
		}
		else {
			ui.iri_right->setPixmap(pixmap.scaled(ui.iri_right->size(), Qt::KeepAspectRatio));
		}
	}
	else {
		qDebug() << "Dữ liệu hình ảnh không hợp lệ.";
	}
}
void DialogFormEmployee::handleCapture(QString side) {
	qDebug() << "Đang scan ...";
	/*QString iri = IriTracker::run([this]() {
		updateFrame();
		});

	if (iri.trimmed().isEmpty()) {
		msgBox.setText("Scan fail ...");
		msgBox.exec();
	}
	QPixmap iriImg;
	iriImg.load(iri);
	QGraphicsScene* scene = new QGraphicsScene(this);
	scene->addPixmap(iriImg);

	if (side == "LEFT") {
		iri_leftPath = iri;
	}
	else {
		iri_rightPath = iri;
	}*/
}
