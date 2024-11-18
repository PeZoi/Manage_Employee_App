#pragma once
#include <QObject>
#include "DialogFormEmployee.h"
#include "ManageEmployee.h"
#include "IDatabaseManager.h"

class ManageEmployeeController : public QObject {
	Q_OBJECT

public:
	ManageEmployeeController(ManageEmployee* view, IDatabaseManager* _db, QObject* parent = nullptr);
	QString employeeSelected;

public slots:
	void handleRenderTable();
	void onClickAdd();
	void onClickEdit();
	void onClickDelete();
	void handleToggleEnabled(QString id, bool checked);
	void handleUploadAvatar(DialogFormEmployee* employeeForm, bool isEditMode_employee);
	void renderDepartments(Ui::DialogFormEmployeeClass employeeForm);

	void submitEmployee(const EmployeeModel& employee, bool isEditMode, DialogFormEmployee* employeeView);

	void handleRowClicked(const QModelIndex& index);

	ManageEmployee* getMeView();


private:
	IDatabaseManager* db;
	ManageEmployee* meView;
};

