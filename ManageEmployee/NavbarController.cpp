#include "NavbarController.h"
#include "EmployeeRepository.h"
#include "ErrorLabel.h"
#include <QSettings>

NavbarController::NavbarController(QObject* parent)
	: QObject(parent)
{}

NavbarController::NavbarController(Navbar* view, QObject* parent)
	: QObject(parent), navbarView(view)
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
	msgBox.setText("Logout");
	msgBox.exec();

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
	DatabaseManager::connectToDatabase();
	if (EmployeeRepository::signInAdmin(pass)) {
		dialog->accept();
		onLoginSuccess();
	}
	else {
		ErrorLabel* error = new ErrorLabel("  Password was wrong.  ");
		error->showTemporary(dialog->getUi().verticalLayout, 3000);
		dialog->adjustSize();
	}
	DatabaseManager::closeDatabase();
}

void NavbarController::setEmployeeCheckInOutController(EmployeeCheckInOutController* _employeeCheckInOutController) {
	employeeCheckInOutController = _employeeCheckInOutController;
}