/********************************************************************************
** Form generated from reading UI file 'Navbar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVBAR_H
#define UI_NAVBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navbar
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *back;
    QToolButton *logout;
    QToolButton *login;
    QToolButton *copyright;
    QToolButton *mode;
    QToolButton *exit;

    void setupUi(QWidget *Navbar)
    {
        if (Navbar->objectName().isEmpty())
            Navbar->setObjectName(QString::fromUtf8("Navbar"));
        Navbar->resize(602, 400);
        horizontalLayoutWidget = new QWidget(Navbar);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 493, 34));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        back = new QToolButton(horizontalLayoutWidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setStyleSheet(QString::fromUtf8("height: 25px"));
        back->setAutoRaise(false);

        horizontalLayout->addWidget(back);

        logout = new QToolButton(horizontalLayoutWidget);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setStyleSheet(QString::fromUtf8("height: 25px"));
        logout->setAutoRaise(false);

        horizontalLayout->addWidget(logout);

        login = new QToolButton(horizontalLayoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("height: 25px"));
        login->setAutoRaise(false);

        horizontalLayout->addWidget(login);

        copyright = new QToolButton(horizontalLayoutWidget);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setStyleSheet(QString::fromUtf8("height: 25px"));

        horizontalLayout->addWidget(copyright);

        mode = new QToolButton(horizontalLayoutWidget);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setStyleSheet(QString::fromUtf8("height: 25px"));

        horizontalLayout->addWidget(mode);

        exit = new QToolButton(horizontalLayoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setStyleSheet(QString::fromUtf8("height: 25px"));

        horizontalLayout->addWidget(exit);

        QWidget::setTabOrder(logout, copyright);
        QWidget::setTabOrder(copyright, mode);
        QWidget::setTabOrder(mode, exit);

        retranslateUi(Navbar);

        QMetaObject::connectSlotsByName(Navbar);
    } // setupUi

    void retranslateUi(QWidget *Navbar)
    {
        Navbar->setWindowTitle(QCoreApplication::translate("Navbar", "Navbar", nullptr));
        back->setText(QCoreApplication::translate("Navbar", "Tr\341\273\237 L\341\272\241i", nullptr));
        logout->setText(QCoreApplication::translate("Navbar", "\304\220\304\203ng xu\341\272\245t", nullptr));
        login->setText(QCoreApplication::translate("Navbar", "\304\220\304\203ng nh\341\272\255p", nullptr));
        copyright->setText(QCoreApplication::translate("Navbar", "B\341\272\243n quy\341\273\201n s\341\273\255 d\341\273\245ng", nullptr));
        mode->setText(QCoreApplication::translate("Navbar", "Ch\341\272\277 \304\221\341\273\231", nullptr));
        exit->setText(QCoreApplication::translate("Navbar", "Tho\303\241t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Navbar: public Ui_Navbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVBAR_H
