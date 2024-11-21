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


bool DatabaseManagerSQLite::connectToDatabase()
{
	QString pathIni = Constant::PATH_CONFIG;
	QSettings settings(pathIni, QSettings::IniFormat);

	QString dbName = settings.value("database/path").toString();
	QFile dbFile(dbName);

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

	if (!db.open()) {
		qDebug() << "Failed to open database:" << db.lastError().text();
		return false;
	}

	QString createTableDepartmentQuery =
		"CREATE TABLE IF NOT EXISTS department ("
		"name TEXT PRIMARY KEY, "
		"description TEXT); "
		"INSERT OR IGNORE INTO department (name, description) VALUES ('Others', '');";

	QString createTableEmployeeQuery =
		"CREATE TABLE IF NOT EXISTS employee ("
		"id TEXT PRIMARY KEY, "
		"first_name TEXT, "
		"last_name TEXT, "
		"password TEXT, "
		"department TEXT, "
		"date_of_birth TEXT, "
		"start_date_of_work TEXT, "
		"status TEXT, "
		"is_enabled BOOLEAN NOT NULL DEFAULT 1, "
		"avatar TEXT, "
		"role TEXT, "
		"email TEXT UNIQUE, "
		"phone_number TEXT, "
		"address TEXT, "
		"is_allow_password BOOLEAN NOT NULL DEFAULT 0, "
		"iri_right TEXT, "
		"iri_left TEXT, "
		"FOREIGN KEY (department) REFERENCES department(name));";

	QString createTableAttendanceEvent =
		"CREATE TABLE IF NOT EXISTS attendance_event ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"type_event TEXT, "
		"date_event TEXT, "
		"time_event TEXT, "
		"exception INTEGER, "
		"session INTEGER, "
		"employee_id TEXT, "
		"FOREIGN KEY(employee_id) REFERENCES employee(id));";

	// Thực thi các lệnh tạo bảng
	executeCreate(createTableDepartmentQuery);
	executeCreate(createTableEmployeeQuery);
	executeCreate(createTableAttendanceEvent);

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


