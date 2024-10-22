#pragma once

#include <QDialog>
#include "ui_DialogFormDepartment.h"
#include "DatabaseManager.h"

class DialogFormDepartment : public QDialog
{
	Q_OBJECT

public:
	DialogFormDepartment(QWidget *parent = nullptr);
	~DialogFormDepartment();

signals:
	void excuteDBSuccessful();

public slots:
	void handleSubmit();
	void setName(const QString& name);
	void setDescription(const QString& description);
	void setMode(bool _isEditMode);

private:
	Ui::DialogFormDepartmentClass ui;
	DatabaseManager db;
	QMessageBox msgBox;

	bool checkNameDepartment(const QString& name);
};
