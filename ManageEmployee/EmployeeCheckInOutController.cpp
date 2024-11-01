#include "EmployeeCheckInOutController.h"
#include "CustomFilterProxyModel.h"
#include <QStandardItemModel>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QSortFilterProxyModel>

EmployeeCheckInOutController::EmployeeCheckInOutController(EmployeeCheckInOut* view, QObject* parent)
	: QObject(parent), view(view)
{
	loadEmployee();
	setupRealTimeClock();

	
}

EmployeeCheckInOut* EmployeeCheckInOutController::getView() {
	return view;
}

void EmployeeCheckInOutController::setupRealTimeClock() {
	QTimer* timer = new QTimer(this);

	connect(timer, &QTimer::timeout, this, &EmployeeCheckInOutController::updateDateTime);
	timer->start(1000);

	updateDateTime();
}

void EmployeeCheckInOutController::updateDateTime() {
	QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

	QString timeString = QTime::currentTime().toString("hh:mm:ss AP");
	QString dateString = QDate::currentDate().toString("dddd, MMMM d, yyyy");

	view->getUi()->timeLabel->setText(timeString);
	view->getUi()->dateLabel->setText(dateString);
}

void EmployeeCheckInOutController::loadEmployee() {
	QStandardItemModel* model = new QStandardItemModel(this);
	view->getUi()->companyTreeView->header()->setVisible(false);

	QList<DepartmentModel> departmentList = DepartmentRepository::getAll();

	for (int i = 0; i < departmentList.size(); i++) {
		QList<EmployeeModel> employeeList = EmployeeRepository::getByDepartment(departmentList.at(i).getName());

		QString departmentDisplay = QString("%1 (%2)").arg(departmentList.at(i).getName()).arg(employeeList.size());
		QStandardItem* departmentItem = new QStandardItem(departmentDisplay);
		departmentItem->setFlags(departmentItem->flags() & ~Qt::ItemIsEditable);

		for (int j = 0; j < employeeList.size(); j++) {
			QString id = employeeList.at(j).getId();
			QString fullname = employeeList.at(j).getFirstName() + " " + employeeList.at(j).getLastName();
			QString employeeDisplay = QString("%1 (%2)").arg(fullname).arg(id);

			QStandardItem* employeeItem = new QStandardItem(employeeDisplay);
			if (employeeList.at(j).getIsEnabled()) {
				employeeItem->setIcon(QIcon("D:\\IriTechCode\\ManageEmployee\\icon\\avatar.png"));
			}
			else {
				employeeItem->setIcon(QIcon("D:\\IriTechCode\\ManageEmployee\\icon\\ban.png"));
			}
			employeeItem->setFlags(employeeItem->flags() & ~Qt::ItemIsEditable);

			departmentItem->appendRow(employeeItem);
		}

		model->appendRow(departmentItem);
	}

	CustomFilterProxyModel* filterModel = new CustomFilterProxyModel(this);
	filterModel->setSourceModel(model);
	filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
	filterModel->setFilterKeyColumn(0);

	view->getUi()->companyTreeView->setModel(filterModel);
	view->getUi()->companyTreeView->expandAll();

	connect(view->getUi()->searchLineEdit, &QLineEdit::textChanged, filterModel, &CustomFilterProxyModel::setFilterFixedString);
}

