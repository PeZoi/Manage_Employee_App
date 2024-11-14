#include "SignUpAdmin.h"
#include "DatabaseManager.h"
#include "MainWindow.h"
#include "MainWindowController.h"
#include "SignUpAdminController.h"
#include "IDatabaseManager.h"
#include "DatabaseManagerSQLite.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDir>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QString pathIni = "D:/IriTech/Code/ManageEmployee/database/config.ini";
	QFile configFile(pathIni);
	QSettings settings(pathIni, QSettings::IniFormat);
	
	IDatabaseManager* db;

	// Xử lý hiện để chọn sql
	if (settings.value("database/type").toString() == "MYSQL") {
		settings.setValue("database/type", "MYSQL");
		db = new DatabaseManagerSQLite();
	}
	else {
		settings.setValue("database/type", "SQLITE");
		db = new DatabaseManagerSQLite();
	}

	SignUpAdmin* signUpUI = new SignUpAdmin(nullptr);
	SignUpAdminController* signUpController = new SignUpAdminController(signUpUI, db, nullptr);

	MainWindow* mainWindowUI = new MainWindow(nullptr);
	MainWindowController* mainWindowController = new MainWindowController(mainWindowUI, db, nullptr);



	//DatabaseManager db;

	//db.connectToDatabase();

	//if (!db.checkExistAdmin()) {
	//    signUpController->getSignUpView()->show();
	//}
	//else {
	//    mainWindowController->getMainWindowView()->show();
	//}

	//// Đóng kết nối cơ sở dữ liệu sau khi ứng dụng thoát
	//db.closeDatabase();

	 //Giải phóng bộ nhớ
	delete mainWindowController;
	delete mainWindowUI;

	delete signUpController;
	delete signUpUI;

	

	/*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setPort(3306);
	db.setDatabaseName("mysql_iritech");
	db.setUserName("root");
	db.setPassword("root");

	if (db.open()) {
		qDebug() << "Kết nối thành công";
	}
	else {
		qDebug() << "Kết nối thất bại: " << db.lastError().text();
	}*/

	int result = a.exec();
	return result;
}
