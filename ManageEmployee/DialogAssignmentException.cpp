#include "DialogAssignmentException.h"
#include "DatabaseSingleton.h"
#include "DepartmentModel.h"
#include "EmployeeModel.h"
#include <QDate>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDebug>

DialogAssignmentException::DialogAssignmentException(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::DialogAssignmentExceptionClass())
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Form Assignment Exception"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui->from->setDisplayFormat("dd/MM/yyyy");
	ui->to->setDisplayFormat("dd/MM/yyyy");

	ui->from->setDate(QDate::currentDate());
	ui->to->setDate(QDate::currentDate());

	ui->all_days->setChecked(true);
	ui->all->setChecked(true);

	setDisabledEmployee(false);
	setDisabledDepartment(false);

	connect(ui->deparment, &QRadioButton::toggled, this, &DialogAssignmentException::setDisabledDepartment);
	connect(ui->selection, &QRadioButton::toggled, this, &DialogAssignmentException::setDisabledEmployee);
	connect(ui->filter_deparment, &QLineEdit::textChanged, this, &DialogAssignmentException::filterDepartment);
	connect(ui->filter_employee, &QLineEdit::textChanged, this, &DialogAssignmentException::filterEmployee);

	connect(ui->all, &QRadioButton::toggled, this, [this](bool checked) {
		if (checked) {
			setDisabledEmployee(false);
			setDisabledDepartment(false);
		}
		});
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	departments = DatabaseSingleton::getInstance()->getDB()->getDepartmentRepository()->getAll();
	employees = DatabaseSingleton::getInstance()->getDB()->getEmployeeRepository()->getAll();

	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
	renderExceptions();
	renderDepartments(departments);
	renderEmployees(employees);
}

DialogAssignmentException::~DialogAssignmentException()
{
	delete ui;
}

void DialogAssignmentException::renderExceptions() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	QList<ExceptionModel> exceptionList = DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->getAll();

	ui->table->setRowCount(exceptionList.size());

	for (int i = 0; i < exceptionList.size(); i++) {
		ui->table->setItem(i, 0, new QTableWidgetItem(exceptionList.at(i).getName()));
		ui->table->setItem(i, 1, new QTableWidgetItem(exceptionList.at(i).getPaidHours()));
		ui->table->setItem(i, 2, new QTableWidgetItem(QString::number(exceptionList.at(i).getPaidCoefficient(), 'f', 2)));
		ui->table->setItem(i, 3, new QTableWidgetItem(QString::number(exceptionList.at(i).getWorkCoefficient(), 'f', 2)));
	}

	ui->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < exceptionList.size(); ++i) {
		if (i % 2 == 0) { // Dòng chẵn
			for (int j = 0; j < ui->table->columnCount(); ++j) {
				QTableWidgetItem* item = ui->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237)); // Màu xám nhạt
				}
			}
		}
	}
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}
void DialogAssignmentException::renderDepartments(QList<DepartmentModel> departments) {
	QLayout* currentLayout = ui->department_widget->layout();
	if (currentLayout != nullptr) {
		QLayoutItem* item;
		while ((item = currentLayout->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete currentLayout; 
	}

	QVBoxLayout* layout1 = new QVBoxLayout();

	for (const DepartmentModel& department : departments) {
		QCheckBox* checkBox = new QCheckBox(department.getName(), this);
		layout1->addWidget(checkBox);
	}

	ui->department_widget->setLayout(layout1);
}
void DialogAssignmentException::renderEmployees(QList<EmployeeModel> employees) {
	QLayout* currentLayout = ui->employee_widget->layout();
	if (currentLayout != nullptr) {
		QLayoutItem* item;
		while ((item = currentLayout->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete currentLayout;
	}

	QVBoxLayout* layout1 = new QVBoxLayout();

	for (const EmployeeModel& employee : employees) {
		QString fullname = employee.getFirstName() + " " + employee.getLastName();
		QString displayName = QString("%1 (%2)").arg(fullname).arg(employee.getId());
		QCheckBox* checkBox = new QCheckBox(displayName, this);
		layout1->addWidget(checkBox);
	}

	ui->employee_widget->setLayout(layout1);
}

void DialogAssignmentException::setDisabledEmployee(bool check) {
	ui->filter_employee->setDisabled(!check); // vì check lấy isChecked của radio nên hơi ngược
	ui->employee_widget->setDisabled(!check);
}
void DialogAssignmentException::setDisabledDepartment(bool check) {
	ui->filter_deparment->setDisabled(!check);
	ui->department_widget->setDisabled(!check);
}

void DialogAssignmentException::filterDepartment(const QString& name){
	QList<DepartmentModel> filteredDepartments;
	for (const DepartmentModel& department : departments) {
		if (department.getName().contains(name, Qt::CaseInsensitive)) {
			filteredDepartments.append(department);  
		}
	}

	renderDepartments(filteredDepartments);
}
void DialogAssignmentException::filterEmployee(const QString& name){
	QList<EmployeeModel> filteredEmployees;
	for (const EmployeeModel& employee : employees) {
		QString fullname = employee.getFirstName() + " " + employee.getLastName();
		QString displayName = QString("%1 (%2)").arg(fullname).arg(employee.getId());
		if (displayName.contains(name, Qt::CaseInsensitive)) {
			filteredEmployees.append(employee);
		}
	}

	renderEmployees(filteredEmployees);
}