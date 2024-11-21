#pragma once
#include <QObject>
#include "SignUpAdmin.h"
#include "EmployeeModel.h"
#include "IDatabaseManager.h"

class SignUpAdminController : public QObject {
	Q_OBJECT
public:
	SignUpAdminController(SignUpAdmin* view, IDatabaseManager*& _db, QObject* parent = nullptr);
	void handleSubmit();
	SignUpAdmin* getSignUpView();

private:
	SignUpAdmin* signUpView;
	IDatabaseManager*& db;
};

