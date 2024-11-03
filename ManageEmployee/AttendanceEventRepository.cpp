#include "AttendanceEventRepository.h"
#include <QList>

AttendanceEventRepository::AttendanceEventRepository() {
}

bool AttendanceEventRepository::add(AttendanceEventModel attendanceEvent) {
    QString query = "INSERT INTO attendance_event (type_event, date_event, time_event, exception, session, employee_id) "
        "VALUES (:type_event, :date_event, :time_event, :exception, :session, :employee_id);";

    QMap<QString, QVariant> params;
    params[":type_event"] = attendanceEvent.getTypeEvent();
    params[":date_event"] = attendanceEvent.getDateEvent();
    params[":time_event"] = attendanceEvent.getTime();
    params[":exception"] = attendanceEvent.getException();
    params[":session"] = attendanceEvent.getSession();
    params[":employee_id"] = attendanceEvent.getEmployeeId();
    
    return DatabaseManager::executeCreate(query, params);
}

bool AttendanceEventRepository::update(AttendanceEventModel attendanceEvent) {
    DatabaseManager::connectToDatabase();
    QString query = "UPDATE attendance_event SET type_event = :type_event, date_event = :date_event, "
        "time_event = :time_event, exception = :exception, session = :session, employee_id = :employee_id "
        "WHERE id = :id;";

    QMap<QString, QVariant> params;
    params[":type_event"] = attendanceEvent.getTypeEvent();
    params[":date_event"] = attendanceEvent.getDateEvent();
    params[":time_event"] = attendanceEvent.getTime();
    params[":exception"] = attendanceEvent.getException();
    params[":session"] = attendanceEvent.getSession();
    params[":employee_id"] = attendanceEvent.getEmployeeId();
    params[":id"] = attendanceEvent.getId();

    return DatabaseManager::executeCreate(query, params);
}

bool AttendanceEventRepository::_delete(int id) {
    DatabaseManager::connectToDatabase();
    QString query = "DELETE FROM attendance_event WHERE id = :id;";

    QMap<QString, QVariant> params;
    params[":id"] = id;

    return DatabaseManager::executeCreate(query, params);
}

QList<AttendanceEventModel> AttendanceEventRepository::getAll() {
    QString query = "SELECT * FROM attendance_event;";
    QSqlQuery sqlQuery(query);
    QList<AttendanceEventModel> events;

    while (sqlQuery.next()) {
        AttendanceEventModel event;
        event.setId(sqlQuery.value("id").toInt());
        event.setTypeEvent(sqlQuery.value("type_event").toString());
        event.setDateEvent(sqlQuery.value("date_event").toString());
        event.setTime(sqlQuery.value("time_event").toString());
        event.setException(sqlQuery.value("exception").toInt());
        event.setSession(sqlQuery.value("session").toInt());
        event.setEmployeeId(sqlQuery.value("employee_id").toString());
        events.append(event);
    }

    return events;
}

AttendanceEventModel AttendanceEventRepository::getById(int id) {
    return AttendanceEventModel();
}

QList<AttendanceEventModel> AttendanceEventRepository::getByEmployeeId(QString employeeId) {
    QString query = "SELECT * FROM attendance_event WHERE employee_id = :employee_id";

    QMap<QString, QVariant> params;
    params[":employee_id"] = employeeId;

    QSqlQuery sqlQuery = DatabaseManager::executeQuery2(query, params);
    QList<AttendanceEventModel> events;

    if (!sqlQuery.isActive()) {
        qDebug() << "Query failed:" << sqlQuery.lastError().text();
        return events;
    }

    while (sqlQuery.next()) {
        AttendanceEventModel event;
        event.setId(sqlQuery.value("id").toInt());
        event.setTypeEvent(sqlQuery.value("type_event").toString());
        event.setDateEvent(sqlQuery.value("date_event").toString());
        event.setTime(sqlQuery.value("time_event").toString());
        event.setException(sqlQuery.value("exception").toInt());
        event.setSession(sqlQuery.value("session").toInt());
        event.setEmployeeId(sqlQuery.value("employee_id").toString());
        events.append(event);
    }

    return events;
}
QList<AttendanceEventModel> AttendanceEventRepository::getBySession(int session) {
    QString query = "SELECT * FROM attendance_event WHERE session = :session";

    QMap<QString, QVariant> params;
    params[":session"] = session;

    QSqlQuery sqlQuery = DatabaseManager::executeQuery2(query, params);
    QList<AttendanceEventModel> events;

    if (!sqlQuery.isActive()) {
        qDebug() << "Query failed:" << sqlQuery.lastError().text();
        return events;
    }

    while (sqlQuery.next()) {
        AttendanceEventModel event;
        event.setId(sqlQuery.value("id").toInt());
        event.setTypeEvent(sqlQuery.value("type_event").toString());
        event.setDateEvent(sqlQuery.value("date_event").toString());
        event.setTime(sqlQuery.value("time_event").toString());
        event.setException(sqlQuery.value("exception").toInt());
        event.setSession(sqlQuery.value("session").toInt());
        event.setEmployeeId(sqlQuery.value("employee_id").toString());
        events.append(event);
    }

    return events;
}

AttendanceEventModel AttendanceEventRepository::getByDateAndTime(QString date, QString time) {
    QString query = "SELECT * FROM attendance_event WHERE date_event = :date_event AND time_event = :time_event";

    QMap<QString, QVariant> params;
    params[":date_event"] = date;
    params[":time_event"] = time;

    QSqlQuery sqlQuery = DatabaseManager::executeQuery2(query, params);

    if (!sqlQuery.isActive()) {
        qDebug() << "Query failed:" << sqlQuery.lastError().text();
        return AttendanceEventModel();
    }

    while (sqlQuery.next()) {
        AttendanceEventModel event;
        event.setId(sqlQuery.value("id").toInt());
        event.setTypeEvent(sqlQuery.value("type_event").toString());
        event.setDateEvent(sqlQuery.value("date_event").toString());
        event.setTime(sqlQuery.value("time_event").toString());
        event.setException(sqlQuery.value("exception").toInt());
        event.setSession(sqlQuery.value("session").toInt());
        event.setEmployeeId(sqlQuery.value("employee_id").toString());

        return event;
    }

    return AttendanceEventModel();
}

bool AttendanceEventRepository::deleteBySession(int session) {
    QString query = "DELETE FROM attendance_event WHERE session = :session;";

    QMap<QString, QVariant> params;
    params[":session"] = session;

    return DatabaseManager::executeCreate(query, params);
}