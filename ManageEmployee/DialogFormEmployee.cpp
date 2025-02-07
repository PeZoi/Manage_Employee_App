#include "DialogFormEmployee.h"
#include "ManageDepartment.h"
#include "IriTracker.h"
#include "ErrorLabel.h"
#include "DepartmentModel.h"
#include "EmployeeModel.h"
#include "Utils.h"
#include "IriTrackerSingleton.h"
#include <QMetaMethod>
#include <QBuffer>
#include <QThread>
#include <QDebug>
#include <QByteArray>

bool checkConnectSignal = false;
bool flagFoundDevice = false;
bool isRunningFirst = true;
bool isRunningIriLeft = false;
bool isRunningIriRight = false;

DialogFormEmployee::DialogFormEmployee(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(tr("Form Employee"));

	iriTracker = IriTrackerSingleton::getIriCaptureEyes();
	iriTracker->isCancelDialogEmployee = false;

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

	// Add event click label
	ui.iri_right->installEventFilter(this);
	ui.iri_left->installEventFilter(this);

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

	connect(IriTrackerSingleton::getIriTrackerGetDevice(), &IriTracker::foundDevice, this, &DialogFormEmployee::switchImage, Qt::QueuedConnection);
	//switchImage(true);
}

DialogFormEmployee::~DialogFormEmployee()
{

	if (iriTracker) {
		disconnect(iriTracker, &IriTracker::imageProcessed, this, &DialogFormEmployee::updateFrame);
		disconnect(iriTracker, &IriTracker::imageResult, this, &DialogFormEmployee::updateFrame);
		disconnect(iriTracker, &IriTracker::resultTemplate, this, &DialogFormEmployee::handleReciveTemplate);
	}

	disconnect(IriTrackerSingleton::getIriTrackerGetDevice(), &IriTracker::foundDevice, this, nullptr);

	iriTracker->isCancelDialogEmployee = true;
	captureThread = nullptr;
	checkConnectSignal = false;
	flagFoundDevice = false;
	isRunningFirst = true;
	isRunningIriLeft = false;
	isRunningIriRight = false;

}
void DialogFormEmployee::onClickCancel() {
	if (IriTrackerSingleton::getStreamThread()->isRunning()) {
		IriTrackerSingleton::getStreamThread()->quit();
	}
	emit cancel();
	close();
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
		ErrorLabel* error = new ErrorLabel(tr("  All required fields must be filled in"));
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	if (isAllowPassword && (password.trimmed().isEmpty() || confirmPassword.trimmed().isEmpty())) {
		ErrorLabel* error = new ErrorLabel(tr("  The password field cannot be left empty"));
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	if (isAllowPassword && (password.length() < 4)) {
		ErrorLabel* error = new ErrorLabel(tr("  Password must be at least 4 characters long."));
		error->showTemporary(ui.errorLayout, 3000);
		return;
	}

	if (isAllowPassword && (password != confirmPassword)) {
		ErrorLabel* error = new ErrorLabel(tr("  Passwords do not match"));
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
		iri_rightPath,
		iri_leftPath
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

	if (employee.getIriLeft().size() > 0) {
		ui.label_left->setText(tr("   (Registed)"));
		ui.label_left->setStyleSheet("color: green;");
	}

	if (employee.getIriRight().size() > 0) {
		ui.label_right->setText(tr("   (Registed)"));
		ui.label_right->setStyleSheet("color: green;");
	}

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
	
	// Kiểm tra và kết nối tín hiệu nếu chưa kết nối
	if (!checkConnectSignal) {
		connect(iriTracker, &IriTracker::imageProcessed, this, &DialogFormEmployee::updateFrame, Qt::QueuedConnection);
		connect(iriTracker, &IriTracker::imageResult, this, &DialogFormEmployee::updateFrame, Qt::QueuedConnection);
		connect(iriTracker, &IriTracker::resultTemplate, this, &DialogFormEmployee::handleReciveTemplate, Qt::QueuedConnection);
		connect(iriTracker, &IriTracker::isExistIri, this, [this](bool check) {
			if (check) {
				ErrorLabel* error = new ErrorLabel(tr("  Iri already exists"));
				error->showTemporary(ui.errorLayout, 3000);
			}
			}, Qt::QueuedConnection);

		checkConnectSignal = true;
	}

	// Dừng luồng hiện tại nếu nó đang chạy
	if (IriTrackerSingleton::getStreamThread()->isRunning()) {
		IriTrackerSingleton::getStreamThread()->quit();
	}

	if (checkConnectSignal) {
		disconnect(IriTrackerSingleton::getStreamThread(), &QThread::started, nullptr, nullptr);
	}

	// Di chuyển tracker sang thread và kết nối run()
	iriTracker->moveToThread(IriTrackerSingleton::getStreamThread());
	connect(IriTrackerSingleton::getStreamThread(), &QThread::started, [=]() {
		iriTracker->run(false, true, true);
		});

	// Bắt đầu luồng
	IriTrackerSingleton::getStreamThread()->start();
}
void DialogFormEmployee::updateFrame(const unsigned char* imageData, int imageLen, int imageWidth, int imageHeight) {
	if (imageData && imageWidth > 0 && imageHeight > 0) {
		// Tạo QImage từ dữ liệu raw
		QImage image(imageData, imageWidth, imageHeight, QImage::Format_Grayscale8);
		QPixmap pixmap = QPixmap::fromImage(image);

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

void DialogFormEmployee::handleReciveTemplate(const unsigned char* buffer, int size) {

	if (IriTrackerSingleton::getStreamThread()->isRunning()) {
		IriTrackerSingleton::getStreamThread()->quit();
	}
	QByteArray templateBlob = Utils::templateConvertToByte(buffer, size);
	if (side == "LEFT") {
		iri_leftPath = templateBlob;
	}
	else {
		iri_rightPath = templateBlob;
	}
}

bool DialogFormEmployee::eventFilter(QObject* obj, QEvent* event) {
	if (event->type() == QEvent::MouseButtonPress) {
		if (obj == ui.iri_left) {

			side = "LEFT";
			isRunningIriLeft = true;
			isRunningIriRight = false;
			processStreaming();
			return true;
		}
		else if (obj == ui.iri_right) {
			side = "RIGHT";
			isRunningIriLeft = false;
			isRunningIriRight = true;
			processStreaming();
			return true;
		}
	}
	return QWidget::eventFilter(obj, event);
}

void DialogFormEmployee::switchImage(bool isFoundDevice) {

	/*if (!isFoundDevice) {
		isRunningIriLeft = false;
		isRunningIriRight = false;
	}

	if ((isRunningIriLeft || isRunningIriRight) && isFoundDevice) {
		if (isRunningIriLeft && iri_rightPath.isEmpty()) {
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		else if (isRunningIriRight && iri_leftPath.isEmpty()) {
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		return;
	}
	if (isRunningFirst || isFoundDevice != flagFoundDevice) {
		if (isFoundDevice) {
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		else {
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
		}

		flagFoundDevice = isFoundDevice;
		isRunningFirst = false;
	}*/

	if (!isFoundDevice) {
		isRunningIriLeft = false;
		isRunningIriRight = false;
	}

	if ((isRunningIriLeft || isRunningIriRight) && isFoundDevice) {
		if (isRunningIriLeft && iri_rightPath.isEmpty()) {
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		else if (isRunningIriRight && iri_leftPath.isEmpty()) {
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		return;
	}
	if (isFoundDevice) {
		
		if (!iri_leftPath.isEmpty()) {
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		else if (!iri_rightPath.isEmpty()) {
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
		else {
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
		}
	}
	else {
		if (!iri_leftPath.isEmpty()) {
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
		}
		else if (!iri_rightPath.isEmpty()) {
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
		}
		else {
			ui.iri_left->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
			ui.iri_right->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
		}
	}
}