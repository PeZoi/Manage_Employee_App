#include "DialogFormLoginAdmin.h"

DialogFormLoginAdmin::DialogFormLoginAdmin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.login, SIGNAL(clicked()), this, SLOT(handleLoginAdmin()));
	
}

DialogFormLoginAdmin::~DialogFormLoginAdmin()
{}

void DialogFormLoginAdmin::handleLoginAdmin() {
	QString pass = ui.password->text();

	if (pass.trimmed().isEmpty()) {
		msgBox.setText("Vui lòng nhập đủ các trường");
		msgBox.exec();
		return;
	}

	QString queryString = "SELECT password FROM employee WHERE role = 'ADMIN'";
	QSqlQuery query;

    if (query.exec(queryString)) {
        if (query.next()) {
            QString storedPassword = query.value(0).toString();

            // So sánh mật khẩu
            if (pass == storedPassword) {
                emit loginSuccessful();
                this->accept();
            }
            else {
                msgBox.setText("Sai mật khẩu");
                msgBox.exec();
            }
        }
    }
    else {
        qDebug() << "Lỗi truy vấn: " << query.lastError().text();
        msgBox.setText("Lỗi truy vấn");
        msgBox.exec();
    }
}