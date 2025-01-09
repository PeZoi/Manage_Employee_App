#include "DepartmentRepositoryMYSQL.h"
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DepartmentRepositoryMYSQL::DepartmentRepositoryMYSQL(IDatabaseManager* _db) {
	db = _db;
}

bool DepartmentRepositoryMYSQL::add(DepartmentModel department) {
	QString query = "INSERT INTO department (name, description, is_deleted) "
		"VALUES (:name, :description, 0);";

	QMap<QString, QVariant> params;
	params[":name"] = department.getName();
	params[":description"] = department.getDescription();

	return db->executeCreate(query, params);
}

bool DepartmentRepositoryMYSQL::update(DepartmentModel department) {
	QString query = "UPDATE department SET description = :description "
		"WHERE name = :name ;";

	QMap<QString, QVariant> params;
	params[":name"] = department.getName();
	params[":description"] = department.getDescription();

	return db->executeCreate(query, params);
}

bool DepartmentRepositoryMYSQL::_delete(QString name) {
	QString queryDeleteDepartment = "UPDATE department SET is_deleted = 1 WHERE name = :name";
	QString queryUpdateEmployee = "UPDATE employee SET department = 'Others' WHERE department = :name";
	QMap<QString, QVariant> params;
	params[":name"] = name;

	db->executeCreate(queryUpdateEmployee, params);
	return db->executeCreate(queryDeleteDepartment, params);
}

QList<DepartmentModel> DepartmentRepositoryMYSQL::getAll() {
	QString query = "SELECT * FROM department WHERE is_deleted = 0;";
	QSqlQuery result = db->executeQuery(query);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return QList<DepartmentModel>();
	}
	QList<DepartmentModel> list;

	while (result.next()) {
		DepartmentModel department = DepartmentModel();
		department.setName(result.value(0).toString());
		department.setDescription(result.value(1).toString());

		list.append(department);
	}

	return list;
}

QList<DepartmentModel> DepartmentRepositoryMYSQL::getAllIgnoreOthers() {

	QString query = "SELECT * FROM department WHERE name != 'Others' AND is_deleted = 0;";
	QSqlQuery result = db->executeQuery(query);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return QList<DepartmentModel>();
	}
	QList<DepartmentModel> list;

	while (result.next()) {
		DepartmentModel department = DepartmentModel();
		department.setName(result.value(0).toString());
		department.setDescription(result.value(1).toString());

		list.append(department);
	}

	return list;
}

DepartmentModel DepartmentRepositoryMYSQL::getByName(QString name) {

	QString query = "SELECT * FROM department WHERE name = :name";
	QMap<QString, QVariant> params;
	params[":name"] = name;
	QSqlQuery result = db->executeQuery2(query, params);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return DepartmentModel();
	}

	

	if (result.next()) {
		DepartmentModel department = DepartmentModel(result.value(0).toString(), result.value(1).toString(), result.value(2).toBool());
		return department;
	}
	else {
		return DepartmentModel();
	}

}

bool DepartmentRepositoryMYSQL::switchIsDeleted(bool value, DepartmentModel department) {
	QString queryDeleteDepartment = "UPDATE department SET is_deleted = :is_deleted, description = :description WHERE name = :name";
	QMap<QString, QVariant> params;
	params[":name"] = department.getName();
	params[":description"] = department.getDescription();
	params[":is_deleted"] = value;

	return db->executeCreate(queryDeleteDepartment, params);
}