#include "ToolsController.h"
#include "DialogChangeDatabase.h"
#include "DatabaseManagerMYSQL.h"
#include "DatabaseManagerSQLite.h"
#include "DatabaseManagerSQLServer.h"
#include "Constant.h"
#include <QDebug>
#include <QPushButton>

ToolsController::ToolsController(Tools* view, IDatabaseManager*& _db, QObject* parent)
	: QObject(parent), tools(view), db(_db)
{
	connect(view->getUi()->backup_data, &QPushButton::clicked, this, &ToolsController::onClickBackupData);
	connect(view->getUi()->restore_data, &QPushButton::clicked, this, &ToolsController::onClickRestoreData);
	connect(view->getUi()->change_db, &QPushButton::clicked, this, &ToolsController::onClickChangeDB);
	connect(view->getUi()->change_password, &QPushButton::clicked, this, &ToolsController::onClickChangePassword);
	connect(view->getUi()->settings, &QPushButton::clicked, this, &ToolsController::onClickSettings);
}

Tools* ToolsController::getView() {
	return tools;
}

void ToolsController::onClickBackupData(){
}
void ToolsController::onClickRestoreData(){}
void ToolsController::onClickChangeDB(){
	DialogChangeDatabase* dialogChangeDB = new DialogChangeDatabase(tools);

	connect(dialogChangeDB, &DialogChangeDatabase::changeDB, this, &ToolsController::handleChangeDB);

	dialogChangeDB->exec();
}
void ToolsController::onClickChangePassword(){}
void ToolsController::onClickSettings(){}

void ToolsController::handleChangeDB(QString type) {
	if (db != nullptr) {
		delete db;
		db = nullptr;
	}
	if (type == Constant::SQLITE) {
		db = new DatabaseManagerSQLite();
	}
	else if (type == Constant::MYSQL) {
		db = new DatabaseManagerMYSQL();
	}
	else {
		db = new DatabaseManagerSQLServer();
	}
}