#pragma once
#include "IEmployeeRepository.h"
#include "IDatabaseManager.h"
#include "EmployeeModel.h"
class EmployeeRepositorySQLite : public IEmployeeRepository
{
public:
	EmployeeRepositorySQLite(IDatabaseManager* _db);

	bool add(EmployeeModel employee) override;
	bool update(EmployeeModel employee) override;
	bool _delete(QString id) override;
	QList<EmployeeModel> getAll() override;
	EmployeeModel getById(QString id) override;
	bool toggleEnabled(QString id, bool checked) override;
	bool changeAvatar(QString path, QString id) override;
	bool signInAdmin(QString pass) override;
	bool signInStaff(QString id, QString pass) override;
	QList<EmployeeModel> getByDepartment(QString department) override;
	bool checkStatusIn(QString id) override;
	bool updateStatus(QString status, QString id) override;
	bool checkExistAdmin() override;

private:
	IDatabaseManager* db;
};

