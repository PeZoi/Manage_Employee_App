#pragma once
#include "BulletinModel.h"
#include <QString>
#include <QList>
class IBulletinRepository {
public:
	virtual ~IBulletinRepository() {}

	virtual bool add(BulletinModel bulletin) = 0;
	virtual bool update(BulletinModel bulletin) = 0;
	virtual bool updateActived(int id, bool checked) = 0;
	virtual bool _delete(int id) = 0;
	virtual QList<BulletinModel> getAll() = 0;
	virtual BulletinModel getById(int id) = 0;
	virtual QList<BulletinModel> getByCurrentDate() = 0;
	
};