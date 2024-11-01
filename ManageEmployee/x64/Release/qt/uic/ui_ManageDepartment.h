/********************************************************************************
** Form generated from reading UI file 'ManageDepartment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEDEPARTMENT_H
#define UI_MANAGEDEPARTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageDepartmentClass
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *table;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QPushButton *edit;
    QPushButton *delete_2;

    void setupUi(QWidget *ManageDepartmentClass)
    {
        if (ManageDepartmentClass->objectName().isEmpty())
            ManageDepartmentClass->setObjectName(QString::fromUtf8("ManageDepartmentClass"));
        ManageDepartmentClass->resize(504, 337);
        ManageDepartmentClass->setStyleSheet(QString::fromUtf8("height: fit-content;"));
        label = new QLabel(ManageDepartmentClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 20, 371, 31));
        label->setStyleSheet(QString::fromUtf8("color: #f53e2d;\n"
"font-size: 28px"));
        verticalLayoutWidget = new QWidget(ManageDepartmentClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 70, 451, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        table = new QTableView(verticalLayoutWidget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setStyleSheet(QString::fromUtf8(""));

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


        retranslateUi(ManageDepartmentClass);

        QMetaObject::connectSlotsByName(ManageDepartmentClass);
    } // setupUi

    void retranslateUi(QWidget *ManageDepartmentClass)
    {
        ManageDepartmentClass->setWindowTitle(QCoreApplication::translate("ManageDepartmentClass", "ManageDepartment", nullptr));
        label->setText(QCoreApplication::translate("ManageDepartmentClass", "Ph\303\262ng Ban", nullptr));
        add->setText(QCoreApplication::translate("ManageDepartmentClass", "Th\303\252m", nullptr));
        edit->setText(QCoreApplication::translate("ManageDepartmentClass", "S\341\273\255a", nullptr));
        delete_2->setText(QCoreApplication::translate("ManageDepartmentClass", "Xo\303\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageDepartmentClass: public Ui_ManageDepartmentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEDEPARTMENT_H
