#pragma once
#include <QObject>
#include "IDatabaseManager.h"
#include "Tools.h"
class ToolsController : public QObject {
	Q_OBJECT

public:
	ToolsController(Tools* view, IDatabaseManager*& _db, QObject* parent = nullptr);

	Tools* getView();
	
	void onClickBackupData();
	void onClickRestoreData();
	void onClickChangeDB();
	void onClickChangePassword();
	void onClickSettings();

	void handleChangeDB(QString type);

private:
	IDatabaseManager*& db;
	Tools* tools;
};

