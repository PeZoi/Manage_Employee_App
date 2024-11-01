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

public slots:
	void setupRealTimeClock();
	void updateDateTime();
	void loadEmployee();

private:
	EmployeeCheckInOut* view;
};

