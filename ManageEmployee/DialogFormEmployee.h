#pragma once

#include <QDialog>
#include "ui_DialogFormEmployee.h"
#include "DatabaseManager.h"

class DialogFormEmployee : public QDialog
{
	Q_OBJECT

public:
	DialogFormEmployee(QWidget *parent = nullptr);
	~DialogFormEmployee();

signals:
	void excuteDBSuccessful();
	void editModeChanged();

public slots:
	void handleSubmit();
	void setMode(bool _isEditMode);
	void setValue(QSqlQuery result);
	bool validateExists(const QString& id, const QString& email);
	void handleUploadAvatar();

	void renderDepartments();

private:
	Ui::DialogFormEmployeeClass ui;
	DatabaseManager db;
	QMessageBox msgBox;
};
