#pragma once
#include <QList>
#include "DatabaseManager.h"
#include "DepartmentModel.h"

class DepartmentRepository : public QObject
{
	Q_OBJECT
public:
	DepartmentRepository();

	static bool add(DepartmentModel department);
	static bool update(DepartmentModel department);
	static bool _delete(QString name);
	static QList<DepartmentModel> getAll();
	static QList<DepartmentModel> getAllIgnoreOthers();
	static DepartmentModel getByName(QString name);
	
};