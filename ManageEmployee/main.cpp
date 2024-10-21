#include "SignUpAdmin.h"
#include "DatabaseManager.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignUpAdmin signUpUI;
    MainWindow mainWindowUI;
    DatabaseManager db;

    db.connectToDatabase();

    if (!db.checkExistAdmin()) {
        signUpUI.show();
    }
    else {
        mainWindowUI.show();
    }

    db.closeDatabase();

    
    return a.exec();
}
