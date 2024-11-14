#pragma once
#include <QList>
#include <QVariant>
#include "DepartmentModel.h"
#include "IDatabaseManager.h"
class IDepartmentRepository {
public:
	virtual ~IDepartmentRepository() {}

	virtual bool add(DepartmentModel department);
	virtual bool update(DepartmentModel department);
	virtual bool _delete(QString name);
	virtual QList<DepartmentModel> getAll();
	virtual QList<DepartmentModel> getAllIgnoreOthers();
	virtual DepartmentModel getByName(QString name);
};