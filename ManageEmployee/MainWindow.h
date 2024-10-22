#pragma once

#include <QtWidgets/QMainWindow>
#include <QSettings>
#include <QDebug>
#include "ui_MainWindow.h"
#include "Navbar.h"
#include "MenuList.h"
#include "DialogFormLoginAdmin.h"
#include "ManageDepartment.h"
#include "ManageEmployee.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleHiddenMenu();
    void handleShowMenu();

    void handleHiddenManageDepartment();
    void handleShowManageDepartment();

    void handleHiddenManageEmployee();
    void handleShowManageEmployee();

private:
    Ui::MainWindowClass ui;
    DialogFormLoginAdmin formLogin;
    QSettings settings;
    MenuList* menu;
    Navbar* navbar;
    ManageDepartment* md;
    ManageEmployee* me;
};
