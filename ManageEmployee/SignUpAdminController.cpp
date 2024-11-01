#include "SignUpAdminController.h"
#include "EmployeeRepository.h"
#include "MainWindowController.h"
#include "ErrorLabel.h"

SignUpAdminController::SignUpAdminController(SignUpAdmin* view, QObject* parent)
	: QObject(parent), signUpView(view)
{
	connect(signUpView->getUi()->btn_signup_2, &QPushButton::clicked, this, &SignUpAdminController::handleSubmit);
	connect(signUpView->getUi()->cancelButton, &QPushButton::clicked, this, [this]() {exit(0); });
}


void SignUpAdminController::handleSubmit() {
	QString email = signUpView->getUi()->email_2->text();
	QString pass = signUpView->getUi()->password_2->text();
	QString passCon = signUpView->getUi()->password_confirm_2->text();

	if (email.trimmed().isEmpty() || pass.trimmed().isEmpty() || passCon.trimmed().isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  Please enter complete information.  ");
		error->showTemporary(signUpView->getUi()->verticalLayout, 3000);
		
		return;
	}

	if (pass.length() < 4) {
		ErrorLabel* error = new ErrorLabel("   Password must be at least 4 characters long.  ");
		error->showTemporary(signUpView->getUi()->verticalLayout, 3000);
		return;
	}

	if (pass != passCon) {
		ErrorLabel* error = new ErrorLabel("  Passwords do not match.  ");
		error->showTemporary(signUpView->getUi()->verticalLayout, 3000);
		return;
	}

	QRegularExpression emailRegex("^[\\w\\.]+@[\\w\\.]+\\.[a-z]{2,3}$");
	if (!emailRegex.match(email).hasMatch()) {
		ErrorLabel* error = new ErrorLabel("  Email address is invalid. ");
		error->showTemporary(signUpView->getUi()->verticalLayout, 3000);
		return;
	}

	DatabaseManager::connectToDatabase();

	EmployeeModel admin = EmployeeModel();
	admin.setId("admin");
	admin.setPassword(pass);
	admin.setIsEnabled(true);
	admin.setRole("ADMIN");
	admin.setEmail(email);

	if (EmployeeRepository::add(admin)) {
		QSettings settings("Iritech", "Manage_Employee_App");
		settings.setValue("isLoggedIn", true);
	}

	DatabaseManager::closeDatabase();

	signUpView->hide();
	
	MainWindow* mainWindowUI = new MainWindow(nullptr);
	MainWindowController* mainWindowController = new MainWindowController(mainWindowUI, nullptr);

	mainWindowController->getMainWindowView()->show();
}

SignUpAdmin* SignUpAdminController::getSignUpView() {
	return signUpView;
}