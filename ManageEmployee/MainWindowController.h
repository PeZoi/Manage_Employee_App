#pragma once
#include <QObject>
#include "ManageDepartmentController.h"
#include "ManageEmployeeController.h"
#include "EmployeeCheckInOutController.h"
#include "ManageAttendanceEventsController.h"
#include "NavbarController.h"
#include "MainWindow.h"
#include "IDatabaseManager.h"
class MainWindowController : public QObject {
    Q_OBJECT

public:
    MainWindowController(MainWindow* view, IDatabaseManager* _db, QObject* parent = nullptr);

public slots:
    void handleLogout();
    void handleLogin();
    void handleBack();

    void handleHiddenMenu();
    void handleShowMenu();

    void handleHiddenManageDepartment();
    void handleShowManageDepartment();

    void handleHiddenManageEmployee();
    void handleShowManageEmployee();

    void handleHiddenCheckInOut();
    void handleShowCheckInOut();

    void handleHiddenManageEvents();
    void handleShowManageEnvents();

    MainWindow* getMainWindowView();

private:
    MainWindow* mainWindowView;
    ManageDepartmentController* mdController;
    ManageEmployeeController* meController;
    EmployeeCheckInOutController* ecioController;
    ManageAttendanceEventsController* maeController;

    IDatabaseManager* db;
};

