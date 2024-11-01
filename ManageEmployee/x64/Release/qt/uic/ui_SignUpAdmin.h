/********************************************************************************
** Form generated from reading UI file 'SignUpAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPADMIN_H
#define UI_SIGNUPADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpAdminClass
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *email;
    QLineEdit *password;
    QLabel *label_2;
    QLineEdit *password_confirm;
    QLabel *label;
    QLabel *label_3;
    QPushButton *btn_signup;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignUpAdminClass)
    {
        if (SignUpAdminClass->objectName().isEmpty())
            SignUpAdminClass->setObjectName(QString::fromUtf8("SignUpAdminClass"));
        SignUpAdminClass->resize(600, 266);
        centralWidget = new QWidget(SignUpAdminClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 60, 571, 103));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        email = new QLineEdit(formLayoutWidget);
        email->setObjectName(QString::fromUtf8("email"));

        formLayout->setWidget(1, QFormLayout::FieldRole, email);

        password = new QLineEdit(formLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));

        formLayout->setWidget(2, QFormLayout::FieldRole, password);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        password_confirm = new QLineEdit(formLayoutWidget);
        password_confirm->setObjectName(QString::fromUtf8("password_confirm"));

        formLayout->setWidget(3, QFormLayout::FieldRole, password_confirm);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 10, 331, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        btn_signup = new QPushButton(centralWidget);
        btn_signup->setObjectName(QString::fromUtf8("btn_signup"));
        btn_signup->setGeometry(QRect(500, 170, 80, 25));
        SignUpAdminClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SignUpAdminClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        SignUpAdminClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SignUpAdminClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SignUpAdminClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SignUpAdminClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SignUpAdminClass->setStatusBar(statusBar);

        retranslateUi(SignUpAdminClass);

        QMetaObject::connectSlotsByName(SignUpAdminClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpAdminClass)
    {
        SignUpAdminClass->setWindowTitle(QCoreApplication::translate("SignUpAdminClass", "SignUpAdmin", nullptr));
        label_4->setText(QCoreApplication::translate("SignUpAdminClass", "Email: ", nullptr));
        label_2->setText(QCoreApplication::translate("SignUpAdminClass", "X\303\241c nh\341\272\255n m\341\272\255t kh\341\272\251u:", nullptr));
        label->setText(QCoreApplication::translate("SignUpAdminClass", "M\341\272\255t kh\341\272\251u: ", nullptr));
        label_3->setText(QCoreApplication::translate("SignUpAdminClass", "\304\220\304\203ng k\303\275 t\303\240i kho\341\272\243n admin", nullptr));
        btn_signup->setText(QCoreApplication::translate("SignUpAdminClass", "\304\220\304\203ng k\303\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpAdminClass: public Ui_SignUpAdminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPADMIN_H
