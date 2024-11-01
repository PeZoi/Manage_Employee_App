#pragma once
#include <QObject>
#include "SignUpAdmin.h"
#include "EmployeeModel.h"

class SignUpAdminController : public QObject {
	Q_OBJECT
public:
	SignUpAdminController(SignUpAdmin* view, QObject* parent = nullptr);
	void handleSubmit();
	SignUpAdmin* getSignUpView();

private:
	SignUpAdmin* signUpView;
};

