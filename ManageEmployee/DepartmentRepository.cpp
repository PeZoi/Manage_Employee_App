#include "DepartmentRepository.h"

DepartmentRepository::DepartmentRepository() {
}

bool DepartmentRepository::add(DepartmentModel department) {
	DatabaseManager::connectToDatabase();
	QString query = "INSERT INTO department (name, description) "
		"VALUES (:name, :description);";

	QMap<QString, QVariant> params;
	params[":name"] = department.getName();
	params[":description"] = department.getDescription();

	return DatabaseManager::executeCreate(query, params);
}

bool DepartmentRepository::update(DepartmentModel department) {
	DatabaseManager::connectToDatabase();
	QString query = "UPDATE department SET description = :description "
		"WHERE name = :name ;";

	QMap<QString, QVariant> params;
	params[":name"] = department.getName();
	params[":description"] = department.getDescription();

	return DatabaseManager::executeCreate(query, params);
}

bool DepartmentRepository::_delete(QString name) {
	DatabaseManager::connectToDatabase();
	QString query = "DELETE FROM department WHERE name = :name";
	QMap<QString, QVariant> params;
	params[":name"] = name;

	return DatabaseManager::executeCreate(query, params);
}

QList<DepartmentModel> DepartmentRepository::getAll() {
	QString query = "SELECT * FROM department";
	QSqlQuery result = DatabaseManager::executeQuery(query);

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

QList<DepartmentModel> DepartmentRepository::getAllIgnoreOthers() {
	DatabaseManager::connectToDatabase();
	QString query = "SELECT * FROM department WHERE name != 'Others';";
	QSqlQuery result = DatabaseManager::executeQuery(query);

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

DepartmentModel DepartmentRepository::getByName(QString name) {
	DatabaseManager::connectToDatabase();
	QString query = "SELECT * FROM department WHERE name = :name";
	QMap<QString, QVariant> params;
	params[":name"] = name;
	QSqlQuery result = DatabaseManager::executeQuery2(query, params);

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