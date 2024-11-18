#pragma once
#include <QObject>
#include "DialogFormDepartment.h"
#include "ManageDepartment.h"
#include "IDatabaseManager.h"
class ManageDepartmentController : public QObject {
	Q_OBJECT

public:
	ManageDepartmentController(ManageDepartment* view, IDatabaseManager* _db, QObject* parent = nullptr);
	QString departmentSelected;

public slots:
	void handleRenderTable();
	void onClickAdd();
	void onClickEdit();
	void onClickDelete();

	void submitDepartment(const DepartmentModel& department, bool isEditMode, DialogFormDepartment* departmentView);

	void handleRowClicked(const QModelIndex& index);

	ManageDepartment* getMdView();
	

private:
	IDatabaseManager* db;
	ManageDepartment* mdView;
};

