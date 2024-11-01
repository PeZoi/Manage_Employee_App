#include "SignUpAdmin.h"
#include "DatabaseManager.h"
#include "MainWindow.h"
#include "MainWindowController.h"
#include "SignUpAdminController.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    SignUpAdmin* signUpUI = new SignUpAdmin(nullptr);
    SignUpAdminController* signUpController = new SignUpAdminController(signUpUI, nullptr);

    MainWindow* mainWindowUI = new MainWindow(nullptr);
    MainWindowController* mainWindowController = new MainWindowController(mainWindowUI, nullptr);
    DatabaseManager db;

    db.connectToDatabase();

    if (!db.checkExistAdmin()) {
        signUpController->getSignUpView()->show();
    }
    else {
        mainWindowController->getMainWindowView()->show();
    }

    // Đóng kết nối cơ sở dữ liệu sau khi ứng dụng thoát
    int result = a.exec();
    db.closeDatabase();

    // Giải phóng bộ nhớ
    delete mainWindowController;
    delete mainWindowUI;

    delete signUpController;
    delete signUpUI;

    return result;
}
