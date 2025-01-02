#include "DialogChangePassword.h"
#include "DatabaseSingleton.h"
#include "ErrorLabel.h"
#include <QPushButton>
#include <QString>
#include <QDebug>

DialogChangePassword::DialogChangePassword(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DialogChangePasswordClass())
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Change Password"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	connect(ui->btn_yes, &QPushButton::clicked, this, &DialogChangePassword::handleChangePassword);
	connect(ui->btn_no, &QPushButton::clicked, this, [this]() {reject(); });
}

DialogChangePassword::~DialogChangePassword()
{
	delete ui;
}

void DialogChangePassword::handleChangePassword() {
	QString oldPassword = ui->old_password->text();
	QString newPassword = ui->new_password->text();
	QString retypeNewPassword = ui->retype_new_password->text();

	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	bool isCorrectPassAdmin = DatabaseSingleton::getInstance()->getDB()->getEmployeeRepository()->signInAdmin(oldPassword);

	if (oldPassword == "" || newPassword == "" || retypeNewPassword == "") {
		ErrorLabel* error = new ErrorLabel("  Please enter complete information.");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	if (!isCorrectPassAdmin) {
		ErrorLabel* error = new ErrorLabel("  Password was wrong");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	if (oldPassword == newPassword) {
		ErrorLabel* error = new ErrorLabel("  Old password and new password are the same");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	if (newPassword != retypeNewPassword) {
		ErrorLabel* error = new ErrorLabel("  Retyped new password does not match the new password");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	if (newPassword.length() < 4) {
		ErrorLabel* error = new ErrorLabel("  Password must be at least 4 characters long");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	if (!DatabaseSingleton::getInstance()->getDB()->getEmployeeRepository()->changePasswordAdmin(newPassword)) {
		ErrorLabel* error = new ErrorLabel("  Change password failed!");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
	this->accept();

}