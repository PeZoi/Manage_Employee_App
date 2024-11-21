/********************************************************************************
** Form generated from reading UI file 'DialogChangeDatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHANGEDATABASE_H
#define UI_DIALOGCHANGEDATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogChangeDatabaseClass
{
public:
    QComboBox *sql_list;
    QPushButton *connect;
    QStackedWidget *stackedWidget;
    QWidget *sqlite;
    QRadioButton *radio_create;
    QPushButton *select_sqlite;
    QRadioButton *radio_exist;
    QLabel *label;
    QLineEdit *sql_path;
    QWidget *mysql_sqlserver;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *host_name;
    QLineEdit *db_name;
    QLineEdit *port;
    QLineEdit *username;
    QLineEdit *password;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *DialogChangeDatabaseClass)
    {
        if (DialogChangeDatabaseClass->objectName().isEmpty())
            DialogChangeDatabaseClass->setObjectName(QString::fromUtf8("DialogChangeDatabaseClass"));
        DialogChangeDatabaseClass->resize(441, 313);
        sql_list = new QComboBox(DialogChangeDatabaseClass);
        sql_list->addItem(QString());
        sql_list->addItem(QString());
        sql_list->addItem(QString());
        sql_list->setObjectName(QString::fromUtf8("sql_list"));
        sql_list->setGeometry(QRect(10, 30, 421, 24));
        connect = new QPushButton(DialogChangeDatabaseClass);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(339, 260, 91, 25));
        connect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8("../icon/connect_db.png"), QSize(), QIcon::Normal, QIcon::Off);
        connect->setIcon(icon);
        stackedWidget = new QStackedWidget(DialogChangeDatabaseClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 70, 431, 171));
        sqlite = new QWidget();
        sqlite->setObjectName(QString::fromUtf8("sqlite"));
        radio_create = new QRadioButton(sqlite);
        radio_create->setObjectName(QString::fromUtf8("radio_create"));
        radio_create->setGeometry(QRect(220, 0, 101, 22));
        select_sqlite = new QPushButton(sqlite);
        select_sqlite->setObjectName(QString::fromUtf8("select_sqlite"));
        select_sqlite->setGeometry(QRect(340, 40, 91, 25));
        select_sqlite->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        radio_exist = new QRadioButton(sqlite);
        radio_exist->setObjectName(QString::fromUtf8("radio_exist"));
        radio_exist->setGeometry(QRect(50, 0, 131, 22));
        label = new QLabel(sqlite);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 81, 21));
        sql_path = new QLineEdit(sqlite);
        sql_path->setObjectName(QString::fromUtf8("sql_path"));
        sql_path->setGeometry(QRect(100, 40, 231, 24));
        stackedWidget->addWidget(sqlite);
        mysql_sqlserver = new QWidget();
        mysql_sqlserver->setObjectName(QString::fromUtf8("mysql_sqlserver"));
        label_2 = new QLabel(mysql_sqlserver);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 91, 21));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_3 = new QLabel(mysql_sqlserver);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 141, 21));
        label_3->setFont(font);
        label_4 = new QLabel(mysql_sqlserver);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 141, 21));
        label_4->setFont(font);
        label_5 = new QLabel(mysql_sqlserver);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 100, 141, 21));
        label_5->setFont(font);
        label_6 = new QLabel(mysql_sqlserver);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 141, 21));
        label_6->setFont(font);
        host_name = new QLineEdit(mysql_sqlserver);
        host_name->setObjectName(QString::fromUtf8("host_name"));
        host_name->setGeometry(QRect(150, 10, 281, 24));
        host_name->setFont(font);
        db_name = new QLineEdit(mysql_sqlserver);
        db_name->setObjectName(QString::fromUtf8("db_name"));
        db_name->setGeometry(QRect(150, 40, 281, 24));
        db_name->setFont(font);
        port = new QLineEdit(mysql_sqlserver);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(150, 70, 281, 24));
        port->setFont(font);
        username = new QLineEdit(mysql_sqlserver);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(150, 100, 281, 24));
        username->setFont(font);
        password = new QLineEdit(mysql_sqlserver);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(150, 130, 281, 24));
        password->setFont(font);
        stackedWidget->addWidget(mysql_sqlserver);
        verticalLayoutWidget = new QWidget(DialogChangeDatabaseClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 290, 441, 20));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DialogChangeDatabaseClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogChangeDatabaseClass);
    } // setupUi

    void retranslateUi(QDialog *DialogChangeDatabaseClass)
    {
        DialogChangeDatabaseClass->setWindowTitle(QCoreApplication::translate("DialogChangeDatabaseClass", "DialogChangeDatabase", nullptr));
        sql_list->setItemText(0, QCoreApplication::translate("DialogChangeDatabaseClass", "SQLITE", nullptr));
        sql_list->setItemText(1, QCoreApplication::translate("DialogChangeDatabaseClass", "MYSQL", nullptr));
        sql_list->setItemText(2, QCoreApplication::translate("DialogChangeDatabaseClass", "SQLServer", nullptr));

        connect->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Connect", nullptr));
        radio_create->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Create new", nullptr));
        select_sqlite->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Browse ...", nullptr));
        radio_exist->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Existing database", nullptr));
        label->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Database file", nullptr));
        label_2->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Host name:", nullptr));
        label_3->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Database  name:", nullptr));
        label_4->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Port: ", nullptr));
        label_5->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Username", nullptr));
        label_6->setText(QCoreApplication::translate("DialogChangeDatabaseClass", "Password", nullptr));
        host_name->setText(QString());
        db_name->setText(QString());
        port->setText(QString());
        username->setText(QString());
        password->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogChangeDatabaseClass: public Ui_DialogChangeDatabaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHANGEDATABASE_H
