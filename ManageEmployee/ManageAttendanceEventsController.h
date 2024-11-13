#pragma once
#include <QObject>
#include "ManageAttendanceEvents.h"
#include "DepartmentRepository.h"
#include "DialogFormAttendanceEvents.h"
#include "EmployeeRepository.h"
class ManageAttendanceEventsController : public QObject {
	Q_OBJECT

public:
	ManageAttendanceEventsController(ManageAttendanceEvents* view, QObject* parent = nullptr);
	void loadEmployee();

	ManageAttendanceEvents* getView();

	QString employeeSelected;
	AttendanceEventModel attendanceEventSelected;
	QString filter = "This week";

public slots:
	void onClickAdd();
	void onClickEdit();
	void onClickDelete();
	
	void handleCheckout();
	void handleSelectEmployee(const QModelIndex& index);
	void handleRenderTable(QString filter = "This week");
	void handleSubmit(QString _employeeSelected, bool isEditMode, DialogFormAttendanceEvents* dialog);
	void handleRowClicked(const QModelIndex& index);
	void handleFilterRange(const QString& value);
	QList<AttendanceEventModel> filterEvents(const QList<AttendanceEventModel>& eventList, const QString& filter);

private:
	ManageAttendanceEvents* view;
};

