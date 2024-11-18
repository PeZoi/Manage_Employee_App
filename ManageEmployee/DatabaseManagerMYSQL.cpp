#include "DatabaseManagerMYSQL.h"
#include "DepartmentRepositoryMYSQL.h"
#include "EmployeeRepositoryMYSQL.h"
#include "AttendanceEventRepositoryMYSQL.h"
#include "IDepartmentRepository.h"
#include "IEmployeeRepository.h"
#include "IAttendanceEventRepository.h"
#include "DepartmentModel.h"
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManagerMYSQL::DatabaseManagerMYSQL()
{
	departmentRepository = new DepartmentRepositoryMYSQL(this);
	employeeRepository = new EmployeeRepositoryMYSQL(this);
	attendanceEventRepository = new AttendanceEventRepositoryMYSQL(this);
}

DatabaseManagerMYSQL::~DatabaseManagerMYSQL() {
	delete departmentRepository;
	delete employeeRepository;
	delete attendanceEventRepository;
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


bool DatabaseManagerMYSQL::connectToDatabase()
{
	QString hostName = "localhost";
	QString dbName = "mysql_iritech";
	QString userName = "root";
	QString password = "root";

	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(hostName);
	db.setDatabaseName(dbName);
	db.setUserName(userName);
	db.setPassword(password);
	db.setPort(3306);

	if (!db.open()) {
		qDebug() << "Failed to connect to MySQL database:" << db.lastError().text();
		return false;
	}

	QString createTableDepartmentQuery =
		"CREATE TABLE IF NOT EXISTS department ("
		"name VARCHAR(255) PRIMARY KEY, "
		"description TEXT"
		");";

	QString createTableEmployeeQuery =
		"CREATE TABLE IF NOT EXISTS employee ("
		"id VARCHAR(255) PRIMARY KEY, "
		"first_name VARCHAR(255), "
		"last_name VARCHAR(255), "
		"password VARCHAR(255), "
		"department VARCHAR(255), "
		"date_of_birth VARCHAR(255), "
		"start_date_of_work VARCHAR(255), "
		"status VARCHAR(255), "
		"is_enabled BOOLEAN NOT NULL DEFAULT 1, "
		"avatar TEXT, "
		"role VARCHAR(255), "
		"email VARCHAR(255), "
		"phone_number VARCHAR(255), "
		"address TEXT, "
		"is_allow_password BOOLEAN NOT NULL DEFAULT 0, "
		"iri_right TEXT, "
		"iri_left TEXT, "
		"FOREIGN KEY (department) REFERENCES department(name)"
		");";

	QString createTableAttendanceEventQuery =
		"CREATE TABLE IF NOT EXISTS attendance_event ("
		"id INT AUTO_INCREMENT PRIMARY KEY, "
		"type_event VARCHAR(255), "
		"date_event VARCHAR(255), "
		"time_event VARCHAR(255), "
		"exception INT, "
		"session INT, "
		"employee_id VARCHAR(255), "
		"FOREIGN KEY (employee_id) REFERENCES employee(id)"
		");";

	// Thực thi các truy vấn tạo bảng
	executeCreate(createTableDepartmentQuery);
	executeCreate(createTableEmployeeQuery);
	executeCreate(createTableAttendanceEventQuery);

	// Thêm dữ liệu mặc định vào bảng `department`
	DepartmentModel departmentDefault = DepartmentModel("Others", "");
	departmentRepository->add(departmentDefault);

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


