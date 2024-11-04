#pragma once
#include <QObject>
#include "EmployeeCheckInOut.h"
#include "DepartmentRepository.h"
#include "EmployeeRepository.h"

class EmployeeCheckInOutController : public QObject {
	Q_OBJECT

public:
	EmployeeCheckInOutController(EmployeeCheckInOut* view, QObject* parent = nullptr);
	EmployeeCheckInOut* getView();

	QString employeeSelected;

public slots:
	void setupRealTimeClock();
	void updateDateTime();

	void onClickShowAll();

	void handleSelectEmployee(const QModelIndex& index);
	void handleSelectEmployeeByCombo(const QString& name);
	void loadEmployee();

	void handleSubmitForPassword();

private:
	EmployeeCheckInOut* view;
};

