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
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    DialogFormLoginAdmin& getFormLogin();
    MenuList* getMenu();
    Navbar* getNavbar();
    Ui::MainWindowClass* getUi() { return ui; };

private:
    Ui::MainWindowClass* ui;
    DialogFormLoginAdmin formLogin;
    QSettings settings;
    MenuList* menu;
    Navbar* navbar;
};
