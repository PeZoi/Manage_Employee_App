#include "SignUpAdmin.h"
#include "MainWindow.h"
#include "MainWindowController.h"
#include "SignUpAdminController.h"
#include "IDatabaseManager.h"
#include "DatabaseManagerSQLite.h"
#include "DatabaseManagerMYSQL.h"
#include "DatabaseManagerSQLServer.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QString pathIni = "D:/IriTech/Code/ManageEmployee/database/config.ini";
	QFile configFile(pathIni);
	QSettings settings(pathIni, QSettings::IniFormat);
	
	IDatabaseManager* db;

	// Xử lý hiện để chọn sql
	/*if (settings.value("database/type").toString() == "MYSQL") {
		settings.setValue("database/type", "MYSQL");
		db = new DatabaseManagerMYSQL();
	}
	else if (settings.value("database/type").toString() == "SQLITE") {
		settings.setValue("database/type", "SQLITE");
		db = new DatabaseManagerSQLite();
	}
	else {
		settings.setValue("database/type", "SQLServer");
		db = new DatabaseManagerSQLServer();
	}*/

	db = new DatabaseManagerSQLServer();

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
