#pragma once

#include <QWidget>
#include "ui_ManageDepartment.h"
#include "DatabaseManager.h"
#include "DialogFormDepartment.h"

class ManageDepartment : public QWidget
{
	Q_OBJECT

public:
	ManageDepartment(QWidget *parent = nullptr);
	~ManageDepartment();

signals:
	void modeEdit();
	

public slots:
	void handleRenderTable();
	void handleClickAdd();
	void handleEdit();
	void handleDelete();

	QSqlQuery getAllDepartment();

	void handleRowClicked(const QModelIndex& index);

private:
	Ui::ManageDepartmentClass ui;
	DatabaseManager db;
	DialogFormDepartment* df_department;
	QMessageBox msgBox;
};
