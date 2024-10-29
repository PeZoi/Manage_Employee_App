#pragma once
#include <QObject>
#include "ManageDepartment.h"
class ManageDepartmentController : public QObject {
	Q_OBJECT

public:
	ManageDepartmentController(ManageDepartment* view, QObject* parent = nullptr);
	QString departmentSelected;

public slots:
	void handleRenderTable();
	void onClickAdd();
	void onClickEdit();
	void onClickDelete();

	void submitDepartment(const DepartmentModel& department, bool isEditMode);

	void handleRowClicked(const QModelIndex& index);

	ManageDepartment* getMdView();
	

private:
	ManageDepartment* mdView;
	DatabaseManager db;
	
};

