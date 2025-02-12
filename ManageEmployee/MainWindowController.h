#pragma once
#include <QObject>
#include "ManageDepartmentController.h"
#include "ManageEmployeeController.h"
#include "ManageAttendanceEventsController.h"
#include "ManageExceptionController.h"
#include "ManageBulletinController.h"
#include "ToolsController.h"
#include "MainWindow.h"
class MainWindowController : public QObject {
    Q_OBJECT

public:
    MainWindowController(MainWindow* view, IDatabaseManager*& _db, QObject* parent = nullptr);

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

    void handleHiddenManageException();
    void handleShowManageException();

    void handleHiddenManageBulletin();
    void handleShowManageBulletin();

    void handleHiddenTools();
    void handleShowTools();

    MainWindow* getMainWindowView();
    ManageDepartmentController* getMdController() const {
        return mdController;
    }

    ManageEmployeeController* getMeController() const {
        return meController;
    }

    EmployeeCheckInOutController* getEcioController() const {
        return ecioController;
    }

    ManageAttendanceEventsController* getMaeController() const {
        return maeController;
    }

    ManageExceptionController* getMexController() const {
        return mexController;
    }

    ManageBulletinController* getMbController() const {
        return mbController;
    }

    ToolsController* getToolsController() const {
        return toolsController;
    }

private:
    MainWindow* mainWindowView;
    ManageDepartmentController* mdController;
    ManageEmployeeController* meController;
    EmployeeCheckInOutController* ecioController;
    ManageAttendanceEventsController* maeController;
    ManageExceptionController* mexController;
    ManageBulletinController* mbController;
    ToolsController* toolsController;

    IDatabaseManager*& db;
};

