#pragma once
#include "IDatabaseManager.h"
#include "IDepartmentRepository.h"
#include "IEmployeeRepository.h"
#include "IAttendanceEventRepository.h"
class DatabaseManagerSQLServer : public IDatabaseManager
{
public:
    DatabaseManagerSQLServer();
    ~DatabaseManagerSQLServer();

    bool connectToDatabase() override;
    void closeDatabase() override;
    bool executeCreate(const QString& queryStr) override;
    bool executeCreate(const QString& queryStr, const QMap<QString, QVariant>& params) override;
    QSqlQuery executeQuery(const QString& queryStr) override;
    QSqlQuery executeQuery2(const QString& queryStr, const QMap<QString, QVariant>& params) override;

    IDepartmentRepository* getDepartmentRepository() override;
    IEmployeeRepository* getEmployeeRepository() override;
    IAttendanceEventRepository* getAttendanceEventRepository() override;

    bool excuteInitTable(QString pathDefault) override;
    void bankupData() override;
    void restoreData() override;

private:
    QSqlDatabase db;
    IDepartmentRepository* departmentRepository;
    IEmployeeRepository* employeeRepository;
    IAttendanceEventRepository* attendanceEventRepository;
};
