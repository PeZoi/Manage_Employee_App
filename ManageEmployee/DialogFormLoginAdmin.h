#pragma once

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "ui_DialogFormLoginAdmin.h"
#include "DatabaseManager.h"

class DialogFormLoginAdmin : public QDialog
{
	Q_OBJECT

signals:
	void loginSuccessful(QString pass, DialogFormLoginAdmin* dialog);

public:
	DialogFormLoginAdmin(QWidget *parent = nullptr);
	~DialogFormLoginAdmin();
	Ui::DialogFormLoginAdminClass getUi();

private slots:
	void handleLoginAdmin();

private:
	Ui::DialogFormLoginAdminClass ui;
	QMessageBox msgBox;
	DatabaseManager db;
};
