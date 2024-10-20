/********************************************************************************
** Form generated from reading UI file 'ManageEmployee.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEEMPLOYEE_H
#define UI_MANAGEEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageEmployeeClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ManageEmployeeClass)
    {
        if (ManageEmployeeClass->objectName().isEmpty())
            ManageEmployeeClass->setObjectName(QString::fromUtf8("ManageEmployeeClass"));
        ManageEmployeeClass->resize(600, 400);
        centralWidget = new QWidget(ManageEmployeeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(200, 80, 104, 85));
        ManageEmployeeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ManageEmployeeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        ManageEmployeeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ManageEmployeeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ManageEmployeeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ManageEmployeeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ManageEmployeeClass->setStatusBar(statusBar);

        retranslateUi(ManageEmployeeClass);

        QMetaObject::connectSlotsByName(ManageEmployeeClass);
    } // setupUi

    void retranslateUi(QMainWindow *ManageEmployeeClass)
    {
        ManageEmployeeClass->setWindowTitle(QCoreApplication::translate("ManageEmployeeClass", "ManageEmployee", nullptr));
        textEdit->setHtml(QCoreApplication::translate("ManageEmployeeClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">M\303\240n h\303\254nh ch\303\255nh</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageEmployeeClass: public Ui_ManageEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEEMPLOYEE_H
