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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageEmployeeClass
{
public:
    QWidget *centralWidget;
    QWidget *header;
    QWidget *content;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ManageEmployeeClass)
    {
        if (ManageEmployeeClass->objectName().isEmpty())
            ManageEmployeeClass->setObjectName(QString::fromUtf8("ManageEmployeeClass"));
        ManageEmployeeClass->resize(795, 469);
        centralWidget = new QWidget(ManageEmployeeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        header = new QWidget(centralWidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(10, -10, 551, 61));
        content = new QWidget(centralWidget);
        content->setObjectName(QString::fromUtf8("content"));
        content->setGeometry(QRect(10, 40, 761, 351));
        content->setStyleSheet(QString::fromUtf8("width: 100%;\n"
"height: 100%;\n"
"margin: 50px;"));
        ManageEmployeeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ManageEmployeeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ManageEmployeeClass->setStatusBar(statusBar);

        retranslateUi(ManageEmployeeClass);

        QMetaObject::connectSlotsByName(ManageEmployeeClass);
    } // setupUi

    void retranslateUi(QMainWindow *ManageEmployeeClass)
    {
        ManageEmployeeClass->setWindowTitle(QCoreApplication::translate("ManageEmployeeClass", "ManageEmployee", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageEmployeeClass: public Ui_ManageEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEEMPLOYEE_H
