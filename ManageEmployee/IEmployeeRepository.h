#pragma once
#include <QString>
#include <QList>
#include "EmployeeModel.h"
class IEmployeeRepository {
public:
	virtual ~IEmployeeRepository() {}
	virtual bool add(EmployeeModel employee) = 0;
	virtual bool update(EmployeeModel employee) = 0;
	virtual bool _delete(QString id) = 0;
	virtual QList<EmployeeModel> getAll() = 0;
	virtual EmployeeModel getById(QString id) = 0;
	virtual bool toggleEnabled(QString id, bool checked) = 0;
	virtual bool changeAvatar(QString path, QString id) = 0;
	virtual bool signInAdmin(QString pass) = 0;
	virtual bool signInStaff(QString id, QString pass) = 0;
	virtual QList<EmployeeModel> getByDepartment(QString department) = 0;
	virtual bool checkStatusIn(QString id) = 0;
	virtual bool updateStatus(QString status, QString id) = 0;
	virtual bool checkExistAdmin() = 0;
};