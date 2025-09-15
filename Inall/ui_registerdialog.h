/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLineEdit *userNameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPassword;
    QLineEdit *phoneNumberLineEdit;
    QPushButton *registerButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *register_userName;
    QLabel *register_userPassword;
    QLabel *register_confirmPassword;
    QLabel *register_userSex;
    QLabel *register_userPhoneNumber;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *male;
    QCheckBox *female;
    QCheckBox *otherSex;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(566, 474);
        RegisterDialog->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256 QMessageBox \347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\345\222\214\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"QMessageBox {\n"
"    background-color: white;   /* \347\231\275\350\211\262\350\203\214\346\231\257 */\n"
"    color: #333333;            /* \346\267\261\347\201\260\350\211\262\346\226\207\345\255\227\357\274\214\344\273\243\346\233\277\344\274\240\347\273\237\347\232\204\346\267\261\350\223\235\350\211\262\357\274\214\344\275\277\345\205\266\346\233\264\347\216\260\344\273\243 */\n"
"    font-family: 'Segoe UI', Tahoma, sans-serif; /* \346\233\264\347\216\260\344\273\243\347\232\204\345\255\227\344\275\223 */\n"
"    font-size: 14px;           /* \351\200\202\345\275\223\345\242\236\345\244\247\345\255\227\344\275\223\357\274\214\346\217\220\345\215\207\345\217\257\350\257\273\346\200\247 */\n"
"    border-radius: 8px;        /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    border: none;              /* \345\216\273\346\216\211\350"
                        "\276\271\346\241\206\347\272\277\357\274\214\344\275\277\347\224\250\351\230\264\345\275\261\346\235\245\344\273\243\346\233\277\350\276\271\346\241\206 */\n"
"    padding: 20px;             /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1); /* \346\267\273\345\212\240\346\237\224\345\222\214\347\232\204\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QMessageBox \346\214\211\351\222\256\347\232\204\346\240\267\345\274\217 */\n"
"QMessageBox QPushButton {\n"
"    background-color: #0078D4; /* \350\223\235\350\211\262\346\214\211\351\222\256\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\214\211\351\222\256\346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    border: none;              /* \345\216\273\346\216\211\346\214\211\351\222\256\350\276\271\346\241\206 */\n"
"    border-radius: 5px;        /* \345\234\206\350\247\222\346\214\211\351\222\256 */\n"
"    padding: 1"
                        "0px 20px;        /* \346\214\211\351\222\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 15px;           /* \351\200\202\344\270\255\347\232\204\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    transition: background-color 0.3s, transform 0.1s ease-in-out; /* \345\271\263\346\273\221\350\277\207\346\270\241\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"/* \346\214\211\351\222\256\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QMessageBox QPushButton:hover {\n"
"    background-color: #005A9E; /* \346\214\211\351\222\256\346\202\254\345\201\234\346\227\266\345\217\230\344\270\272\346\267\261\350\223\235\350\211\262 */\n"
"    transform: scale(1.05);     /* \346\202\254\345\201\234\346\227\266\347\250\215\345\276\256\346\224\276\345\244\247\346\214\211\351\222\256 */\n"
"}\n"
"\n"
"/* \346\214\211\351\222\256\347\202\271\345\207\273\346\225\210\346\236\234 */\n"
"QMessageBox QPushButton:pressed {\n"
"    background-color: #003B6B;  /* \346\214\211\351\222\256\346\214\211\344\270\213\346"
                        "\227\266\350\203\214\346\231\257\345\217\230\344\270\272\346\233\264\346\267\261\347\232\204\350\223\235\350\211\262 */\n"
"    transform: scale(0.95);     /* \346\214\211\351\222\256\346\214\211\344\270\213\346\227\266\347\250\215\345\276\256\347\274\251\345\260\217 */\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QMessageBox \347\232\204\346\240\207\351\242\230\346\240\217\346\240\267\345\274\217 */\n"
"QMessageBox QLabel[title=\"true\"] {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #0078D4; /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    padding: 10px;\n"
"    border-radius: 8px;\n"
"    margin-bottom: 20px; /* \346\267\273\345\212\240\345\272\225\351\203\250\351\227\264\350\267\235\357\274\214\344\275\277\345\276\227\346\240\207\351\242\230\344\270\215\347\264\247\345\207\221 */\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QMessageBox \345\233\276\346\240\207\347\232\204\346\240\267\345\274\217 */\n"
"QMessageBox QLabel {\n"
"    font-size: "
                        "12px;\n"
"    color: #0078D4;  /* \345\233\276\346\240\207\347\232\204\351\242\234\350\211\262\344\270\216\346\214\211\351\222\256\344\270\200\350\207\264\357\274\214\350\220\245\351\200\240\347\273\237\344\270\200\346\204\237 */\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"/* QLineEdit \346\240\267\345\274\217 */\n"
"QLineEdit {\n"
"    color: white;\n"
"   /* background-color: #506371;*/\n"
"	background-color: #87CEEB;\n"
"    font-size: 14px; /* \346\217\220\351\253\230\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
"    font-family: \"MingLiU-ExtB\";\n"
"    padding: 1px; /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"border: 2px solid #87CEEB; /* \345\242\236\345\212\240\350\276\271\346\241\206\344\273\245\347\252\201\345\207\272\350\276\223\345\205\245\346\241\206 */\n"
"}\n"
"\n"
"/* QPushButton \346\240"
                        "\267\345\274\217 */\n"
