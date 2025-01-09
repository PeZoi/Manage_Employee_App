#include "DialogChangeDatabase.h"
#include "Constant.h"
#include "ErrorLabel.h"
#include "EmployeeModel.h"
#include "DatabaseSingleton.h"
#include "DatabaseManagerMYSQL.h"
#include "DatabaseManagerSQLServer.h"
#include <QSettings>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

DialogChangeDatabase::DialogChangeDatabase(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::DialogChangeDatabaseClass())
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Form Change Database"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->password->setEchoMode(QLineEdit::Password);

	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	if (settings.value("database/type").toString() == "SQLITE") {
		QString dbName = settings.value("database/path").toString();
		ui->sql_path->setText(dbName);
		ui->radio_exist->setChecked(true);
	}

	connect(ui->sql_list, &QComboBox::currentTextChanged, this, &DialogChangeDatabase::handleChangeSQLList);
	connect(ui->connect, &QPushButton::clicked, this, &DialogChangeDatabase::handleConnectDB);
	connect(ui->select_sqlite, &QPushButton::clicked, this, [this]() {
		QString sqlPath = QFileDialog::getOpenFileName(this, "Select .db File", "", "Database Files (*.db)");
		ui->sql_path->setText(sqlPath);
		});
}

DialogChangeDatabase::~DialogChangeDatabase()
{
	delete ui;
}

Ui::DialogChangeDatabaseClass* DialogChangeDatabase::getUi() {
	return ui;
}

void DialogChangeDatabase::handleChangeSQLList(QString name) {
	if (name == "SQLite") {
		ui->stackedWidget->setCurrentIndex(0);
	}
	else {
		ui->stackedWidget->setCurrentIndex(1);
	}
}

void DialogChangeDatabase::handleConnectDB() {
	QString path = ui->sql_path->text();
	QString hostName = ui->host_name->text();
	QString dbName = ui->db_name->text();
	QString port = ui->port->text();
	QString username = ui->username->text();
	QString password = ui->password->text();
	QString type = ui->sql_list->currentText();

	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);
	try
	{
		if (type == "SQLITE") {
			QFile file(path);
			QDir dir(QFileInfo(path).absolutePath());

			if (!dir.exists()) {
				ErrorLabel* error = new ErrorLabel(tr("  The path is invalid."));
				error->showTemporary(ui->verticalLayout, 3000);
				return;
			}

			if (!isFileDB(path)) {
				ErrorLabel* error = new ErrorLabel(tr("  File extension is not in the correct format (.db). Location: ") + path);
				error->showTemporary(ui->verticalLayout, 3000);
				return;
			}

			if (ui->radio_exist->isChecked()) {
				if (!file.exists()) {
					ErrorLabel* error = new ErrorLabel(tr("  Failed to open the database file. Location: ") + path);
					error->showTemporary(ui->verticalLayout, 3000);
					return;
				}
			}

			if (ui->radio_create->isChecked()) {
				file.open(QIODevice::WriteOnly);
			}

			settings.setValue("database/path", path);
		}
		else {
			QSqlDatabase db;
			if (type == "MYSQL") {
				db = QSqlDatabase::addDatabase("QMYSQL");
			}
			else {
				db = QSqlDatabase::addDatabase("QODBC");
			}
			db.setHostName(hostName);
			db.setDatabaseName(dbName);
			db.setUserName(username);
			db.setPassword(password);
			db.setPort(port.toInt());

			if (!db.open()) {
				ErrorLabel* error = new ErrorLabel("  Failed to connect " + type + " database");
				error->showTemporary(ui->verticalLayout, 3000);
				return;
			}

			//QString queryString = "SELECT COUNT(*) FROM employee WHERE role = 'ADMIN';";
			//QSqlQuery query = db.exec(queryString);
			//bool checkHaveAdmin = true;

			//if (query.next()) {
			//	checkHaveAdmin = query.value(0).toInt() > 0;
			//}

			//if (!checkHaveAdmin) {
			//	IDatabaseManager* databaseManager = DatabaseSingleton::getInstance()->getDB();
			//	databaseManager->connectToDatabase();
			//	EmployeeModel employee = databaseManager->getEmployeeRepository()->getById("admin");
			//	databaseManager->closeDatabase();

			//	QString queryInsert = "INSERT INTO employee ("
			//		"id, first_name, last_name, password, department, "
			//		"date_of_birth, start_date_of_work, status, is_enabled, "
			//		"avatar, role, email, phone_number, address, is_allow_password, "
			//		"iri_right, iri_left) "
			//		"VALUES (:id, :first_name, :last_name, :password, :department, "
			//		":date_of_birth, :start_date_of_work, :status, :is_enabled, "
			//		":avatar, :role, :email, :phone_number, :address, :is_allow_password, "
			//		":iri_right, :iri_left);";

			//	query.prepare(queryInsert);

			//	// Gắn các giá trị cho placeholder
			//	query.bindValue(":id", employee.getId());
			//	query.bindValue(":first_name", employee.getFirstName());
			//	query.bindValue(":last_name", employee.getLastName());
			//	query.bindValue(":password", employee.getPassword());
			//	query.bindValue(":department", employee.getDepartment().getName());
			//	query.bindValue(":date_of_birth", employee.getDateOfBirth().toString("dd/MM/yyyy"));
			//	query.bindValue(":start_date_of_work", employee.getStartDateOfWork().toString("dd/MM/yyyy"));
			//	query.bindValue(":status", employee.getStatus());
			//	query.bindValue(":is_enabled", employee.getIsEnabled());
			//	query.bindValue(":avatar", employee.getAvatar());
			//	query.bindValue(":role", employee.getRole());
			//	query.bindValue(":email", employee.getEmail().trimmed().isEmpty() ? QVariant(QVariant::String) : employee.getEmail());
			//	query.bindValue(":phone_number", employee.getPhoneNumber());
			//	query.bindValue(":address", employee.getAddress());
			//	query.bindValue(":is_allow_password", employee.getIsAllowPassword());
			//	query.bindValue(":iri_right", employee.getIriRight());
			//	query.bindValue(":iri_left", employee.getIriLeft());

			//	// Thực thi câu lệnh
			//	if (!query.exec()) {
			//		qDebug() << "Lỗi thực thi truy vấn, Khi chuyển đổi ADMIN:" << query.lastError().text();
			//		return;
			//	}

			//	db.close();
			//}

			settings.setValue("database/hostName", hostName);
			settings.setValue("database/dbName", dbName);
			settings.setValue("database/username", username);
			settings.setValue("database/password", password);
			settings.setValue("database/port", port);
		}
	}
	catch (const std::exception&)
	{
		ErrorLabel* error = new ErrorLabel(tr("  Failed something ..."));
		error->showTemporary(ui->verticalLayout, 3000);
		return;
		qDebug() << "Có lỗi gì đó Dialog Change Database";
	}

	qDebug() << "Change database Successfully";
	settings.setValue("database/type", type);
	emit changeDB(type);
	this->accept();
}

bool DialogChangeDatabase::isFileDB(QString path) {
	return path.endsWith(".db", Qt::CaseInsensitive);
}