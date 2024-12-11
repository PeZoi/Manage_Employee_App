#pragma once
#include "IExceptionRepository.h"
#include "IDatabaseManager.h"
class ExceptionRepositoryMYSQL : public IExceptionRepository
{
public:
	ExceptionRepositoryMYSQL(IDatabaseManager* _db);

	bool add(ExceptionModel exception) override;
	bool update(ExceptionModel exception) override;
	bool _delete(int id) override;
	QList<ExceptionModel> getAll() override;
	ExceptionModel getById(int id) override;
	ExceptionModel getByName(QString name)override;
	bool checkExistByName(QString name) override;

private:
	IDatabaseManager* db;
};

