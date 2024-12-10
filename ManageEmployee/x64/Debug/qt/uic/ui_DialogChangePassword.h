/********************************************************************************
** Form generated from reading UI file 'DialogChangePassword.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHANGEPASSWORD_H
#define UI_DIALOGCHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogChangePasswordClass
{
public:
    QLabel *label;
    QLineEdit *old_password;
    QLineEdit *new_password;
    QLabel *label_2;
    QLineEdit *retype_new_password;
    QLabel *label_3;
    QPushButton *btn_no;
    QPushButton *btn_yes;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *DialogChangePasswordClass)
    {
        if (DialogChangePasswordClass->objectName().isEmpty())
            DialogChangePasswordClass->setObjectName(QString::fromUtf8("DialogChangePasswordClass"));
        DialogChangePasswordClass->resize(400, 197);
        label = new QLabel(DialogChangePasswordClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 71, 31));
        old_password = new QLineEdit(DialogChangePasswordClass);
        old_password->setObjectName(QString::fromUtf8("old_password"));
        old_password->setGeometry(QRect(130, 10, 261, 31));
        new_password = new QLineEdit(DialogChangePasswordClass);
        new_password->setObjectName(QString::fromUtf8("new_password"));
        new_password->setGeometry(QRect(130, 50, 261, 31));
        label_2 = new QLabel(DialogChangePasswordClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 31));
        retype_new_password = new QLineEdit(DialogChangePasswordClass);
        retype_new_password->setObjectName(QString::fromUtf8("retype_new_password"));
        retype_new_password->setGeometry(QRect(130, 90, 261, 31));
        label_3 = new QLabel(DialogChangePasswordClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 121, 31));
        btn_no = new QPushButton(DialogChangePasswordClass);
        btn_no->setObjectName(QString::fromUtf8("btn_no"));
        btn_no->setGeometry(QRect(300, 160, 91, 27));
        btn_no->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_no->setIcon(icon);
        btn_no->setIconSize(QSize(12, 12));
        btn_yes = new QPushButton(DialogChangePasswordClass);
        btn_yes->setObjectName(QString::fromUtf8("btn_yes"));
        btn_yes->setGeometry(QRect(200, 160, 91, 27));
        btn_yes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_yes->setIcon(icon1);
        btn_yes->setIconSize(QSize(14, 14));
        verticalLayoutWidget = new QWidget(DialogChangePasswordClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 130, 401, 20));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DialogChangePasswordClass);

        QMetaObject::connectSlotsByName(DialogChangePasswordClass);
    } // setupUi

    void retranslateUi(QDialog *DialogChangePasswordClass)
    {
        DialogChangePasswordClass->setWindowTitle(QCoreApplication::translate("DialogChangePasswordClass", "DialogChangePassword", nullptr));
        label->setText(QCoreApplication::translate("DialogChangePasswordClass", "Old password", nullptr));
        label_2->setText(QCoreApplication::translate("DialogChangePasswordClass", "New password", nullptr));
        label_3->setText(QCoreApplication::translate("DialogChangePasswordClass", "Retype new password", nullptr));
        btn_no->setText(QCoreApplication::translate("DialogChangePasswordClass", "No", nullptr));
        btn_yes->setText(QCoreApplication::translate("DialogChangePasswordClass", "Yes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChangePasswordClass: public Ui_DialogChangePasswordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHANGEPASSWORD_H
