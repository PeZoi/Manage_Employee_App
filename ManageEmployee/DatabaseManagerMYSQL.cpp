#include "DatabaseManagerMYSQL.h"
#include "DepartmentRepositoryMYSQL.h"
#include "EmployeeRepositoryMYSQL.h"
#include "AttendanceEventRepositoryMYSQL.h"
#include "ExceptionRepositoryMYSQL.h"
#include "IDepartmentRepository.h"
#include "IEmployeeRepository.h"
#include "IAttendanceEventRepository.h"
#include "DepartmentModel.h"
#include "Constant.h"
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSettings>
#include <QFileDialog>
#include <QProcess>

DatabaseManagerMYSQL::DatabaseManagerMYSQL()
{
	departmentRepository = new DepartmentRepositoryMYSQL(this);
	employeeRepository = new EmployeeRepositoryMYSQL(this);
	attendanceEventRepository = new AttendanceEventRepositoryMYSQL(this);
	exceptionRepository = new ExceptionRepositoryMYSQL(this);
}

DatabaseManagerMYSQL::~DatabaseManagerMYSQL() {
	delete departmentRepository;
	delete employeeRepository;
	delete attendanceEventRepository;
	delete exceptionRepository;
}

IDepartmentRepository* DatabaseManagerMYSQL::getDepartmentRepository()
{
	return departmentRepository;
}

IEmployeeRepository* DatabaseManagerMYSQL::getEmployeeRepository()
{
	return employeeRepository;
}

IAttendanceEventRepository* DatabaseManagerMYSQL::getAttendanceEventRepository()
{
	return attendanceEventRepository;
}

IExceptionRepository* DatabaseManagerMYSQL::getExceptionRepository()
{
	return exceptionRepository;
}

bool DatabaseManagerMYSQL::excuteInitTable(QString pathDefault) {
	QFile file(pathDefault);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Không thể mở file SQL:" << file.errorString();
		return false;
	}

	QTextStream in(&file);
	QString sqlContent = in.readAll();
	file.close();

	QStringList queries = sqlContent.split(";", Qt::SkipEmptyParts);
	QSqlQuery query(db);

	for (const QString& singleQuery : queries) {
		QString trimmedQuery = singleQuery.trimmed();
		if (trimmedQuery.isEmpty()) continue;

		if (!query.exec(trimmedQuery)) {
			qDebug() << "Lỗi khi thực thi truy vấn:" << query.lastError().text();
			return false;
		}
	}

	return true;
}

bool DatabaseManagerMYSQL::connectToDatabase()
{
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString hostName = settings.value("database/hostName").toString();
	QString dbName = settings.value("database/dbName").toString();
	QString userName = settings.value("database/username").toString();
	QString password = settings.value("database/password").toString();
	int port = settings.value("database/port").toInt();

	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(hostName);
	db.setDatabaseName(dbName);
	db.setUserName(userName);
	db.setPassword(password);
	db.setPort(port);

	if (!db.open()) {
		qDebug() << "Failed to connect to MySQL database:" << db.lastError().text();
		return false;
	}

	QString sqlFilePath = settings.value("database/initMYSQL").toString();
	if (!excuteInitTable(sqlFilePath)) {
		qDebug() << "Lỗi khi thực thi các câu lệnh SQL từ file.";
		return false;
	}

	qDebug() << "Connected to MySQL database successfully.";
	return true;
}


void DatabaseManagerMYSQL::closeDatabase()
{
	if (db.isOpen()) {
		db.close();
		qDebug() << "Database closed.";
	}
}

bool DatabaseManagerMYSQL::executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) {
	QSqlQuery query(db);
	query.prepare(queryStr);

	for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
		query.bindValue(it.key(), it.value());
	}

	if (!query.exec()) {
		qDebug() << "Failed to execute query:" << query.lastError().text();
		return false;
	}
	qDebug() << "Query executed successfully.";
	return true;
}


bool DatabaseManagerMYSQL::executeCreate(const QString& queryStr)
{
	QSqlQuery query(db);

	if (!query.exec(queryStr)) {
		qDebug() << "Failed to execute query:" << query.lastError().text();
		return false;
	}
	qDebug() << "Query executed successfully.";
	return true;
}

QSqlQuery DatabaseManagerMYSQL::executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params) {
	QSqlQuery query(db);
	query.prepare(queryStr);

	for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
		query.bindValue(it.key(), it.value());
	}

	if (!query.exec()) {
		qDebug() << "Failed to execute query:" << query.lastError().text();
		return query;
	}
	qDebug() << "Query executed successfully.";
	return query;
}

QSqlQuery DatabaseManagerMYSQL::executeQuery(const QString& queryStr) {
	QSqlQuery query(db);
	if (!query.exec(queryStr)) {
		qDebug() << "Query execution failed:" << query.lastError().text();
		return QSqlQuery();
	}
	return query;
}


void DatabaseManagerMYSQL::bankupData() {
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString hostName = settings.value("database/hostName").toString();
	QString dbName = settings.value("database/dbName").toString();
	QString userName = settings.value("database/username").toString();
	QString password = settings.value("database/password").toString();

	QString filePath = QFileDialog::getSaveFileName(nullptr, "Chọn nơi lưu file backup", "", "SQL Files (*.sql)");

	if (filePath.isEmpty()) {
		qDebug() << "Người dùng đã hủy quá trình bankup.";
		return;
	}

	if (!filePath.endsWith(".sql")) {
		filePath += ".sql";
	}

	QString timestamp = QDateTime::currentDateTime().toString("ddMMyyyy_HHmmss");
	QFileInfo fileInfo(filePath);
	QString baseName = fileInfo.completeBaseName();
	QString dirPath = fileInfo.absolutePath();

	filePath = QString("%1/%2_mysql_%3.sql").arg(dirPath).arg(baseName).arg(timestamp);

	QProcess process;
	QString command = QString("mysqldump -h %1 -u %2 -p%3 %4 > %5")
		.arg(hostName)
		.arg(userName)
		.arg(password)
		.arg(dbName)
		.arg(filePath);

	qDebug() << "Command:" << command;

	process.start("cmd", QStringList() << "/c" << command);
	process.waitForFinished();

	if (process.exitCode() == 0) {
		qDebug() << "Backup data MYSQL thành công";
	}
	else {
		qDebug() << "Backup data MYSQL không thành công";
	}
}
void DatabaseManagerMYSQL::restoreData() {
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString hostName = settings.value("database/hostName").toString();
	QString dbName = settings.value("database/dbName").toString();
	QString userName = settings.value("database/username").toString();
	QString password = settings.value("database/password").toString();

	QString filePath = QFileDialog::getOpenFileName(nullptr, "Chọn file backup để restore", "", "SQL Files (*.sql)");

	if (filePath.isEmpty()) {
		qDebug() << "Người dùng đã hủy quá trình restore.";
		return;
	}

	QProcess process;
	QString command = QString("mysql -h %1 -u %2 -p%3 %4 < %5")
		.arg(hostName)
		.arg(userName)
		.arg(password)
		.arg(dbName)
		.arg(filePath);

	process.start("cmd", QStringList() << "/c" << command);
	process.waitForFinished();

	if (process.exitCode() == 0) {
		qDebug() << "Restore data MYSQL thành công";

	}
	else {
		qDebug() << "Restore data MYSQL không thành công";
	}
}