#pragma once
#include <QObject>
#include "EmployeeCheckInOut.h"
#include "IDatabaseManager.h"

class EmployeeCheckInOutController : public QObject {
	Q_OBJECT

public:
	EmployeeCheckInOutController(EmployeeCheckInOut* view, IDatabaseManager*& _db, QObject* parent = nullptr);
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
	IDatabaseManager*& db;
	EmployeeCheckInOut* view;
};

