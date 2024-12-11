#pragma once
#include "ExceptionModel.h"
class IExceptionRepository {
public:
	virtual ~IExceptionRepository() {}

	virtual bool add(ExceptionModel exception) = 0;
	virtual bool update(ExceptionModel exception) = 0;
	virtual bool _delete(int id) = 0;
	virtual QList<ExceptionModel> getAll() = 0;
	virtual ExceptionModel getById(int id) = 0;
	virtual ExceptionModel getByName(QString name) = 0;
	virtual bool checkExistByName(QString name) = 0;
};