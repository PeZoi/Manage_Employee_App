#pragma once
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>
#include <QVariant>
#include <QDebug>
#include <QList>
#include <QString>

#include "AttendaceEventModel.h"

#include "IAttendanceEventRepository.h"
#include "IEmployeeRepository.h"
#include "IDepartmentRepository.h"

class IDatabaseManager {
public:
    virtual ~IDatabaseManager() {}

    virtual bool connectToDatabase() = 0;
    virtual void closeDatabase() = 0;
    virtual bool executeCreate(const QString& queryStr) = 0;
    virtual bool executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) = 0;
    virtual QSqlQuery executeQuery(const QString& queryStr) = 0;
    virtual QSqlQuery executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params) = 0;

    virtual IDepartmentRepository* getDepartmentRepository() = 0;
    virtual IEmployeeRepository* getEmployeeRepository() = 0;
    virtual IAttendanceEventRepository* getAttendanceEventRepository() = 0;
};
