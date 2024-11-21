#include "DialogChangeDatabase.h"
#include "Constant.h"
#include "ErrorLabel.h"
#include <QSettings>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QSqlDatabase>

DialogChangeDatabase::DialogChangeDatabase(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::DialogChangeDatabaseClass())
{
	ui->setupUi(this);

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
	qDebug() << name;
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
				ErrorLabel* error = new ErrorLabel("  The path is invalid.");
				error->showTemporary(ui->verticalLayout, 3000);
				return;
			}

			if (!isFileDB(path)) {
				ErrorLabel* error = new ErrorLabel("  File extension is not in the correct format (.db). Location: " + path);
				error->showTemporary(ui->verticalLayout, 3000);
				return;
			}

			if (ui->radio_exist->isChecked()) {
				if (!file.exists()) {
					ErrorLabel* error = new ErrorLabel("  Failed to open the database file. Location: " + path);
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

			settings.setValue("database/hostName", hostName);
			settings.setValue("database/dbName", dbName);
			settings.setValue("database/username", username);
			settings.setValue("database/password", password);
			settings.setValue("database/port", port);
		}
	}
	catch (const std::exception&)
	{
		ErrorLabel* error = new ErrorLabel("  Failed something ...");
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