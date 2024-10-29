#pragma once

#include <QDialog>
#include "ui_DialogFormDepartment.h"
#include "DatabaseManager.h"
#include "DepartmentModel.h"

class DialogFormDepartment : public QDialog
{
	Q_OBJECT

public:
	DialogFormDepartment(QWidget *parent = nullptr);
	~DialogFormDepartment();
	bool isEditMode_department = false;

signals:
	void submit(DepartmentModel department, bool isEditMode);

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
