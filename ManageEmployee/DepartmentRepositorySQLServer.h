#pragma once
#include "IDepartmentRepository.h"
#include "IDatabaseManager.h"
#include "DepartmentModel.h"
class DepartmentRepositorySQLServer : public IDepartmentRepository
{
public:
	DepartmentRepositorySQLServer(IDatabaseManager* _db);

	bool add(DepartmentModel department) override;
	bool update(DepartmentModel department) override;
	bool _delete(QString name) override;
	QList<DepartmentModel> getAll() override;
	QList<DepartmentModel> getAllIgnoreOthers() override;
	DepartmentModel getByName(QString name) override;

private:
	IDatabaseManager* db;
};