"QPushButton {\n"
"    background: #77BEDB; /* \347\201\260\350\223\235\350\203\214\346\231\257\357\274\214\346\237\224\345\222\214\351\205\215\350\211\262 */\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
"    font-family: \"MingLiU-ExtB\";\n"
"    font-size: 14px; /* \346\214\211\351\222\256\345\255\227\344\275\223\351\200\202\345\272\246\347\274\251\345\260\217 */\n"
"    padding: 8px; /* \350\260\203\346\225\264\345\206\205\350\276\271\350\267\235 */\n"
"    border: 2px solid #6A9FB5; /* \347\273\237\344\270\200\345\270\246\347\201\260\350\223\235\350\276\271\346\241\206 */\n"
"    transition: background-color 0.3s, transform 0.2s; /* \345\242\236\345\212\240\345\212\250\346\200\201\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #6A9FB5; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\345\217\230\344\270\272\346\237\224\345\222\214\350\223\235\350\211\262 */\n"
"    color: white; /* \346\217\220\351\253\230\345\257"
                        "\271\346\257\224\345\272\246 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4F708C; /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\347\225\245\346\232\227 */\n"
"    border-style: inset;\n"
"    transform: scale(0.95); /* \346\214\211\344\270\213\345\212\250\346\200\201\347\274\251\346\224\276\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"\n"
"\n"
"/* QLabel \346\240\267\345\274\217 */\n"
"QLabel {\n"
"    background: rgba(85, 170, 255, 0);\n"
"    color: black;\n"
"    font-family: \"MingLiU-ExtB\";\n"
"    font-size: 16px; /* \350\260\203\345\260\217\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220\346\226\207\345\255\227 */\n"
"    padding: 5px; /* \351\200\202\345\275\223\345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    border-bottom: 1px solid #87CEEB; /* \344\270\213\350\276\271\346\241\206\347\276\216\345\214\226 */\n"
"}\n"
"\n"
"/* QcheckBox \346\240\267\345\274\217 "
                        "*/\n"
"QCheckBox {\n"
"    color: black;\n"
"    font-size: 14px; /* \346\217\220\351\253\230\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}"));
        userNameLineEdit = new QLineEdit(RegisterDialog);
        userNameLineEdit->setObjectName("userNameLineEdit");
        userNameLineEdit->setGeometry(QRect(191, 70, 261, 20));
        passwordLineEdit = new QLineEdit(RegisterDialog);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(191, 125, 261, 20));
        confirmPassword = new QLineEdit(RegisterDialog);
        confirmPassword->setObjectName("confirmPassword");
        confirmPassword->setGeometry(QRect(191, 180, 261, 20));
        phoneNumberLineEdit = new QLineEdit(RegisterDialog);
        phoneNumberLineEdit->setObjectName("phoneNumberLineEdit");
        phoneNumberLineEdit->setGeometry(QRect(190, 290, 261, 20));
        registerButton = new QPushButton(RegisterDialog);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(230, 370, 101, 31));
        layoutWidget = new QWidget(RegisterDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 50, 90, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        register_userName = new QLabel(layoutWidget);
        register_userName->setObjectName("register_userName");

        verticalLayout->addWidget(register_userName);

        register_userPassword = new QLabel(layoutWidget);
        register_userPassword->setObjectName("register_userPassword");

        verticalLayout->addWidget(register_userPassword);

        register_confirmPassword = new QLabel(layoutWidget);
        register_confirmPassword->setObjectName("register_confirmPassword");

        verticalLayout->addWidget(register_confirmPassword);

        register_userSex = new QLabel(layoutWidget);
        register_userSex->setObjectName("register_userSex");

        verticalLayout->addWidget(register_userSex);

        register_userPhoneNumber = new QLabel(layoutWidget);
        register_userPhoneNumber->setObjectName("register_userPhoneNumber");

        verticalLayout->addWidget(register_userPhoneNumber);

        layoutWidget1 = new QWidget(RegisterDialog);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(190, 230, 261, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        male = new QCheckBox(layoutWidget1);
        male->setObjectName("male");

        horizontalLayout->addWidget(male);

        female = new QCheckBox(layoutWidget1);
        female->setObjectName("female");

        horizontalLayout->addWidget(female);

        otherSex = new QCheckBox(layoutWidget1);
        otherSex->setObjectName("otherSex");

        horizontalLayout->addWidget(otherSex);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214", nullptr));
        register_userName->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        register_userPassword->setText(QCoreApplication::translate("RegisterDialog", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        register_confirmPassword->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        register_userSex->setText(QCoreApplication::translate("RegisterDialog", "\346\200\247\345\210\253", nullptr));
        register_userPhoneNumber->setText(QCoreApplication::translate("RegisterDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        male->setText(QCoreApplication::translate("RegisterDialog", "\347\224\267", nullptr));
        female->setText(QCoreApplication::translate("RegisterDialog", "\345\245\263", nullptr));
        otherSex->setText(QCoreApplication::translate("RegisterDialog", "\345\205\266\344\273\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
