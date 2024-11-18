#include "DatabaseManagerSQLServer.h"
#include "DepartmentRepositorySQLServer.h"
#include "EmployeeRepositorySQLServer.h"
#include "AttendanceEventRepositorySQLServer.h"
#include "IDepartmentRepository.h"
#include "IEmployeeRepository.h"
#include "IAttendanceEventRepository.h"
#include "DepartmentModel.h"
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManagerSQLServer::DatabaseManagerSQLServer()
{
	departmentRepository = new DepartmentRepositorySQLServer(this);
	employeeRepository = new EmployeeRepositorySQLServer(this);
	attendanceEventRepository = new AttendanceEventRepositorySQLServer(this);
}

DatabaseManagerSQLServer::~DatabaseManagerSQLServer() {
	delete departmentRepository;
	delete employeeRepository;
	delete attendanceEventRepository;
}

IDepartmentRepository* DatabaseManagerSQLServer::getDepartmentRepository()
{
	return departmentRepository;
}

IEmployeeRepository* DatabaseManagerSQLServer::getEmployeeRepository()
{
	return employeeRepository;
}

IAttendanceEventRepository* DatabaseManagerSQLServer::getAttendanceEventRepository()
{
	return attendanceEventRepository;
}


bool DatabaseManagerSQLServer::connectToDatabase()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("sqlserver_iritech");
	db.setUserName("sa");
	db.setPassword("123456asd");

	if (!db.open()) {
		qDebug() << "Failed to connect to SQL Server database:" << db.lastError().text();
		return false;
	}

	QString createTableDepartmentQuery =
		"IF NOT EXISTS (SELECT * FROM sysobjects WHERE name = 'department' AND xtype = 'U') "
		"BEGIN "
		"CREATE TABLE department ("
		"name NVARCHAR(255) PRIMARY KEY, "
		"description NVARCHAR(MAX)"
		");"
		"INSERT INTO department (name, description) "
		"VALUES('Others', ''); "
		"END;";

	QString createTableEmployeeQuery =
		"IF NOT EXISTS (SELECT * FROM sysobjects WHERE name = 'employee' AND xtype = 'U') "
		"CREATE TABLE employee ("
		"id NVARCHAR(255) PRIMARY KEY, "
		"first_name NVARCHAR(255), "
		"last_name NVARCHAR(255), "
		"password NVARCHAR(255), "
		"department NVARCHAR(255), "
		"date_of_birth NVARCHAR(255), "
		"start_date_of_work NVARCHAR(255), "
		"status NVARCHAR(255), "
		"is_enabled BIT NOT NULL DEFAULT 1, "
		"avatar NVARCHAR(MAX), "
		"role NVARCHAR(255), "
		"email NVARCHAR(255), "
		"phone_number NVARCHAR(255), "
		"address NVARCHAR(MAX), "
		"is_allow_password BIT NOT NULL DEFAULT 0, "
		"iri_right NVARCHAR(MAX), "
		"iri_left NVARCHAR(MAX), "
		"FOREIGN KEY (department) REFERENCES department(name)"
		"); ";

	QString createTableAttendanceEventQuery =
		"IF NOT EXISTS (SELECT * FROM sysobjects WHERE name = 'attendance_event' AND xtype = 'U') "
		"CREATE TABLE attendance_event ("
		"id INT IDENTITY(1,1) PRIMARY KEY, "
		"type_event NVARCHAR(255), "
		"date_event NVARCHAR(255), "
		"time_event NVARCHAR(255), "
		"exception INT, "
		"session INT, "
		"employee_id NVARCHAR(255), "
		"FOREIGN KEY (employee_id) REFERENCES employee(id)"
		");";

	// Thực thi các truy vấn tạo bảng
	executeCreate(createTableDepartmentQuery);
	executeCreate(createTableEmployeeQuery);
	executeCreate(createTableAttendanceEventQuery);

	// Thêm dữ liệu mặc định vào bảng `department`
	/*DepartmentModel departmentDefault = DepartmentModel("Others", "");
	departmentRepository->add(departmentDefault);*/

	qDebug() << "Connected to SQL Server database successfully.";
	return true;
}


void DatabaseManagerSQLServer::closeDatabase()
{
	if (db.isOpen()) {
		db.close();
		qDebug() << "Database closed.";
	}
}

bool DatabaseManagerSQLServer::executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) {
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


bool DatabaseManagerSQLServer::executeCreate(const QString& queryStr)
{
	QSqlQuery query(db);

	if (!query.exec(queryStr)) {
		qDebug() << "Failed to execute query:" << query.lastError().text();
		return false;
	}
	qDebug() << "Query executed successfully.";
	return true;
}

QSqlQuery DatabaseManagerSQLServer::executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params) {
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

QSqlQuery DatabaseManagerSQLServer::executeQuery(const QString& queryStr) {
	QSqlQuery query(db);
	if (!query.exec(queryStr)) {
		qDebug() << "Query execution failed:" << query.lastError().text();
		return QSqlQuery();
	}
	return query;
}


