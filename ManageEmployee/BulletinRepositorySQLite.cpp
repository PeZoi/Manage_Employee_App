#include "BulletinRepositorySQLite.h"
#include "Constant.h"
#include <QSqlQuery>

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

    return true;
}
bool BulletinRepositorySQLite::_delete(int id) {

    return true;
}
QList<BulletinModel> BulletinRepositorySQLite::getAll() {
    QList<BulletinModel> list;

    return list;
}
BulletinModel BulletinRepositorySQLite::getById(int id) {
    return BulletinModel();
}
QList<BulletinModel> BulletinRepositorySQLite::getByCurrentDate() {
    QList<BulletinModel> list;

    return list;
}

bool BulletinRepositorySQLite::updateActived(int id, bool checked) {


    return false;
}