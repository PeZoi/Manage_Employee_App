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
#include "IriTrackerSingleton.h"
#include "AudioUtils.h"
#include "LanguagesUtils.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
#include <QImageReader>
#include <QThread>
#include <QObject>
void getDevice() {
	IriTracker* iriTracker = IriTrackerSingleton::getIriTrackerGetDevice();
	QThread* threadGetDevice = IriTrackerSingleton::getGetDeviceThread();
	iriTracker->moveToThread(threadGetDevice);
	QObject::connect(threadGetDevice, &QThread::started, iriTracker, &IriTracker::get_device);
	threadGetDevice->start();
}

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon("D:/IriTech/Code/ManageEmployee/icon/IriTech.ico"));

	// GET DEVICE
	getDevice();

	// INIT AUDIO
	AudioUtils::getInstance()->initAudio();

	

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

	DatabaseSingleton::getInstance()->setDB(db);

	SignUpAdmin* signUpUI = new SignUpAdmin(nullptr);
	SignUpAdminController* signUpController = new SignUpAdminController(signUpUI, db, nullptr);

	MainWindow* mainWindowUI = new MainWindow(db, nullptr);
	MainWindowController* mainWindowController = new MainWindowController(mainWindowUI, db, nullptr);

	// INIT TRANSLATOR
	LanguagesUtils::getInstance()->setAppDefault(&a, mainWindowController);

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
