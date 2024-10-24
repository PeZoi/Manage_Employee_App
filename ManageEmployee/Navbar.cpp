#include "Navbar.h"
#include <QSettings>


Navbar::Navbar(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.logout, SIGNAL(clicked()), this, SLOT(handleClickLogout()));
	connect(ui.login, SIGNAL(clicked()), this, SLOT(handleClickLogin()));
	connect(ui.copyright, SIGNAL(clicked()), this, SLOT(handleClickCopyright()));
	connect(ui.mode, SIGNAL(clicked()), this, SLOT(handleClickMode()));
	connect(ui.exit, SIGNAL(clicked()), this, SLOT(handleClickExit()));
	connect(ui.back, SIGNAL(clicked()), this, SLOT(handleHiddenBack()));

	QSettings settings("Iritech", "Manage_Employee_App");
	bool isLoggedIn = settings.value("isLoggedIn", false).toBool();


	handleHiddenBack();
	if (isLoggedIn) {
		onLoginSuccess();
	}
	else {
		ui.login->show();
		ui.logout->hide();
	}
}

Navbar::~Navbar()
{}


void Navbar::handleClickLogout() {
	QSettings settings("Iritech", "Manage_Employee_App");
	settings.setValue("isLoggedIn", false);
	onLogoutSuccess();
	msgBox.setText("Logout");
	msgBox.exec();

}
void Navbar::handleClickLogin() {
	QSettings settings("Iritech", "Manage_Employee_App");
	settings.setValue("isLoggedIn", true);



	DialogFormLoginAdmin formLogin(this);
	connect(&formLogin, &DialogFormLoginAdmin::loginSuccessful, this, &Navbar::onLoginSuccess);

	formLogin.exec();

	emit loginSuccessful();
}
void Navbar::handleClickCopyright() {
	msgBox.setText("Copyright");
	msgBox.exec();
}
void Navbar::handleClickMode() {
	msgBox.setText("Mode");
	msgBox.exec();
}
void Navbar::handleClickExit() {
	exit(0);
}

void Navbar::onLoginSuccess() {
	ui.login->hide();
	ui.logout->show(); 
}

void Navbar::onLogoutSuccess() {
	emit logoutSuccessful();
	ui.login->show();
	ui.logout->hide();
}

void Navbar::handleHiddenBack() {
	ui.back->hide();
	emit back();
}
void Navbar::handleShowBack() {
	ui.back->show();
}