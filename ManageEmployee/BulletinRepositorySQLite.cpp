#include "BulletinRepositorySQLite.h"
#include "Constant.h"
#include <QSqlQuery>
#include <QSqlError>

BulletinRepositorySQLite::BulletinRepositorySQLite(IDatabaseManager* _db) {
    db = _db;
}

bool BulletinRepositorySQLite::add(BulletinModel bulletin) {
    QString query = "INSERT INTO bulletin (title, content, start_date, end_date, is_active, is_priority, type) "
        "VALUES (:title, :content, :start_date, :end_date, :is_active, :is_priority, :type);";

    QMap<QString, QVariant> params;
    params[":title"] = bulletin.getTitle();
    params[":content"] = bulletin.getContent();
    params[":start_date"] = bulletin.getStartDate();
    params[":end_date"] = bulletin.getEndDate();
    params[":is_active"] = bulletin.getIsActive();
    params[":is_priority"] = bulletin.getIsPriority();
    params[":type"] = bulletin.getType();

    bool isSuccess = db->executeCreate(query, params);
    if (!isSuccess) {
        return false;
    }
    int newBulletinId = 0;

    QString querySelectNewBulletin = "SELECT * FROM bulletin ORDER BY id DESC LIMIT 1;";
    QSqlQuery querySQL;
    if (querySQL.exec(querySelectNewBulletin)) {
        if (querySQL.next()) {
            newBulletinId = querySQL.value("id").toInt();
        }
    }

    if (bulletin.getType() == Constant::B_TYPE_DEPARTMENT) {
        QString queryCreateBullentinDetail = "INSERT INTO bulletin_detail (bulletin_id, department_id) "
            "VALUES (:bulletin_id, :department_id);";

        QMap<QString, QVariant> paramsDetail;
        paramsDetail[":bulletin_id"] = newBulletinId;
        paramsDetail[":department_id"] = bulletin.getDepartment();
        db->executeCreate(queryCreateBullentinDetail, paramsDetail);
    }
    else if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE) {
        QString queryCreateBullentinDetail = "INSERT INTO bulletin_detail (bulletin_id, employee_id) "
            "VALUES (:bulletin_id, :employee_id);";
        QMap<QString, QVariant> paramsDetail;
        paramsDetail[":bulletin_id"] = newBulletinId;

        for (QString employeeId : bulletin.getEmployeeIds()) {
            paramsDetail[":employee_id"] = employeeId;
            db->executeCreate(queryCreateBullentinDetail, paramsDetail);
        }
    }

    return isSuccess;
}
bool BulletinRepositorySQLite::update(BulletinModel bulletin) {
	QString updateBulletinQuery = "UPDATE bulletin SET title = :title, content = :content, "
		"start_date = :start_date, end_date = :end_date, is_active = :is_active, "
		"is_priority = :is_priority, type = :type WHERE id = :id;";

	QMap<QString, QVariant> params;
	params[":id"] = bulletin.getId();
	params[":title"] = bulletin.getTitle();
	params[":content"] = bulletin.getContent();
	params[":start_date"] = bulletin.getStartDate();
	params[":end_date"] = bulletin.getEndDate();
	params[":is_active"] = bulletin.getIsActive();
	params[":is_priority"] = bulletin.getIsPriority();
	params[":type"] = bulletin.getType();

	bool bulletinUpdateSuccess = db->executeCreate(updateBulletinQuery, params);
	if (!bulletinUpdateSuccess) {
		qDebug() << "Failed to update bulletin record.";
		return false;
	}

	QString deleteOldDetailsQuery = "DELETE FROM bulletin_detail WHERE bulletin_id = :bulletin_id;";
	QMap<QString, QVariant> deleteParams;
	deleteParams[":bulletin_id"] = bulletin.getId();

	bool deleteOldDetailsSuccess = db->executeCreate(deleteOldDetailsQuery, deleteParams);
	if (!deleteOldDetailsSuccess) {
		qDebug() << "Failed to delete old bulletin_detail records.";
		return false;
	}

	if (bulletin.getType() == Constant::B_TYPE_DEPARTMENT) {
		QString insertDepartmentDetailQuery = "INSERT INTO bulletin_detail (bulletin_id, department_id) VALUES (:bulletin_id, :department_id);";

		QMap<QString, QVariant> paramsDetail;
		paramsDetail[":bulletin_id"] = bulletin.getId();
		paramsDetail[":department_id"] = bulletin.getDepartment();

		bool insertDepartmentSuccess = db->executeCreate(insertDepartmentDetailQuery, paramsDetail);
		if (!insertDepartmentSuccess) {
			qDebug() << "Failed to insert department bulletin_detail record.";
			return false;
		}
	}
	// Nếu loại thông báo là "employee"
	else if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE) {
		QString insertEmployeeDetailQuery = "INSERT INTO bulletin_detail (bulletin_id, employee_id) VALUES (:bulletin_id, :employee_id);";

		for (QString employeeId : bulletin.getEmployeeIds()) {
			QMap<QString, QVariant> paramsDetail;
			paramsDetail[":bulletin_id"] = bulletin.getId();
			paramsDetail[":employee_id"] = employeeId;

			bool insertEmployeeSuccess = db->executeCreate(insertEmployeeDetailQuery, paramsDetail);
			if (!insertEmployeeSuccess) {
				qDebug() << "Failed to insert employee bulletin_detail records.";
				return false;
			}
		}
	}

	return true;
}
bool BulletinRepositorySQLite::_delete(int id) {
	QString deleteDetailQuery = "DELETE FROM bulletin_detail WHERE bulletin_id = :bulletin_id;";
	QMap<QString, QVariant> params;
	params[":bulletin_id"] = id;

	bool detailDeleteSuccess = db->executeCreate(deleteDetailQuery, params);
	if (!detailDeleteSuccess) {
		qDebug() << "Failed to delete related bulletin_detail records.";
		return false;
	}

	QString deleteBulletinQuery = "DELETE FROM bulletin WHERE id = :bulletin_id;";
	bool bulletinDeleteSuccess = db->executeCreate(deleteBulletinQuery, params);
	if (!bulletinDeleteSuccess) {
		qDebug() << "Failed to delete bulletin record.";
		return false;
	}
	return true;
}
QList<BulletinModel> BulletinRepositorySQLite::getAll() {
	QList<BulletinModel> list;
	QString query = "SELECT * FROM bulletin;";
	QSqlQuery result = db->executeQuery(query);

	if (!result.isActive()) {
		qDebug() << "Query failed:" << result.lastError().text();
		return list;
	}

	while (result.next()) {
		BulletinModel bulletin;
		bulletin.setId(result.value("id").toInt());
		bulletin.setTitle(result.value("title").toString());
		bulletin.setContent(result.value("content").toString());
		bulletin.setStartDate(result.value("start_date").toString());
		bulletin.setEndDate(result.value("end_date").toString());
		bulletin.setIsActive(result.value("is_active").toBool());
		bulletin.setIsPriority(result.value("is_priority").toBool());
		bulletin.setType(result.value("type").toString());

		list.append(bulletin);
	}

	return list;
}
BulletinModel BulletinRepositorySQLite::getById(int id) {
	BulletinModel bulletin;

	QString selectBulletinQuery = "SELECT * FROM bulletin WHERE id = :id;";
	QMap<QString, QVariant> params;
	params[":id"] = id;

	QSqlQuery result = db->executeQuery2(selectBulletinQuery, params);
	if (!result.isActive()) {
		qDebug() << "Query failed to retrieve bulletin:" << result.lastError().text();
		return bulletin;
	}

	if (result.next()) {
		bulletin.setId(result.value("id").toInt());
		bulletin.setTitle(result.value("title").toString());
		bulletin.setContent(result.value("content").toString());
		bulletin.setStartDate(result.value("start_date").toString());
		bulletin.setEndDate(result.value("end_date").toString());
		bulletin.setIsActive(result.value("is_active").toBool());
		bulletin.setIsPriority(result.value("is_priority").toBool());
		bulletin.setType(result.value("type").toString());
	}
	else {
		qDebug() << "No bulletin found with ID:" << id;
		return bulletin;
	}

	if (bulletin.getType() == Constant::B_TYPE_DEPARTMENT) {
		QString selectDepartmentQuery = "SELECT department_id FROM bulletin_detail WHERE bulletin_id = :bulletin_id;";
		QMap<QString, QVariant> paramsDetail;
		paramsDetail[":bulletin_id"] = id;

		QSqlQuery detailResult = db->executeQuery2(selectDepartmentQuery, paramsDetail);
		if (detailResult.next()) {
			bulletin.setDepartment(detailResult.value("department_id").toString());
		}
	}
	else if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE) {
		QString selectEmployeesQuery = "SELECT employee_id FROM bulletin_detail WHERE bulletin_id = :bulletin_id;";
		QMap<QString, QVariant> paramsDetail;
		paramsDetail[":bulletin_id"] = id;

		QSqlQuery detailResult = db->executeQuery2(selectEmployeesQuery, paramsDetail);
		QVector<QString> employeeIds;
		while (detailResult.next()) {
			employeeIds.append(detailResult.value("employee_id").toString());
		}
		bulletin.setEmployeeIds(employeeIds);
	}

	return bulletin;
}
QList<BulletinModel> BulletinRepositorySQLite::getByCurrentDate() {
	QList<BulletinModel> list;
	QString queryGetAll =
		"SELECT * FROM bulletin WHERE "
		"DATE(substr(start_date, 7, 4) || '-' || substr(start_date, 4, 2) || '-' || substr(start_date, 1, 2)) <= DATE('now') AND "
		"DATE(substr(end_date, 7, 4) || '-' || substr(end_date, 4, 2) || '-' || substr(end_date, 1, 2)) >= DATE('now');";

	QSqlQuery result = db->executeQuery(queryGetAll);
	if (!result.isActive()) {
		qDebug() << "Query failed to retrieve bulletin:" << result.lastError().text();
		return list;
	}

	while (result.next()) {
		BulletinModel bulletin;
		bulletin.setId(result.value("id").toInt());
		bulletin.setTitle(result.value("title").toString());
		bulletin.setContent(result.value("content").toString());
		bulletin.setStartDate(result.value("start_date").toString());
		bulletin.setEndDate(result.value("end_date").toString());
		bulletin.setIsActive(result.value("is_active").toBool());
		bulletin.setIsPriority(result.value("is_priority").toBool());
		bulletin.setType(result.value("type").toString());

		if (bulletin.getType() == Constant::B_TYPE_DEPARTMENT) {
			QString selectDepartmentQuery = "SELECT department_id FROM bulletin_detail WHERE bulletin_id = :bulletin_id;";
			QMap<QString, QVariant> paramsDetail;
			paramsDetail[":bulletin_id"] = bulletin.getId();

			QSqlQuery detailResult = db->executeQuery2(selectDepartmentQuery, paramsDetail);
			if (detailResult.next()) {
				bulletin.setDepartment(detailResult.value("department_id").toString());
			}
		}
		else if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE) {
			QString selectEmployeesQuery = "SELECT employee_id FROM bulletin_detail WHERE bulletin_id = :bulletin_id;";
			QMap<QString, QVariant> paramsDetail;
			paramsDetail[":bulletin_id"] = bulletin.getId();

			QSqlQuery detailResult = db->executeQuery2(selectEmployeesQuery, paramsDetail);
			QVector<QString> employeeIds;
			while (detailResult.next()) {
				employeeIds.append(detailResult.value("employee_id").toString());
			}
			bulletin.setEmployeeIds(employeeIds);
		}

		list.append(bulletin);
	}
	return list;
}


bool BulletinRepositorySQLite::updateActived(int id, bool checked) {
	QString query = "UPDATE bulletin SET is_active = :is_active WHERE id = :id;";

	QMap<QString, QVariant> params;
	params[":is_active"] = checked;
	params[":id"] = id;

	return db->executeCreate(query, params);
}