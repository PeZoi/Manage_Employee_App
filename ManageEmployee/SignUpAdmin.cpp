#include "SignUpAdmin.h"
#include <QSettings>
#include <QLinearGradient>
#include <QPalette>


SignUpAdmin::SignUpAdmin(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::SignUpAdminClass)
{
	ui->setupUi(this);	

    QLinearGradient gradient(0, 0, 0, this->height());
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor("#87A8D2"));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    ui->password_2->setEchoMode(QLineEdit::Password);
    ui->password_confirm_2->setEchoMode(QLineEdit::Password);
}

SignUpAdmin::~SignUpAdmin()
{
}

Ui::SignUpAdminClass* SignUpAdmin::getUi() {
    return ui;
}