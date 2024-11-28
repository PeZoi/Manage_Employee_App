#pragma once
#include "DatabaseManagerSQLite.h"
#include "DepartmentRepositorySQLite.h"
#include "EmployeeRepositorySQLite.h"
#include "AttendanceEventRepositorySQLite.h"
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

DatabaseManagerSQLite::DatabaseManagerSQLite()
{
	departmentRepository = new DepartmentRepositorySQLite(this);
	employeeRepository = new EmployeeRepositorySQLite(this);
	attendanceEventRepository = new AttendanceEventRepositorySQLite(this);
}

DatabaseManagerSQLite::~DatabaseManagerSQLite() {
	delete departmentRepository;
	delete employeeRepository;
	delete attendanceEventRepository;
}

IDepartmentRepository* DatabaseManagerSQLite::getDepartmentRepository()
{
	return departmentRepository;
}

IEmployeeRepository* DatabaseManagerSQLite::getEmployeeRepository()
{
	return employeeRepository;
}

IAttendanceEventRepository* DatabaseManagerSQLite::getAttendanceEventRepository()
{
	return attendanceEventRepository;
}

bool DatabaseManagerSQLite::excuteInitTable(QString pathDefault) {
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

bool DatabaseManagerSQLite::connectToDatabase()
{
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString dbName = settings.value("database/path").toString();
	QFile dbFile(dbName);

	if (!dbFile.exists()) {
		QString dirDatabase = settings.value("database/dirDB").toString();
		QString _dbName = "manage_employee_sqlite.db";

		QString fullPath = QDir(dirDatabase).filePath(_dbName);
		dbFile.setFileName(fullPath);

		if (!dbFile.open(QIODevice::WriteOnly)) {
			qDebug() << "Không thể tạo file mới:" << dbName;
			exit(0);
		}
		else {
			settings.setValue("database/path", fullPath);
			qDebug() << "File đã được tạo mới:" << _dbName;
			dbFile.close();
		}
	}

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

	if (!db.open()) {
		qDebug() << "Failed to open database:" << db.lastError().text();
		return false;
	}

	QString sqlFilePath = settings.value("database/initSQLite").toString();
	if (!excuteInitTable(sqlFilePath)) {
		qDebug() << "Lỗi khi thực thi các câu lệnh SQL từ file.";
		return false;
	}

	qDebug() << "Connected to database successfully.";
	return true;
}

void DatabaseManagerSQLite::closeDatabase()
{
	if (db.isOpen()) {
		db.close();
		qDebug() << "Database closed.";
	}
}

bool DatabaseManagerSQLite::executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) {
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


bool DatabaseManagerSQLite::executeCreate(const QString& queryStr)
{
	QSqlQuery query(db);

	if (!query.exec(queryStr)) {
		qDebug() << "Failed to execute query:" << query.lastError().text();
		return false;
	}
	qDebug() << "Query executed successfully.";
	return true;
}

QSqlQuery DatabaseManagerSQLite::executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params) {
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

QSqlQuery DatabaseManagerSQLite::executeQuery(const QString& queryStr) {
	QSqlQuery query(db);
	if (!query.exec(queryStr)) {
		qDebug() << "Query execution failed:" << query.lastError().text();
		return QSqlQuery();
	}
	return query;
}


void DatabaseManagerSQLite::bankupData() {
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString databasePath = settings.value("database/path").toString();

	QString savePath = QFileDialog::getSaveFileName(nullptr, "Chọn nơi lưu file backup", "", "SQLite Database (*.db)");
	QString timestamp = QDateTime::currentDateTime().toString("ddMMyyyy_HHmmss");

	if (savePath.isEmpty()) {
		qDebug() << "Người dùng đã hủy quá trình backup.";
		return;
	}

	QFileInfo fileInfo(savePath);
	QString baseName = fileInfo.completeBaseName();
	QString dir = fileInfo.path();
	savePath = QString("%1/%2_sqlite_%3.db").arg(dir).arg(baseName).arg(timestamp);

	// Đảm bảo file kết thúc bằng đuôi .db
	if (QFile::copy(databasePath, savePath)) {
		qDebug() << "Backup data SQLite thành công tại:" << savePath;
	}
	else {
		qDebug() << "Backup data SQLite không thành công.";
	}
}
void DatabaseManagerSQLite::restoreData() {
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString databasePath = settings.value("database/path").toString();

	QString openPath = QFileDialog::getOpenFileName(nullptr, "Chọn file backup để restore", "", "SQLite Database (*.db)");

	if (openPath.isEmpty()) {
		qDebug() << "Người dùng đã hủy quá trình restore.";
		return;
	}

	QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

	if (!QFile::remove(databasePath)) {
		qDebug() << "Không thể xóa database cũ tại:" << databasePath;
		return;
	}

	if (QFile::copy(openPath, databasePath)) {
		qDebug() << "Backup data SQLite thành công";
	}
	else {
		qDebug() << "Backup data SQLite không thành công";
	}
}