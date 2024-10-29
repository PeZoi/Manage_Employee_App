/********************************************************************************
** Form generated from reading UI file 'DialogFormDepartment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORMDEPARTMENT_H
#define UI_DIALOGFORMDEPARTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormDepartmentClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *description;
    QLabel *label_4;
    QLineEdit *name;
    QPushButton *submit;

    void setupUi(QDialog *DialogFormDepartmentClass)
    {
        if (DialogFormDepartmentClass->objectName().isEmpty())
            DialogFormDepartmentClass->setObjectName(QString::fromUtf8("DialogFormDepartmentClass"));
        DialogFormDepartmentClass->resize(321, 243);
        formLayoutWidget = new QWidget(DialogFormDepartmentClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 281, 155));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        description = new QLineEdit(formLayoutWidget);
        description->setObjectName(QString::fromUtf8("description"));
        description->setStyleSheet(QString::fromUtf8("height: 100px;"));

        formLayout->setWidget(2, QFormLayout::FieldRole, description);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        name = new QLineEdit(formLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(1, QFormLayout::FieldRole, name);

        submit = new QPushButton(DialogFormDepartmentClass);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(210, 190, 80, 25));

        retranslateUi(DialogFormDepartmentClass);

        QMetaObject::connectSlotsByName(DialogFormDepartmentClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormDepartmentClass)
    {
        DialogFormDepartmentClass->setWindowTitle(QCoreApplication::translate("DialogFormDepartmentClass", "DialogFormDepartment", nullptr));
        label->setText(QCoreApplication::translate("DialogFormDepartmentClass", "M\303\264 t\341\272\243", nullptr));
        label_4->setText(QCoreApplication::translate("DialogFormDepartmentClass", "T\303\252n", nullptr));
        submit->setText(QCoreApplication::translate("DialogFormDepartmentClass", "\304\220\341\273\223ng \303\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormDepartmentClass: public Ui_DialogFormDepartmentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMDEPARTMENT_H
