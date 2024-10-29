#include "DialogFormEmployee.h"
#include "ManageDepartment.h"
#include "IriTracker.h"
#include <QDate>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QPixmap>

bool isEditMode_employee = false;
QString idSelected = "";
QString avatarPath = "";
QString iri_rightPath = "";
QString iri_leftPath = "";

DialogFormEmployee::DialogFormEmployee(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.tabWidget->setTabText(0, "Thông tin chung");
	ui.tabWidget->setTabText(1, "Thông tin liên lạc");
	ui.tabWidget->setTabText(2, "Ảnh mắt");
	
	renderDepartments();
	ui.password->setDisabled(true);
	ui.confirm_password->setDisabled(true);

	connect(ui.submit, SIGNAL(clicked()), this, SLOT(handleSubmit()));
	connect(ui.select_avatar, SIGNAL(clicked()), this, SLOT(handleUploadAvatar()));

	connect(this, &DialogFormEmployee::editModeChanged, this, &DialogFormEmployee::renderDepartments);

	connect(ui.scan_left, &QPushButton::clicked, this, [this]() {
		qDebug() << "Đang scan ...";
		QString iriLeft = IriTracker::run();

		if (iriLeft.trimmed().isEmpty()) {
			msgBox.setText("Scan fail ...");
			msgBox.exec();
		}

		iri_leftPath = iriLeft;

		QPixmap iriImg;
		iriImg.load(iriLeft);

		QGraphicsScene* scene = new QGraphicsScene(this);
		scene->addPixmap(iriImg);

		ui.iri_left->setScene(scene);
		ui.iri_left->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
		});

	connect(ui.scan_right, &QPushButton::clicked, this, [this]() {
		qDebug() << "Đang scan ...";
		QString iriRight = IriTracker::run();
		if (iriRight.trimmed().isEmpty()) {
			msgBox.setText("Scan fail ...");
			msgBox.exec();
		}

		iri_rightPath = iriRight;

		QPixmap iriImg;
		iriImg.load(iriRight);

		QGraphicsScene* scene = new QGraphicsScene(this);
		scene->addPixmap(iriImg);

		ui.iri_right->setScene(scene);
		ui.iri_right->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
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
{}

bool DialogFormEmployee::validateExists(const QString& id, const QString& email) {

	if (!isEditMode_employee) {
		QString checkIdQuery = "SELECT COUNT(*) FROM employee WHERE id = '" + id + "';";
		QSqlQuery result1 = db.executeQuery(checkIdQuery);
		if (result1.next() && result1.value(0).toInt() > 0) {
			msgBox.setText("Mã nhân viên đã tồn tại");
			msgBox.exec();
			return true;
		}
	}

	if (!email.trimmed().isEmpty()) {
		QString checkEmailQuery = "SELECT id FROM employee WHERE email = '" + email + "';";
		QSqlQuery result2 = db.executeQuery(checkEmailQuery);

		if (result2.next()) {
			QString existingId = result2.value(0).toString();

			if (isEditMode_employee && existingId != id) {
				msgBox.setText("Email đã tồn tại");
				msgBox.exec();
				return true;
			}

			if (!isEditMode_employee) {
				msgBox.setText("Email đã tồn tại");
				msgBox.exec();
				return true;
			}
		}
	}
	return false;
}

void DialogFormEmployee::handleSubmit() {
	QString id = ui.id->text();
	QString firstName = ui.first_name->text();
	QString lastName = ui.last_name->text();
	QString password = ui.password->text();
	QString confirmPassword = ui.confirm_password->text();
	QString department = ui.department->currentText();
	QString dateOfBirth = ui.date_of_birth->date().toString("dd/MM/yyyy");
	QString startDateOfWork = ui.start_date_of_work->date().toString("dd/MM/yyyy");
	QString email = ui.email->text();
	QString phoneNumber = ui.phone_number->text();
	QString address = ui.address->text();
	bool isAllowPassword = ui.is_allow_password->isChecked();
	bool isEnabled = ui.is_enabled->isChecked();


	if (id.trimmed().isEmpty() || firstName.trimmed().isEmpty() || lastName.trimmed().isEmpty()) {
		msgBox.setText("Cần điền đầy đủ các trường yêu cầu");
		msgBox.exec();
		return;
	}

	if (isAllowPassword && (password.trimmed().isEmpty() || confirmPassword.trimmed().isEmpty())) {
		msgBox.setText("Trường mật khẩu không được để trống");
		msgBox.exec();
		return;
	}

	if (isAllowPassword && (password != confirmPassword)) {
		msgBox.setText("Mật khẩu không trùng khớp");
		msgBox.exec();
		return;
	}

	db.connectToDatabase();

	if (validateExists(id, email)) {
		return;
	}

	if (!isEditMode_employee) {
		QString insertEmployeeQuery = "INSERT INTO employee ("
			"id, first_name, last_name, password, department, "
			"date_of_birth, start_date_of_work, status, is_enabled, "
			"avatar, role, email, phone_number, address, is_allow_password, "
			"iri_right, iri_left) "
			"VALUES (:id, :first_name, :last_name, :password, :department, "
			":date_of_birth, :start_date_of_work, :status, :is_enabled, "
			":avatar, :role, :email, :phone_number, :address, :is_allow_password, "
			":iri_right, :iri_left);";


		QMap<QString, QVariant> params;
		params[":id"] = id;
		params[":first_name"] = firstName;
		params[":last_name"] = lastName;
		params[":password"] = password;
		params[":department"] = department;
		params[":date_of_birth"] = dateOfBirth;
		params[":start_date_of_work"] = startDateOfWork;
		params[":role"] = "STAFF";
		params[":email"] = email.trimmed().isEmpty() ? NULL : email;
		params[":phone_number"] = phoneNumber;
		params[":address"] = address;
		params[":is_enabled"] = isEnabled;
		params[":is_allow_password"] = isAllowPassword;

		params[":status"] = "Về";
		params[":avatar"] = avatarPath.isEmpty() ? NULL : avatarPath;

		params[":iri_right"] = iri_rightPath;
		params[":iri_left"] = iri_leftPath;

		if (!db.executeCreate(insertEmployeeQuery, params)) {
			msgBox.setText("Thêm mới thất bại");
			msgBox.exec();
			return;
		}
	}
	else {
		QString updateEmployeeQuery = "UPDATE employee SET "
			"first_name = :first_name, "
			"last_name = :last_name, "
			"password = :password, "
			"department = :department, "
			"date_of_birth = :date_of_birth, "
			"start_date_of_work = :start_date_of_work, "
			"is_enabled = :is_enabled, "
			"email = :email, "
			"phone_number = :phone_number, "
			"address = :address, "
			"is_allow_password = :is_allow_password "
			"WHERE id = :id;";

		QMap<QString, QVariant> params;
		params[":id"] = id;
		params[":first_name"] = firstName;
		params[":last_name"] = lastName;
		params[":password"] = password;
		params[":department"] = department;
		params[":date_of_birth"] = dateOfBirth;
		params[":start_date_of_work"] = startDateOfWork;
		params[":email"] = email.trimmed().isEmpty() ? NULL : email;
		params[":phone_number"] = phoneNumber;
		params[":address"] = address;
		params[":is_enabled"] = isEnabled;
		params[":is_allow_password"] = isAllowPassword;

		params[":avatar"] = avatarPath.isEmpty() ? NULL : avatarPath;

		if (!db.executeCreate(updateEmployeeQuery, params)) {
			msgBox.setText("Cập nhật thất bại");
			msgBox.exec();
			return;
		}
	}


	db.closeDatabase();

	emit excuteDBSuccessful();

	this->accept();

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

	emit editModeChanged();
}

void DialogFormEmployee::renderDepartments() {
	/*ManageDepartment md;
	QSqlQuery result = md.getAllDepartment();

	ui.department->clear();

	ui.department->addItem("Khác");

	while (result.next()) {
		ui.department->addItem(result.value(0).toString());
	}*/
}

void DialogFormEmployee::setValue(QSqlQuery result) {
	if (result.next()) {
		ui.id->setText(result.value("id").toString());
		ui.first_name->setText(result.value("first_name").toString());
		ui.last_name->setText(result.value("last_name").toString());
		ui.password->setText(result.value("password").toString());
		ui.confirm_password->setText(result.value("password").toString());
		ui.department->setCurrentText(result.value("department").toString());
		ui.date_of_birth->setDate(QDate::fromString(result.value("date_of_birth").toString(), "dd/MM/yyyy"));
		ui.start_date_of_work->setDate(QDate::fromString(result.value("start_date_of_work").toString(), "dd/MM/yyyy"));
		ui.email->setText(result.value("email").toString());
		ui.phone_number->setText(result.value("phone_number").toString());
		ui.address->setText(result.value("address").toString());
		ui.is_allow_password->setChecked(result.value("is_allow_password").toBool());
		ui.is_enabled->setChecked(!result.value("is_enabled").toBool());

		idSelected = result.value("id").toString();
		avatarPath = result.value("avatar").toString();

		QPixmap avatar;
		avatar.load(avatarPath);

		QGraphicsScene* scene = new QGraphicsScene(this);
		scene->addPixmap(avatar);

		ui.avatar->setScene(scene);
		ui.avatar->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
	}
	else {
		QMessageBox::warning(this, "Thông báo", "Không tìm thấy thông tin nhân viên.");
	}
}

void DialogFormEmployee::handleUploadAvatar() {
	QString picpath = QFileDialog::getOpenFileName(this, tr("Open file"), "C://Users//MY PC//OneDrive//Pictures", "JPG File(*.jpg);;PNG File(*.png)");
	QString savePath = "D://IriTech//Code//ManageEmployee//image//" + QFileInfo(picpath).baseName() + "_" + idSelected + "." + QFileInfo(picpath).suffix();
	QFile::copy(picpath, savePath);

	QPixmap avatar;
	avatar.load(savePath);

	QGraphicsScene* scene = new QGraphicsScene(this);
	scene->addPixmap(avatar);

	ui.avatar->setScene(scene);
	ui.avatar->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

	if (isEditMode_employee) {
		db.connectToDatabase();
		QSqlQuery query;
		query.prepare("UPDATE employee SET avatar='" + savePath + "' WHERE id = '" + idSelected + "';");
		query.exec();
		db.closeDatabase();
	}

	avatarPath = savePath;

}