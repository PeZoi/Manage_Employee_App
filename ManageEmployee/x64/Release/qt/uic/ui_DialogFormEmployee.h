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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormEmployeeClass
{
public:
    QPushButton *submit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLineEdit *id;
    QLabel *label_8;
    QLineEdit *last_name;
    QLabel *label_7;
    QLineEdit *first_name;
    QLabel *label_5;
    QLineEdit *password;
    QLabel *label_3;
    QLineEdit *confirm_password;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QCheckBox *is_enabled;
    QCheckBox *is_allow_password;
    QDateEdit *date_of_birth;
    QDateEdit *start_date_of_work;
    QComboBox *department;
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
    QLineEdit *name_9;
    QLabel *label_6;
    QLineEdit *address;
    QWidget *tab_3;
    QLabel *label_14;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_17;
    QLabel *label_18;
    QGraphicsView *iri_right;
    QPushButton *scan_right;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_16;
    QLabel *label_15;
    QGraphicsView *iri_left;
    QPushButton *scan_left;
    QLabel *label_19;

    void setupUi(QDialog *DialogFormEmployeeClass)
    {
        if (DialogFormEmployeeClass->objectName().isEmpty())
            DialogFormEmployeeClass->setObjectName(QString::fromUtf8("DialogFormEmployeeClass"));
        DialogFormEmployeeClass->resize(706, 628);
        submit = new QPushButton(DialogFormEmployeeClass);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(590, 590, 80, 25));
        tabWidget = new QTabWidget(DialogFormEmployeeClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 661, 561));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 0, 641, 351));
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

        last_name = new QLineEdit(formLayoutWidget);
        last_name->setObjectName(QString::fromUtf8("last_name"));
        last_name->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(2, QFormLayout::FieldRole, last_name);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        first_name = new QLineEdit(formLayoutWidget);
        first_name->setObjectName(QString::fromUtf8("first_name"));
        first_name->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout->setWidget(3, QFormLayout::FieldRole, first_name);

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

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label);

        is_enabled = new QCheckBox(formLayoutWidget);
        is_enabled->setObjectName(QString::fromUtf8("is_enabled"));

        formLayout->setWidget(10, QFormLayout::LabelRole, is_enabled);

        is_allow_password = new QCheckBox(formLayoutWidget);
        is_allow_password->setObjectName(QString::fromUtf8("is_allow_password"));

        formLayout->setWidget(4, QFormLayout::LabelRole, is_allow_password);

        date_of_birth = new QDateEdit(formLayoutWidget);
        date_of_birth->setObjectName(QString::fromUtf8("date_of_birth"));

        formLayout->setWidget(8, QFormLayout::FieldRole, date_of_birth);

        start_date_of_work = new QDateEdit(formLayoutWidget);
        start_date_of_work->setObjectName(QString::fromUtf8("start_date_of_work"));

        formLayout->setWidget(9, QFormLayout::FieldRole, start_date_of_work);

        department = new QComboBox(formLayoutWidget);
        department->setObjectName(QString::fromUtf8("department"));

        formLayout->setWidget(7, QFormLayout::FieldRole, department);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 360, 55, 16));
        avatar = new QGraphicsView(tab);
        avatar->setObjectName(QString::fromUtf8("avatar"));
        avatar->setGeometry(QRect(10, 380, 151, 131));
        select_avatar = new QPushButton(tab);
        select_avatar->setObjectName(QString::fromUtf8("select_avatar"));
        select_avatar->setGeometry(QRect(170, 380, 80, 25));
        delete_avatar = new QPushButton(tab);
        delete_avatar->setObjectName(QString::fromUtf8("delete_avatar"));
        delete_avatar->setGeometry(QRect(170, 410, 80, 25));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayoutWidget_2 = new QWidget(tab_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 10, 641, 231));
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

        name_9 = new QLineEdit(formLayoutWidget_2);
        name_9->setObjectName(QString::fromUtf8("name_9"));
        name_9->setStyleSheet(QString::fromUtf8("height: 25px;"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, name_9);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        address = new QLineEdit(formLayoutWidget_2);
        address->setObjectName(QString::fromUtf8("address"));
        address->setStyleSheet(QString::fromUtf8("height: 100px;"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, address);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 10, 191, 16));
        gridLayoutWidget = new QWidget(tab_3);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 60, 571, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        verticalLayout_4->addWidget(label_17, 0, Qt::AlignHCenter|Qt::AlignTop);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("color: red;"));

        verticalLayout_4->addWidget(label_18, 0, Qt::AlignHCenter|Qt::AlignTop);

        iri_right = new QGraphicsView(gridLayoutWidget);
        iri_right->setObjectName(QString::fromUtf8("iri_right"));

        verticalLayout_4->addWidget(iri_right);

        scan_right = new QPushButton(gridLayoutWidget);
        scan_right->setObjectName(QString::fromUtf8("scan_right"));

        verticalLayout_4->addWidget(scan_right);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        verticalLayout_3->addWidget(label_16, 0, Qt::AlignHCenter|Qt::AlignTop);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("color: red;"));

        verticalLayout_3->addWidget(label_15, 0, Qt::AlignHCenter|Qt::AlignTop);

        iri_left = new QGraphicsView(gridLayoutWidget);
        iri_left->setObjectName(QString::fromUtf8("iri_left"));

        verticalLayout_3->addWidget(iri_left);

        scan_left = new QPushButton(gridLayoutWidget);
        scan_left->setObjectName(QString::fromUtf8("scan_left"));

        verticalLayout_3->addWidget(scan_left);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 500, 631, 16));
        label_19->setStyleSheet(QString::fromUtf8("font: 15px"));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(DialogFormEmployeeClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DialogFormEmployeeClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormEmployeeClass)
    {
        DialogFormEmployeeClass->setWindowTitle(QCoreApplication::translate("DialogFormEmployeeClass", "DialogFormEmployee", nullptr));
        submit->setText(QCoreApplication::translate("DialogFormEmployeeClass", "\304\220\341\273\223ng \303\275", nullptr));
        label_9->setText(QCoreApplication::translate("DialogFormEmployeeClass", "M\303\243 s\341\273\221 (*)", nullptr));
        label_8->setText(QCoreApplication::translate("DialogFormEmployeeClass", "T\303\252n (*)", nullptr));
        label_7->setText(QCoreApplication::translate("DialogFormEmployeeClass", "H\341\273\215 (*)", nullptr));
        label_5->setText(QCoreApplication::translate("DialogFormEmployeeClass", "M\341\272\255t kh\341\272\251u", nullptr));
        label_3->setText(QCoreApplication::translate("DialogFormEmployeeClass", "X\303\241c nh\341\272\255n m\341\272\255t kh\341\272\251u", nullptr));
        label_2->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Ph\303\262ng ban", nullptr));
        label_4->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Ng\303\240y sinh", nullptr));
        label->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Ng\303\240y b\341\272\257t \304\221\341\272\247u (l\303\240m vi\341\273\207c)", nullptr));
        is_enabled->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Nh\303\242n vi\303\252n b\341\273\213 v\303\264 hi\341\273\207u ho\303\241", nullptr));
        is_allow_password->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Cho ph\303\251p s\341\273\255 d\341\273\245ng m\341\272\255t kh\341\272\251u", nullptr));
        label_13->setText(QCoreApplication::translate("DialogFormEmployeeClass", "\341\272\242nh", nullptr));
        select_avatar->setText(QCoreApplication::translate("DialogFormEmployeeClass", "T\303\254m", nullptr));
        delete_avatar->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Xo\303\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DialogFormEmployeeClass", "Tab 1", nullptr));
        label_10->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Email", nullptr));
        label_11->setText(QCoreApplication::translate("DialogFormEmployeeClass", "\304\220i\341\273\207n tho\341\272\241i", nullptr));
        label_12->setText(QCoreApplication::translate("DialogFormEmployeeClass", "\304\220i\341\273\207n tho\341\272\241i di \304\221\341\273\231ng", nullptr));
        label_6->setText(QCoreApplication::translate("DialogFormEmployeeClass", "\304\220\341\273\213a ch\341\273\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DialogFormEmployeeClass", "Tab 2", nullptr));
        label_14->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Select and capture the iris(es)", nullptr));
        label_17->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Right iris", nullptr));
        label_18->setText(QCoreApplication::translate("DialogFormEmployeeClass", "(Not registerd yet)", nullptr));
        scan_right->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Scan", nullptr));
        label_16->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Left iris", nullptr));
        label_15->setText(QCoreApplication::translate("DialogFormEmployeeClass", "(Not registerd yet)", nullptr));
        scan_left->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Scan", nullptr));
        label_19->setText(QCoreApplication::translate("DialogFormEmployeeClass", "Note: In order to ensure the iris quality, please capture THREE times for enrolled irises", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DialogFormEmployeeClass", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormEmployeeClass: public Ui_DialogFormEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMEMPLOYEE_H
