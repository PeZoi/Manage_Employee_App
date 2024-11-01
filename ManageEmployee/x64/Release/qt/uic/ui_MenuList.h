/********************************************************************************
** Form generated from reading UI file 'MenuList.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENULIST_H
#define UI_MENULIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuListClass
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *department;
    QPushButton *employee;
    QPushButton *event;
    QPushButton *exception;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *report;
    QPushButton *notification;
    QPushButton *tools;

    void setupUi(QWidget *MenuListClass)
    {
        if (MenuListClass->objectName().isEmpty())
            MenuListClass->setObjectName(QString::fromUtf8("MenuListClass"));
        MenuListClass->resize(789, 400);
        label = new QLabel(MenuListClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 321, 41));
        label->setStyleSheet(QString::fromUtf8("color: #fb5533;\n"
"font-size: 24px;"));
        horizontalLayoutWidget = new QWidget(MenuListClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 90, 631, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        department = new QPushButton(horizontalLayoutWidget);
        department->setObjectName(QString::fromUtf8("department"));
        department->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout->addWidget(department);

        employee = new QPushButton(horizontalLayoutWidget);
        employee->setObjectName(QString::fromUtf8("employee"));
        employee->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout->addWidget(employee);

        event = new QPushButton(horizontalLayoutWidget);
        event->setObjectName(QString::fromUtf8("event"));
        event->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout->addWidget(event);

        exception = new QPushButton(horizontalLayoutWidget);
        exception->setObjectName(QString::fromUtf8("exception"));
        exception->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout->addWidget(exception);

        horizontalLayoutWidget_2 = new QWidget(MenuListClass);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(80, 220, 511, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        report = new QPushButton(horizontalLayoutWidget_2);
        report->setObjectName(QString::fromUtf8("report"));
        report->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout_2->addWidget(report);

        notification = new QPushButton(horizontalLayoutWidget_2);
        notification->setObjectName(QString::fromUtf8("notification"));
        notification->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout_2->addWidget(notification);

        tools = new QPushButton(horizontalLayoutWidget_2);
        tools->setObjectName(QString::fromUtf8("tools"));
        tools->setStyleSheet(QString::fromUtf8("height: 50px;\n"
"margin: 0 15px"));

        horizontalLayout_2->addWidget(tools);


        retranslateUi(MenuListClass);

        QMetaObject::connectSlotsByName(MenuListClass);
    } // setupUi

    void retranslateUi(QWidget *MenuListClass)
    {
        MenuListClass->setWindowTitle(QCoreApplication::translate("MenuListClass", "MenuList", nullptr));
        label->setText(QCoreApplication::translate("MenuListClass", "Ph\303\262ng Qu\341\272\243n Tr\341\273\213", nullptr));
        department->setText(QCoreApplication::translate("MenuListClass", "Ph\303\262ng Ban", nullptr));
        employee->setText(QCoreApplication::translate("MenuListClass", "Nh\303\242n Vi\303\252n", nullptr));
        event->setText(QCoreApplication::translate("MenuListClass", "S\341\273\261 Ki\341\273\207n Ki\341\273\203m Di\341\273\207n", nullptr));
        exception->setText(QCoreApplication::translate("MenuListClass", "Ngo\341\272\241i L\341\273\207", nullptr));
        report->setText(QCoreApplication::translate("MenuListClass", "B\303\241o C\303\241o", nullptr));
        notification->setText(QCoreApplication::translate("MenuListClass", "B\341\272\243ng Th\303\264ng B\303\241o", nullptr));
        tools->setText(QCoreApplication::translate("MenuListClass", "C\303\264ng C\341\273\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuListClass: public Ui_MenuListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENULIST_H
