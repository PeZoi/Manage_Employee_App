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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageEmployeeClass
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *table;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QPushButton *edit;
    QPushButton *delete_2;

    void setupUi(QWidget *ManageEmployeeClass)
    {
        if (ManageEmployeeClass->objectName().isEmpty())
            ManageEmployeeClass->setObjectName(QString::fromUtf8("ManageEmployeeClass"));
        ManageEmployeeClass->resize(867, 400);
        label = new QLabel(ManageEmployeeClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 371, 31));
        label->setStyleSheet(QString::fromUtf8("color: #f53e2d;\n"
"font-size: 28px"));
        verticalLayoutWidget = new QWidget(ManageEmployeeClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 70, 671, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        table = new QTableWidget(verticalLayoutWidget);
        table->setObjectName(QString::fromUtf8("table"));

        verticalLayout->addWidget(table);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add = new QPushButton(verticalLayoutWidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setStyleSheet(QString::fromUtf8("height: 15px;"));

        horizontalLayout->addWidget(add);

        edit = new QPushButton(verticalLayoutWidget);
        edit->setObjectName(QString::fromUtf8("edit"));
        edit->setStyleSheet(QString::fromUtf8("height: 15px;"));

        horizontalLayout->addWidget(edit);

        delete_2 = new QPushButton(verticalLayoutWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setStyleSheet(QString::fromUtf8("height: 15px;"));

        horizontalLayout->addWidget(delete_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ManageEmployeeClass);

        QMetaObject::connectSlotsByName(ManageEmployeeClass);
    } // setupUi

    void retranslateUi(QWidget *ManageEmployeeClass)
    {
        ManageEmployeeClass->setWindowTitle(QCoreApplication::translate("ManageEmployeeClass", "ManageEmployee", nullptr));
        label->setText(QCoreApplication::translate("ManageEmployeeClass", "Nh\303\242n Vi\303\252n", nullptr));
        add->setText(QCoreApplication::translate("ManageEmployeeClass", "Th\303\252m", nullptr));
        edit->setText(QCoreApplication::translate("ManageEmployeeClass", "S\341\273\255a", nullptr));
        delete_2->setText(QCoreApplication::translate("ManageEmployeeClass", "Xo\303\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageEmployeeClass: public Ui_ManageEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEEMPLOYEE_H
