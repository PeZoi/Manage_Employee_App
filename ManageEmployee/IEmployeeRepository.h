#pragma once
#include <QList>
#include <QVariant>
#include "EmployeeModel.h"
#include "IDatabaseManager.h"
class IEmployeeRepository {
public:
	virtual ~IEmployeeRepository() {}
	virtual bool add(EmployeeModel employee);
	virtual bool update(EmployeeModel employee);
	virtual bool _delete(QString id);
	virtual QList<EmployeeModel> getAll();
	virtual EmployeeModel getById(QString id);
	virtual bool toggleEnabled(QString id, bool checked);
	virtual bool changeAvatar(QString path, QString id);
	virtual bool signInAdmin(QString pass);
	virtual bool signInStaff(QString id, QString pass);
	virtual QList<EmployeeModel> getByDepartment(QString department);
	virtual bool checkStatusIn(QString id);
	virtual bool updateStatus(QString status, QString id);
	virtual bool checkExistAdmin();
};