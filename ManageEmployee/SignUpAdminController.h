#pragma once
#include <QObject>
#include "SignUpAdmin.h"
#include "EmployeeModel.h"
#include "IDatabaseManager.h"
#include "MainWindowController.h"

class SignUpAdminController : public QObject {
	Q_OBJECT
public:
	SignUpAdminController(SignUpAdmin* view, IDatabaseManager*& _db, MainWindowController *mainWindowController,  QObject* parent = nullptr);
	void handleSubmit();
	SignUpAdmin* getSignUpView();

private:
	SignUpAdmin* signUpView;
	IDatabaseManager*& db;
	MainWindowController* mainWindowController;
};

