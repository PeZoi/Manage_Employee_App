#pragma once

#include <QDialog>
#include "ui_DialogFormBulletin.h"
#include "DepartmentModel.h"
#include "EmployeeModel.h"
#include "BulletinModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogFormBulletinClass; };
QT_END_NAMESPACE

class DialogFormBulletin : public QDialog
{
	Q_OBJECT

public:
	DialogFormBulletin(QWidget *parent = nullptr);
	~DialogFormBulletin();

	void renderDepartments(QList<DepartmentModel> departments);
	void renderEmployees(QList<EmployeeModel> employees);

	void setDisabledEmployee(bool check);
	void setDisabledDepartment(bool check);

	void filterEmployee(const QString& name);
	
	Ui::DialogFormBulletinClass* getUi();

	bool isEditMode = false;
	int idSelected = 0;

signals:
	void submit(BulletinModel bulletin, bool isEditMode, DialogFormBulletin* dialog);

public slots:
	void onClickCancel();
	void handleSubmit();
	void setMode(bool _isEditMode);
	void setValue(BulletinModel bulletin);

private:
	Ui::DialogFormBulletinClass *ui;
	QList<DepartmentModel> departments;
	QList<EmployeeModel> employees;
};
