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
	void loginSuccessful();

public:
	DialogFormLoginAdmin(QWidget *parent = nullptr);
	~DialogFormLoginAdmin();

private slots:
	void handleLoginAdmin();

private:
	Ui::DialogFormLoginAdminClass ui;
	QMessageBox msgBox;
	DatabaseManager db;
};
