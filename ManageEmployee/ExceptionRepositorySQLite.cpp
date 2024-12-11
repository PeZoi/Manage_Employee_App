#include "ExceptionRepositorySQLite.h"
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ExceptionRepositorySQLite::ExceptionRepositorySQLite(IDatabaseManager* _db) {
	db = _db;
}

bool ExceptionRepositorySQLite::add(ExceptionModel exception) {
	QString query = "INSERT INTO exception (name, paidHours, paidCoefficient, workCoefficient, isCaculate) "
		"VALUES (:name, :paidHours, :paidCoefficient, :workCoefficient, :isCaculate);";

	QMap<QString, QVariant> params;
	params[":name"] = exception.getName();
	params[":paidHours"] = exception.getPaidHours();
	params[":paidCoefficient"] = exception.getPaidCoefficient();
	params[":workCoefficient"] = exception.getWorkCoefficient();
	params[":isCaculate"] = exception.getIsCaculate();

	return db->executeCreate(query, params);
}

bool ExceptionRepositorySQLite::update(ExceptionModel exception) {
	QString query = "UPDATE exception SET name = :name, paidHours = :paidHours, paidCoefficient = :paidCoefficient, workCoefficient = :workCoefficient, isCaculate = :isCaculate "
		"WHERE id = :id ;";

	QMap<QString, QVariant> params;
	params[":id"] = exception.getId();
	params[":name"] = exception.getName();
	params[":paidHours"] = exception.getPaidHours();
	params[":paidCoefficient"] = exception.getPaidCoefficient();
	params[":workCoefficient"] = exception.getWorkCoefficient();
	params[":isCaculate"] = exception.getIsCaculate();

	return db->executeCreate(query, params);
}

bool ExceptionRepositorySQLite::_delete(int id) {
	QString query = "DELETE FROM exception WHERE id = :id ;";

	QMap<QString, QVariant> params;
	params[":id"] = id;

	return db->executeCreate(query, params);
}

QList<ExceptionModel> ExceptionRepositorySQLite::getAll() {
	QString query = "SELECT * FROM exception;";
	QSqlQuery result = db->executeQuery(query);
	QList<ExceptionModel> list;

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return list;
	}

	while (result.next()) {
		ExceptionModel exception;
		exception.setId(result.value("id").toInt());
		exception.setName(result.value("name").toString());
		exception.setPaidHours(result.value("paidHours").toString());
		exception.setPaidCoefficient(result.value("paidCoefficient").toFloat());
		exception.setWorkCoefficient(result.value("workCoefficient").toFloat());
		exception.setIsCaculate(result.value("isCaculate").toBool());

		list.append(exception);
	}

	return list;
}

ExceptionModel ExceptionRepositorySQLite::getById(int id) {
	QString query = "SELECT * FROM exception WHERE id = :id;";

	QMap<QString, QVariant> params;
	params[":id"] = id;
	QSqlQuery result = db->executeQuery2(query, params);

	if (!result.exec()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return ExceptionModel();
	}

	if (result.next()) {
		ExceptionModel exception;
		exception.setId(result.value("id").toInt());
		exception.setName(result.value("name").toString());
		exception.setPaidHours(result.value("paidHours").toString());
		exception.setPaidCoefficient(result.value("paidCoefficient").toFloat());
		exception.setWorkCoefficient(result.value("workCoefficient").toFloat());
		exception.setIsCaculate(result.value("isCaculate").toBool());
		return exception;
	}

	return ExceptionModel();
}
ExceptionModel ExceptionRepositorySQLite::getByName(QString name) {
	QString query = "SELECT * FROM exception WHERE name = :name;";

	QMap<QString, QVariant> params;
	params[":name"] = name;
	QSqlQuery result = db->executeQuery2(query, params);

	if (!result.exec()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return ExceptionModel();
	}

	if (result.next()) {
		ExceptionModel exception;
		exception.setId(result.value("id").toInt());
		exception.setName(result.value("name").toString());
		exception.setPaidHours(result.value("paidHours").toString());
		exception.setPaidCoefficient(result.value("paidCoefficient").toFloat());
		exception.setWorkCoefficient(result.value("workCoefficient").toFloat());
		exception.setIsCaculate(result.value("isCaculate").toBool());
		return exception;
	}

	return ExceptionModel();
}
bool ExceptionRepositorySQLite::checkExistByName(QString name) {
	QString query = "SELECT COUNT(*) FROM exception WHERE name = :name;";

	QMap<QString, QVariant> params;
	params[":name"] = name;
	QSqlQuery result = db->executeQuery2(query, params);

	if (!result.exec()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return false;
	}

	if (result.next()) {
		return result.value(0).toInt() > 0;
	}

	return false;
}