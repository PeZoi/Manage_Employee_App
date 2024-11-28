/********************************************************************************
** Form generated from reading UI file 'DialogFormEmployee.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORMEMPLOYEE_H
#define UI_DIALOGFORMEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormEmployeeClass
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLineEdit *id;
    QLabel *label_8;
    QLineEdit *first_name;
    QLabel *label_7;
    QLineEdit *last_name;
    QCheckBox *is_allow_password;
    QLabel *label_5;
    QLineEdit *password;
    QLabel *label_3;
    QLineEdit *confirm_password;
    QLabel *label_2;
    QComboBox *department;
    QLabel *label_4;
    QDateEdit *date_of_birth;
    QLabel *label;
    QDateEdit *start_date_of_work;
    QCheckBox *is_enabled;
    QLabel *label_13;
    QGraphicsView *avatar;
    QPushButton *select_avatar;
    QPushButton *delete_avatar;
    QWidget *tab_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLineEdit *email;
    QLabel *label_11;
    QLineEdit *phone_number;
    QLabel *label_12;
    QLineEdit *cell_phone;
    QLabel *label_6;
    QTextEdit *address;
    QWidget *tab_3;
    QLabel *label_14;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *iri_left;
    QLabel *iri_right;
    QPushButton *submit;
    QPushButton *cancelButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *errorLayout;

    void setupUi(QDialog *DialogFormEmployeeClass)
    {
        if (DialogFormEmployeeClass->objectName().isEmpty())
            DialogFormEmployeeClass->setObjectName(QString::fromUtf8("DialogFormEmployeeClass"));
        DialogFormEmployeeClass->resize(593, 610);
        tabWidget = new QTabWidget(DialogFormEmployeeClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 551, 531));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { background: transparent; border: none;}\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 0, 521, 351));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(1, QFormLayout::FieldRole, id);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        first_name = new QLineEdit(formLayoutWidget);
        first_name->setObjectName(QString::fromUtf8("first_name"));
        first_name->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(2, QFormLayout::FieldRole, first_name);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        last_name = new QLineEdit(formLayoutWidget);
        last_name->setObjectName(QString::fromUtf8("last_name"));
        last_name->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(3, QFormLayout::FieldRole, last_name);

        is_allow_password = new QCheckBox(formLayoutWidget);
        is_allow_password->setObjectName(QString::fromUtf8("is_allow_password"));

        formLayout->setWidget(4, QFormLayout::LabelRole, is_allow_password);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        password = new QLineEdit(formLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(5, QFormLayout::FieldRole, password);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        confirm_password = new QLineEdit(formLayoutWidget);
        confirm_password->setObjectName(QString::fromUtf8("confirm_password"));
        confirm_password->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(6, QFormLayout::FieldRole, confirm_password);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_2);

        department = new QComboBox(formLayoutWidget);
        department->setObjectName(QString::fromUtf8("department"));

        formLayout->setWidget(7, QFormLayout::FieldRole, department);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        date_of_birth = new QDateEdit(formLayoutWidget);
        date_of_birth->setObjectName(QString::fromUtf8("date_of_birth"));

        formLayout->setWidget(8, QFormLayout::FieldRole, date_of_birth);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label);

        start_date_of_work = new QDateEdit(formLayoutWidget);
        start_date_of_work->setObjectName(QString::fromUtf8("start_date_of_work"));

        formLayout->setWidget(9, QFormLayout::FieldRole, start_date_of_work);

        is_enabled = new QCheckBox(formLayoutWidget);
        is_enabled->setObjectName(QString::fromUtf8("is_enabled"));

        formLayout->setWidget(10, QFormLayout::LabelRole, is_enabled);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 350, 55, 16));
        avatar = new QGraphicsView(tab);
        avatar->setObjectName(QString::fromUtf8("avatar"));
        avatar->setGeometry(QRect(30, 370, 121, 111));
        select_avatar = new QPushButton(tab);
        select_avatar->setObjectName(QString::fromUtf8("select_avatar"));
        select_avatar->setGeometry(QRect(160, 370, 80, 25));
        select_avatar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        delete_avatar = new QPushButton(tab);
        delete_avatar->setObjectName(QString::fromUtf8("delete_avatar"));
        delete_avatar->setGeometry(QRect(160, 400, 80, 25));
        delete_avatar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8("../icon/general.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayoutWidget_2 = new QWidget(tab_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 0, 521, 231));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        email = new QLineEdit(formLayoutWidget_2);
        email->setObjectName(QString::fromUtf8("email"));
        email->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, email);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        phone_number = new QLineEdit(formLayoutWidget_2);
        phone_number->setObjectName(QString::fromUtf8("phone_number"));
        phone_number->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, phone_number);

        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_12);

        cell_phone = new QLineEdit(formLayoutWidget_2);
        cell_phone->setObjectName(QString::fromUtf8("cell_phone"));
        cell_phone->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, cell_phone);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        address = new QTextEdit(formLayoutWidget_2);
        address->setObjectName(QString::fromUtf8("address"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, address);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/contact.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon1, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 10, 191, 16));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 500, 631, 16));
        label_19->setStyleSheet(QString::fromUtf8("font: 15px"));
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(97, 73, 105, 16));
        label_23->setStyleSheet(QString::fromUtf8("color: red;"));
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(120, 50, 49, 16));
        label_22->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        label_25 = new QLabel(tab_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(350, 70, 105, 16));
        label_25->setStyleSheet(QString::fromUtf8("color: red;"));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(370, 50, 61, 16));
        label_24->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        iri_left = new QLabel(tab_3);
        iri_left->setObjectName(QString::fromUtf8("iri_left"));
        iri_left->setGeometry(QRect(30, 100, 231, 171));
        iri_left->setPixmap(QPixmap(QString::fromUtf8("../icon/no-device.jpg")));
        iri_right = new QLabel(tab_3);
        iri_right->setObjectName(QString::fromUtf8("iri_right"));
        iri_right->setGeometry(QRect(280, 100, 231, 171));
        iri_right->setPixmap(QPixmap(QString::fromUtf8("../icon/no-device.jpg")));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icon/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon2, QString());
        submit = new QPushButton(DialogFormEmployeeClass);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(410, 550, 81, 25));
        submit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        submit->setIcon(icon3);
        submit->setIconSize(QSize(14, 14));
        cancelButton = new QPushButton(DialogFormEmployeeClass);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(500, 550, 81, 25));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon4);
        cancelButton->setIconSize(QSize(12, 12));
        verticalLayoutWidget = new QWidget(DialogFormEmployeeClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 590, 601, 20));
        errorLayout = new QVBoxLayout(verticalLayoutWidget);
        errorLayout->setSpacing(6);
        errorLayout->setContentsMargins(11, 11, 11, 11);
        errorLayout->setObjectName(QString::fromUtf8("errorLayout"));
        errorLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DialogFormEmployeeClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DialogFormEmployeeClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormEmployeeClass)
    {
        DialogFormEmployeeClass->setWindowTitle(QCoreApplication::translate("DialogFormEmployeeClass", "DialogFormEmployee", nullptr));
        label_9->setText(QCoreApplication::translate("DialogFormEmployeeClass", "ID (*)", nullptr));
        label_8->setText(QCoreApplication::translate("DialogFormEmployeeClass", "First name (*)", nullptr));
        label_7->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Last name (*)", nullptr));
        is_allow_password->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Allow to use password", nullptr));
        label_5->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Comfirm password", nullptr));
        label_2->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Department", nullptr));
        label_4->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Date of birth", nullptr));
        label->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Start Working Date", nullptr));
        is_enabled->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Employee is disabled", nullptr));
        label_13->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Photo", nullptr));
        select_avatar->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Browse ...", nullptr));
        delete_avatar->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Clear photo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DialogFormEmployeeClass", "General", nullptr));
        label_10->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Email", nullptr));
        label_11->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Phone", nullptr));
        label_12->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Cell phone", nullptr));
        label_6->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Address", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DialogFormEmployeeClass", "Contact Information", nullptr));
        label_14->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Select and capture the iris(es)", nullptr));
        label_19->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Note: In order to ensure the iris quality, please capture THREE times for enrolled irises", nullptr));
        label_23->setText(QCoreApplication::translate("DialogFormEmployeeClass", "(Not registerd yet)", nullptr));
        label_22->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Left iris", nullptr));
        label_25->setText(QCoreApplication::translate("DialogFormEmployeeClass", "(Not registerd yet)", nullptr));
        label_24->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Right iris", nullptr));
        iri_left->setText(QString());
        iri_right->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DialogFormEmployeeClass", "Irises", nullptr));
        submit->setText(QCoreApplication::translate("DialogFormEmployeeClass", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormEmployeeClass: public Ui_DialogFormEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMEMPLOYEE_H
