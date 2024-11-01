#pragma once
#include <QList>
#include "DatabaseManager.h"
#include "EmployeeModel.h"
class EmployeeRepository : public QObject
{
	Q_OBJECT
public:
	EmployeeRepository();

	static bool add(EmployeeModel employee);
	static bool update(EmployeeModel employee);
	static bool _delete(QString id);
	static QList<EmployeeModel> getAll();
	static EmployeeModel getById(QString id);
	static bool toggleEnabled(QString id, bool checked);
	static bool changeAvatar(QString path, QString id);
	static bool signInAdmin(QString pass);
	static QList<EmployeeModel> getByDepartment(QString department);
};

