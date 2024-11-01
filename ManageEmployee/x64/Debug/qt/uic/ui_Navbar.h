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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navbar
{
public:
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *navbarLayout;
    QPushButton *back;
    QPushButton *logout;
    QPushButton *login;
    QPushButton *copyright;
    QPushButton *mode;
    QPushButton *exit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *questionButton;
    QPushButton *informationButton;

    void setupUi(QWidget *Navbar)
    {
        if (Navbar->objectName().isEmpty())
            Navbar->setObjectName(QString::fromUtf8("Navbar"));
        Navbar->resize(778, 68);
        frame = new QFrame(Navbar);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 781, 61));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: 1px solid lightgray;\n"
"	background: #efefef;\n"
"}\n"
"\n"
"QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 555, 41));
        navbarLayout = new QHBoxLayout(horizontalLayoutWidget);
        navbarLayout->setSpacing(6);
        navbarLayout->setContentsMargins(11, 11, 11, 11);
        navbarLayout->setObjectName(QString::fromUtf8("navbarLayout"));
        navbarLayout->setContentsMargins(0, 0, 0, 0);
        back = new QPushButton(horizontalLayoutWidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon);

        navbarLayout->addWidget(back);

        logout = new QPushButton(horizontalLayoutWidget);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logout->setIcon(icon1);

        navbarLayout->addWidget(logout);

        login = new QPushButton(horizontalLayoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icon/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setIcon(icon2);

        navbarLayout->addWidget(login);

        copyright = new QPushButton(horizontalLayoutWidget);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../icon/lisence.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyright->setIcon(icon3);

        navbarLayout->addWidget(copyright);

        mode = new QPushButton(horizontalLayoutWidget);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../icon/mode.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode->setIcon(icon4);

        navbarLayout->addWidget(mode);

        exit = new QPushButton(horizontalLayoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon5);

        navbarLayout->addWidget(exit);

        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(700, 10, 75, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        questionButton = new QPushButton(horizontalLayoutWidget_2);
        questionButton->setObjectName(QString::fromUtf8("questionButton"));
        questionButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"width: 15px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../icon/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        questionButton->setIcon(icon6);
        questionButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(questionButton);

        informationButton = new QPushButton(horizontalLayoutWidget_2);
        informationButton->setObjectName(QString::fromUtf8("informationButton"));
        informationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	background: transparent;\n"
"height: 25px;\n"
"width: 15px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	margin-top: -2px;\n"
"	margin-left: -2px;\n"
"    border: 2px solid #aaa;\n"
"	background: lightgray;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../icon/question-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        informationButton->setIcon(icon7);
        informationButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(informationButton);

        QWidget::setTabOrder(logout, copyright);
        QWidget::setTabOrder(copyright, mode);
        QWidget::setTabOrder(mode, exit);

        retranslateUi(Navbar);

        QMetaObject::connectSlotsByName(Navbar);
    } // setupUi

    void retranslateUi(QWidget *Navbar)
    {
        Navbar->setWindowTitle(QCoreApplication::translate("Navbar", "Navbar", nullptr));
        back->setText(QCoreApplication::translate("Navbar", "Back", nullptr));
        logout->setText(QCoreApplication::translate("Navbar", "Logout", nullptr));
        login->setText(QCoreApplication::translate("Navbar", "Login", nullptr));
        copyright->setText(QCoreApplication::translate("Navbar", "License", nullptr));
        mode->setText(QCoreApplication::translate("Navbar", "Mode", nullptr));
        exit->setText(QCoreApplication::translate("Navbar", "Exit", nullptr));
        questionButton->setText(QString());
        informationButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Navbar: public Ui_Navbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVBAR_H
