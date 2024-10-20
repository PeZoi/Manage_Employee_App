#include "SignUpAdmin.h"
#include <QSettings>


SignUpAdmin::SignUpAdmin(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.btn_signup, &QPushButton::clicked, this, &SignUpAdmin::handleSignUp);
}

SignUpAdmin::~SignUpAdmin()
{
}

void SignUpAdmin::handleSignUp() {
    QString email = ui.email->text();
    QString pass = ui.password->text();
    QString passCon = ui.password_confirm->text();

    if (email.trimmed().isEmpty() || pass.trimmed().isEmpty() || passCon.trimmed().isEmpty()) {
        msgBox.setText("Vui lòng nhập đủ các trường");
        msgBox.exec();
        return;
    }

    if (pass != passCon) {
        msgBox.setText("Mật khẩu không trùng khớp");
        msgBox.exec();
        return;
    }

    db.connectToDatabase();

    QString insertEmployeeQuery = "INSERT INTO employee (id, first_name, last_name, password, department, date_of_birth, start_date_of_work, is_enabled, avatar, role, email, phone_number, address) "
        "VALUES (:id, :first_name, :last_name, :password, :department, :date_of_birth, :start_date_of_work, :is_enabled, :avatar, :role, :email, :phone_number, :address);";

    QMap<QString, QVariant> params;
    params[":id"] = "1"; // Giả sử bạn có logic để đảm bảo ID này là duy nhất
    params[":password"] = pass;
    params[":is_enabled"] = true;
    params[":role"] = "ADMIN";
    params[":email"] = email;

    if (!db.executeCreate(insertEmployeeQuery, params)) {
        msgBox.setText("Đăng ký thất bại");
        msgBox.exec();
        return;
    }

    QSettings settings("Iritech", "Manage_Employee_App");
    settings.setValue("isLoggedIn", true);

    db.closeDatabase();

    this->hide();
    me.show();
}
