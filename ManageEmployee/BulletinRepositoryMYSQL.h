#pragma once
#include "IBulletinRepository.h"
#include "IDatabaseManager.h"
class BulletinRepositoryMYSQL : public IBulletinRepository
{
public:
	BulletinRepositoryMYSQL(IDatabaseManager* _db);

	bool add(BulletinModel bulletin) override;
	bool update(BulletinModel bulletin) override;
	bool _delete(int id) override;
	QList<BulletinModel> getAll() override;
	BulletinModel getById(int id) override;
	QList<BulletinModel> getByCurrentDate() override;
	bool updateActived(int id, bool checked) override;

private:
	IDatabaseManager* db;
};
