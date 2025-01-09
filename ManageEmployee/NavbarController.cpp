#include "NavbarController.h"
#include "IDatabaseManager.h"
#include "DialogFormLoginAdmin.h"
#include "ErrorLabel.h"
#include "IriTrackerSingleton.h"
#include <QSettings>

NavbarController::NavbarController(Navbar* view, IDatabaseManager*& _db, QObject* parent)
	: QObject(parent), navbarView(view), db(_db)
{
	connect(navbarView->getUi()->logout, SIGNAL(clicked()), this, SLOT(handleClickLogout()));
	connect(navbarView->getUi()->login, SIGNAL(clicked()), this, SLOT(handleClickLogin()));
	connect(navbarView->getUi()->copyright, SIGNAL(clicked()), this, SLOT(handleClickCopyright()));
	connect(navbarView->getUi()->mode, SIGNAL(clicked()), this, SLOT(handleClickMode()));
	connect(navbarView->getUi()->exit, SIGNAL(clicked()), this, SLOT(handleClickExit()));
	connect(navbarView->getUi()->back, SIGNAL(clicked()), this, SLOT(handleHiddenBack()));

	handleHiddenBack();
	navbarView->getUi()->login->show();
	navbarView->getUi()->logout->hide();
}

void NavbarController::handleClickLogout() {
	onLogoutSuccess();

}
void NavbarController::handleClickLogin() {
	DialogFormLoginAdmin* formLogin = new DialogFormLoginAdmin(nullptr);
	connect(formLogin, &DialogFormLoginAdmin::loginSuccessful, this, &NavbarController::handleSignInAdmin);

	formLogin->exec();
}
void NavbarController::handleClickCopyright() {
	msgBox.setText("Copyright");
	msgBox.exec();
}
void NavbarController::handleClickMode() {
	msgBox.setText("Mode");
	msgBox.exec();
}
void NavbarController::handleClickExit() {
	exit(0);
}

void NavbarController::onLoginSuccess() {
	emit loginSuccessful();
	navbarView->getUi()->login->hide();
	navbarView->getUi()->logout->show();
}

void NavbarController::onLogoutSuccess() {
	IriTrackerSingleton::isRunningStreamThreadCheckInOut = true;
	emit logoutSuccessful();
	navbarView->getUi()->login->show();
	navbarView->getUi()->logout->hide();
	navbarView->getUi()->back->hide();
}

void NavbarController::handleHiddenBack() {
	navbarView->getUi()->back->hide();
	emit back();
}
void NavbarController::handleShowBack() {
	navbarView->getUi()->back->show();
}

Navbar* NavbarController::getUi() {
	return navbarView;
}

void NavbarController::handleSignInAdmin(QString pass, DialogFormLoginAdmin* dialog) {
	
	db->connectToDatabase();
	if (db->getEmployeeRepository()->signInAdmin(pass)) {
		dialog->accept();
		if (IriTrackerSingleton::getInstance()->getStreamThreadCheckInOut()->isRunning()) {
			IriTrackerSingleton::isRunningStreamThreadCheckInOut = false;
			IriTrackerSingleton::getInstance()->getStreamThreadCheckInOut()->quit();
		}
		onLoginSuccess();
	}
	else {
		ErrorLabel* error = new ErrorLabel(tr("  Password was wrong.  "));
		error->showTemporary(dialog->getUi().verticalLayout, 3000);
		dialog->adjustSize();
	}
	db->closeDatabase();
}

void NavbarController::setEmployeeCheckInOutController(EmployeeCheckInOutController* _employeeCheckInOutController) {
	employeeCheckInOutController = _employeeCheckInOutController;
}