#pragma once

#include <QtWidgets/QMainWindow>
#include <QSettings>
#include <QDebug>
#include "ui_ManageEmployee.h"
#include "Navbar.h"
#include "MenuList.h"
#include "DialogFormLoginAdmin.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleHidenMenu();
    void handleShowMenu();

private:
    Ui::ManageEmployeeClass ui;
    DialogFormLoginAdmin formLogin;
    QSettings settings;
    MenuList* menu;
    Navbar* navbar;
};
