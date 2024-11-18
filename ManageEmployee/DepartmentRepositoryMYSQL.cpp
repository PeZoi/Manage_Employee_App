#include "DepartmentRepositoryMYSQL.h"
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DepartmentRepositoryMYSQL::DepartmentRepositoryMYSQL(IDatabaseManager* _db) {
	db = _db;
}

bool DepartmentRepositoryMYSQL::add(DepartmentModel department) {
	QString query = "INSERT INTO department (name, description) "
		"VALUES (:name, :description);";

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
	QString query = "DELETE FROM department WHERE name = :name";
	QMap<QString, QVariant> params;
	params[":name"] = name;

	return db->executeCreate(query, params);
}

QList<DepartmentModel> DepartmentRepositoryMYSQL::getAll() {
	QString query = "SELECT * FROM department";
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

	QString query = "SELECT * FROM department WHERE name != 'Others';";
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

	DepartmentModel department = DepartmentModel();

	if (result.next()) {
		department.setName(result.value(0).toString());
		department.setDescription(result.value(1).toString());
		return department;
	}
	else {
		return DepartmentModel();
	}

}