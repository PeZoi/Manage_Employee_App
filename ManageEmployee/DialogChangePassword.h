#pragma once

#include <QDialog>
#include "ui_DialogChangePassword.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogChangePasswordClass; };
QT_END_NAMESPACE

class DialogChangePassword : public QDialog
{
	Q_OBJECT

public:
	DialogChangePassword(QWidget *parent = nullptr);
	~DialogChangePassword();

	

public slots:
	void handleChangePassword();

private:
	Ui::DialogChangePasswordClass *ui;
};
