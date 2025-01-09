/********************************************************************************
** Form generated from reading UI file 'Tools.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLS_H
#define UI_TOOLS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolsClass
{
public:
    QToolButton *change_password;
    QLabel *administrationLabel;
    QToolButton *settings;
    QToolButton *change_db;
    QToolButton *backup_data;
    QToolButton *restore_data;

    void setupUi(QWidget *ToolsClass)
    {
        if (ToolsClass->objectName().isEmpty())
            ToolsClass->setObjectName(QString::fromUtf8("ToolsClass"));
        ToolsClass->resize(752, 400);
        change_password = new QToolButton(ToolsClass);
        change_password->setObjectName(QString::fromUtf8("change_password"));
        change_password->setGeometry(QRect(90, 240, 251, 131));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        change_password->setFont(font);
        change_password->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/change_password.png"), QSize(), QIcon::Normal, QIcon::Off);
        change_password->setIcon(icon);
        change_password->setIconSize(QSize(70, 70));
        administrationLabel = new QLabel(ToolsClass);
        administrationLabel->setObjectName(QString::fromUtf8("administrationLabel"));
        administrationLabel->setGeometry(QRect(330, 40, 91, 31));
        QFont font1;
        font1.setPointSize(20);
        administrationLabel->setFont(font1);
        administrationLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #e56f68;\n"
"}"));
        settings = new QToolButton(ToolsClass);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setGeometry(QRect(390, 240, 241, 131));
        settings->setFont(font);
        settings->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings->setIcon(icon1);
        settings->setIconSize(QSize(80, 80));
        change_db = new QToolButton(ToolsClass);
        change_db->setObjectName(QString::fromUtf8("change_db"));
        change_db->setGeometry(QRect(500, 90, 161, 131));
        change_db->setFont(font);
        change_db->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icon/change_db.png"), QSize(), QIcon::Normal, QIcon::Off);
        change_db->setIcon(icon2);
        change_db->setIconSize(QSize(80, 80));
        backup_data = new QToolButton(ToolsClass);
        backup_data->setObjectName(QString::fromUtf8("backup_data"));
        backup_data->setGeometry(QRect(70, 90, 151, 131));
        backup_data->setFont(font);
        backup_data->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../icon/backup_db.png"), QSize(), QIcon::Normal, QIcon::Off);
        backup_data->setIcon(icon3);
        backup_data->setIconSize(QSize(70, 70));
        restore_data = new QToolButton(ToolsClass);
        restore_data->setObjectName(QString::fromUtf8("restore_data"));
        restore_data->setGeometry(QRect(290, 90, 161, 131));
        restore_data->setFont(font);
        restore_data->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../icon/restore_db.png"), QSize(), QIcon::Normal, QIcon::Off);
        restore_data->setIcon(icon4);
        restore_data->setIconSize(QSize(70, 70));

        retranslateUi(ToolsClass);

        QMetaObject::connectSlotsByName(ToolsClass);
    } // setupUi

    void retranslateUi(QWidget *ToolsClass)
    {
        ToolsClass->setWindowTitle(QCoreApplication::translate("ToolsClass", "Tools", nullptr));
        change_password->setText(QCoreApplication::translate("ToolsClass", "Change Admin Password", nullptr));
        administrationLabel->setText(QCoreApplication::translate("ToolsClass", "Tools", nullptr));
        settings->setText(QCoreApplication::translate("ToolsClass", "Settings", nullptr));
        change_db->setText(QCoreApplication::translate("ToolsClass", "Change Database", nullptr));
        backup_data->setText(QCoreApplication::translate("ToolsClass", "Backup Data", nullptr));
        restore_data->setText(QCoreApplication::translate("ToolsClass", "Restore Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolsClass: public Ui_ToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLS_H
