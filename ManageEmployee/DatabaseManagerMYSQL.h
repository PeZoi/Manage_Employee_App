#pragma once

#include "IDatabaseManager.h"
class DatabaseManagerMYSQL : public IDatabaseManager
{
public:
    DatabaseManagerMYSQL();
    ~DatabaseManagerMYSQL();

    bool connectToDatabase() override;
    void closeDatabase() override;
    bool executeCreate(const QString& queryStr) override;
    bool executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) override;
    QSqlQuery executeQuery(const QString& queryStr) override;
    QSqlQuery executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params) override;

    IDepartmentRepository* getDepartmentRepository() override;
    IEmployeeRepository* getEmployeeRepository() override;
    IAttendanceEventRepository* getAttendanceEventRepository() override;
    IExceptionRepository* getExceptionRepository() override;
    IBulletinRepository* getBulletinRepository() override;

    bool excuteInitTable(QString pathDefault) override;
    void bankupData() override;
    void restoreData() override;

private:
    QSqlDatabase db;
    IDepartmentRepository* departmentRepository;
    IEmployeeRepository* employeeRepository;
    IAttendanceEventRepository* attendanceEventRepository;
    IExceptionRepository* exceptionRepository;
    IBulletinRepository* bulletinRepository;
};

