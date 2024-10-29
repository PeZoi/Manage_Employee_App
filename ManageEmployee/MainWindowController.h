#pragma once
#include <QObject>
#include "ManageDepartmentController.h"
#include "MainWindow.h"
class MainWindowController : public QObject {
    Q_OBJECT

public:
    MainWindowController(MainWindow* view, QObject* parent = nullptr);

public slots:
    void handleHiddenMenu();
    void handleShowMenu();

    void handleHiddenManageDepartment();
    void handleShowManageDepartment();

    void handleHiddenManageEmployee();
    void handleShowManageEmployee();

    MainWindow* getMainWindowView();

private:
    MainWindow* mainWindowView;
    ManageDepartmentController* mdController;
};

