#pragma once

#include <QWidget>
#include "ui_ManageEmployee.h"
#include "DatabaseManager.h"
#include "DialogFormEmployee.h"

class ManageEmployee : public QWidget
{
	Q_OBJECT

public:
	ManageEmployee(QWidget *parent = nullptr);
	~ManageEmployee();

signals:
	void modeEdit();

public slots:
	void handleRenderTable();
	void handleClickAdd();
	void handleEdit();
	void handleDelete();
	void handleToggleEnabled(QString id, bool checked);

	void handleRowClicked(const QModelIndex& index);

private:
	Ui::ManageEmployeeClass ui;
	DatabaseManager db;
	DialogFormEmployee* df_employee;
	QMessageBox msgBox;
};
