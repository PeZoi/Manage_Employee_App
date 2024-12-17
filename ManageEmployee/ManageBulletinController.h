#pragma once

#include "BulletinModel.h"
#include "ManageBulletin.h"
#include "DialogFormBulletin.h"
#include <QObject>

class ManageBulletinController : public QObject
{
	Q_OBJECT

public slots:
	void handleRenderTable();
	void handleToggleActive(int id, bool checked);
	void onClickAdd();
	void onClickEdit();
	void onClickDelete();

	void submit(const BulletinModel& bulletin, bool isEditMode, DialogFormBulletin* dialog);

	void handleRowClicked(const QModelIndex& index);

	ManageBulletin* getMbView();

public:
	ManageBulletinController(ManageBulletin* view, QObject* parent);
	~ManageBulletinController();
	BulletinModel bulletinSelected;

private:
	ManageBulletin* mbView;
};
