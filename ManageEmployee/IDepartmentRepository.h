#pragma once
#include "DepartmentModel.h"
#include <QString>
#include <QList>
class IDepartmentRepository {
public:
	virtual ~IDepartmentRepository() {}

	virtual bool add(DepartmentModel department) = 0;
	virtual bool update(DepartmentModel department) = 0;
	virtual bool _delete(QString name) = 0;
	virtual QList<DepartmentModel> getAll() = 0;
	virtual QList<DepartmentModel> getAllIgnoreOthers() = 0;
	virtual DepartmentModel getByName(QString name) = 0;
};