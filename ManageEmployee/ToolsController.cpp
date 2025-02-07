#include "ToolsController.h"
#include "DialogChangeDatabase.h"
#include "DatabaseManagerMYSQL.h"
#include "DatabaseManagerSQLite.h"
#include "DatabaseManagerSQLServer.h"
#include "Constant.h"
#include "DialogConfirm.h"
#include "DatabaseSingleton.h"
#include "DialogChangePassword.h"
#include "DialogSettings.h"
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

void ToolsController::onClickBackupData() {
	DialogConfirm* confirm = new DialogConfirm(tr("This will backup database that contains all IriTracker data.\nAre you sure you want to do this?"), nullptr);
	if (confirm->exec() == QDialog::Accepted) {
		db->bankupData();
	}
}
void ToolsController::onClickRestoreData() {
	DialogConfirm* confirm = new DialogConfirm(tr("This will use the backup database to overwrite all the existing IriTracker data.\nAre you sure you want to do this?"), nullptr);
	if (confirm->exec() == QDialog::Accepted) {
		db->restoreData();
	}
}
void ToolsController::onClickChangeDB() {
	DialogChangeDatabase* dialogChangeDB = new DialogChangeDatabase(tools);

	connect(dialogChangeDB, &DialogChangeDatabase::changeDB, this, &ToolsController::handleChangeDB);

	dialogChangeDB->exec();
}
void ToolsController::onClickChangePassword() {
	DialogChangePassword* dialogChangePassword = new DialogChangePassword(tools);

	dialogChangePassword->exec();
}
void ToolsController::onClickSettings() {
	DialogSettings* dialogSettings = new DialogSettings(tools);

	dialogSettings->exec();
}

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

	DatabaseSingleton::getInstance()->setDB(db);
}