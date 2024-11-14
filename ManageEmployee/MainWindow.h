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
#include "NavbarController.h"
#include "IDatabaseManager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(IDatabaseManager* _db, QWidget* parent = nullptr);
    ~MainWindow();

    DialogFormLoginAdmin& getFormLogin();
    MenuList* getMenu();
    NavbarController* getNavbarController();
    Ui::MainWindowClass* getUi() { return ui; };

private:
    Ui::MainWindowClass* ui;
    DialogFormLoginAdmin formLogin;
    QSettings settings;
    MenuList* menu;
    NavbarController* navbarController;

    IDatabaseManager* db;
};
