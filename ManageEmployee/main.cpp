#include "SignUpAdmin.h"
#include "DatabaseManager.h"
#include "ManageEmployee.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignUpAdmin signUpUI;
    ManageEmployee manageEmployeeUI;
    DatabaseManager db;

    db.connectToDatabase();

    if (!db.checkExistAdmin()) {
        signUpUI.show();
    }
    else {
        manageEmployeeUI.show();
    }

    db.closeDatabase();

    
    return a.exec();
}
