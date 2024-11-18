#pragma once

#include "ui_DialogFormDepartment.h"
#include "DepartmentModel.h"
#include <QMessageBox>

class DialogFormDepartment : public QDialog
{
	Q_OBJECT

public:
	DialogFormDepartment(QWidget *parent = nullptr);
	~DialogFormDepartment();
	bool isEditMode_department = false;
	
	Ui::DialogFormDepartmentClass* getUi();

signals:
	void submit(DepartmentModel department, bool isEditMode, DialogFormDepartment* departmentView);

public slots:
	void handleSubmit();
	void setName(const QString& name);
	void setDescription(const QString& description);
	void setMode(bool _isEditMode);

private:
	Ui::DialogFormDepartmentClass* ui;
	QMessageBox msgBox;

};
