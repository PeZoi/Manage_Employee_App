#include "SignUpAdmin.h"
#include "MainWindow.h"
#include "MainWindowController.h"
#include "SignUpAdminController.h"
#include "IDatabaseManager.h"
#include "DatabaseManagerSQLite.h"
#include "DatabaseManagerMYSQL.h"
#include "DatabaseManagerSQLServer.h"
#include "Constant.h"
#include "IriTracker.h"
#include "DatabaseSingleton.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
#include <QImageReader>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	IriTracker::get_divice();

	QString pathIni = Constant::PATH_CONFIG;
	QFile configFile(pathIni);
	QSettings settings(pathIni, QSettings::IniFormat);
	
	IDatabaseManager* db;

	// Xử lý hiện để chọn sql
	if (settings.value("database/type").toString() == Constant::MYSQL) {
		db = new DatabaseManagerMYSQL();
	}
	else if (settings.value("database/type").toString() == Constant::SQLITE) {
		db = new DatabaseManagerSQLite();
	}
	else {
		db = new DatabaseManagerSQLServer();
	}

	DatabaseSingleton::getInstance()->setDB(db);

	SignUpAdmin* signUpUI = new SignUpAdmin(nullptr);
	SignUpAdminController* signUpController = new SignUpAdminController(signUpUI, db, nullptr);

	MainWindow* mainWindowUI = new MainWindow(db, nullptr);
	MainWindowController* mainWindowController = new MainWindowController(mainWindowUI, db, nullptr);

	db->connectToDatabase();
	if (!db->getEmployeeRepository()->checkExistAdmin()) {
	    signUpController->getSignUpView()->show();
	}
	else {
	    mainWindowController->getMainWindowView()->show();
	}
	int result = a.exec();
	db->closeDatabase();

	 //Giải phóng bộ nhớ
	delete mainWindowController;
	delete mainWindowUI;

	delete signUpController;
	delete signUpUI;

	delete db;



	return result;
}
