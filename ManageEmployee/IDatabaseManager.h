#pragma once
#include <QString>
#include <QMap>
#include <QVariant>
#include <QSqlQuery>
#include "IDepartmentRepository.h"
#include "IEmployeeRepository.h"
#include "IAttendanceEventRepository.h"
#include "IExceptionRepository.h"

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
    virtual IExceptionRepository* getExceptionRepository() = 0;

    virtual bool excuteInitTable(QString pathDefault) = 0;
    virtual void bankupData() = 0;
    virtual void restoreData() = 0;
};

