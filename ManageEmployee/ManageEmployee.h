#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ManageEmployee.h"

class ManageEmployee : public QMainWindow
{
    Q_OBJECT

public:
    ManageEmployee(QWidget *parent = nullptr);
    ~ManageEmployee();

private:
    Ui::ManageEmployeeClass ui;
};
