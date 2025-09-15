/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QPushButton *loginButton;
    QToolButton *closeButton;
    QLineEdit *txt_password;
    QToolButton *minimizeButton;
    QLineEdit *txt_user;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *registerButton;
    QCommandLinkButton *forgetButton;
    QCommandLinkButton *managerUiButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1505, 1067);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(8);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("/* \345\205\250\345\261\200\346\240\267\345\274\217 */\n"
"* {\n"
"    background: rgb(255, 255, 255);\n"
"    font-size: 24px; /* \350\260\203\345\244\247\345\255\227\344\275\223\344\273\245\351\200\202\345\272\224\345\205\250\345\261\217 */\n"
"    font-family: \"MingLiU-ExtB\";\n"
"}\n"
"\n"
"/* QFrame \346\240\267\345\274\217 */\n"
"QFrame {\n"
"    border: solid 10px rgba(0, 0, 0);\n"
"    background-image: url(:/pictures/airplane4.jpg); /* \347\241\256\344\277\235\350\267\257\345\276\204\346\234\211\346\225\210 */\n"
"    background-position: center; /* \345\261\205\344\270\255\346\230\276\347\244\272 */\n"
"    background-repeat: no-repeat; /* \351\230\262\346\255\242\351\207\215\345\244\215 */\n"
"    background-size: contain; /* \350\207\252\345\212\250\347\274\251\346\224\276\345\241\253\345\205\205\347\252\227\345\217\243 */\n"
"}\n"
"\n"
"/* QLineEdit \346\240\267\345\274\217 */\n"
"QLineEdit {\n"
"    color: #C6D8E5;\n"
"   /* background-color: #506371;*/\n"
"	background-color: #4F708C;\n"
"    fo"
                        "nt-size: 20px; /* \346\217\220\351\253\230\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
"    font-family: \"MingLiU-ExtB\";\n"
"    padding: 5px; /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"/* QPushButton \346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    background: #ced1d8;\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
"    font-family: \"MingLiU-ExtB\";\n"
"    font-size: 18px; /* \346\214\211\351\222\256\345\255\227\344\275\223\345\217\230\345\244\247 */\n"
"    padding: 10px; /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235\344\273\245\346\224\271\345\226\204\345\244\226\350\247\202 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"    font-family: \"MingLiU-ExtB\";\n"
"}\n"
"\n"
"\n"
"\n"
"/* QLabel \346\240\267\345\274\217 */\n"
"QLabel {\n"
"    background: rgba(85, 170, 255, 0);\n"
"    color: white;"
                        "\n"
"    font-family: \"MingLiU-ExtB\";\n"
"    font-size: 22px; /* \346\217\220\351\253\230\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    text-align: center; /* \345\261\205\344\270\255\345\257\271\351\275\220\346\226\207\345\255\227 */\n"
"}\n"
"\n"
"/*\346\234\200\345\260\217\345\214\226\345\222\214\345\205\263\351\227\255\346\214\211\351\222\256*/\n"
"/* QToolButton \346\240\267\345\274\217\357\274\232\346\234\200\345\260\217\345\214\226\345\222\214\345\205\263\351\227\255\346\214\211\351\222\256 */\n"
"QToolButton#minimizeButton, QToolButton#closeButton {\n"
"    background-color: rgba(255, 255, 255, 0.5); /* \345\215\212\351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"    border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"    border-radius: 5px; /* \345\234\206\350\247\222 */\n"
"    width: 30px; /* \347\273\237\344\270\200\345\256\275\345\272\246 */\n"
"    height: 30px; /* \347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"    font-size: 14px; /* \346\226\207\345\255\227"
                        "\345\244\247\345\260\217 */\n"
"    color: black; /* \345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QToolButton#toolButton:hover, QToolButton#toolButton_2:hover {\n"
"    background-color: rgba(200, 200, 200, 0.8); /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\345\214\226 */\n"
"}\n"
"\n"
"/* \347\211\271\346\256\212\346\240\267\345\274\217\357\274\232\345\205\263\351\227\255\346\214\211\351\222\256 */\n"
"QToolButton#toolButton_2 {\n"
"   QToolButton#toolButton_2 {\n"
"    background-color: rgba(255, 100, 100, 0.8); /* \345\205\263\351\227\255\346\214\211\351\222\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"}\n"
"\n"
"QToolButton#toolButton_2:hover {\n"
"    background-color: rgba(255, 50, 50, 1); /* \345\205\263\351\227\255\346\214\211\351\222\256\346\202\254\345\201\234\346\227\266\345\217\230\346\267\261\347\272\242\350\211\262 */\n"
"}\n"
"\n"
"\n"
"QMess"
                        "ageBox {\n"
"    background-color: white;   /* \347\231\275\350\211\262\350\203\214\346\231\257 */\n"
"    color: #333333;            /* \346\267\261\347\201\260\350\211\262\346\226\207\345\255\227\357\274\214\344\273\243\346\233\277\344\274\240\347\273\237\347\232\204\346\267\261\350\223\235\350\211\262\357\274\214\344\275\277\345\205\266\346\233\264\347\216\260\344\273\243 */\n"
"    font-family: 'Segoe UI', Tahoma, sans-serif; /* \346\233\264\347\216\260\344\273\243\347\232\204\345\255\227\344\275\223 */\n"
"    font-size: 14px;           /* \351\200\202\345\275\223\345\242\236\345\244\247\345\255\227\344\275\223\357\274\214\346\217\220\345\215\207\345\217\257\350\257\273\346\200\247 */\n"
"    border-radius: 8px;        /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    border: none;              /* \345\216\273\346\216\211\350\276\271\346\241\206\347\272\277\357\274\214\344\275\277\347\224\250\351\230\264\345\275\261\346\235\245\344\273\243\346\233\277\350\276\271\346\241\206 */\n"
"    paddin"
                        "g: 20px;             /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235 */\n"
"    box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1); /* \346\267\273\345\212\240\346\237\224\345\222\214\347\232\204\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256 QMessageBox \346\214\211\351\222\256\347\232\204\346\240\267\345\274\217 */\n"
"QMessageBox QPushButton {\n"
"    background-color: #0078D4; /* \350\223\235\350\211\262\346\214\211\351\222\256\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\214\211\351\222\256\346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    border: none;              /* \345\216\273\346\216\211\346\214\211\351\222\256\350\276\271\346\241\206 */\n"
"    border-radius: 5px;        /* \345\234\206\350\247\222\346\214\211\351\222\256 */\n"
"    padding: 10px 20px;        /* \346\214\211\351\222\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 15px;           /* \351\200\202\344\270\255\347\232\204\345\255\227"
                        "\344\275\223\345\244\247\345\260\217 */\n"
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
"    background-color: #003B6B;  /* \346\214\211\351\222\256\346\214\211\344\270\213\346\227\266\350\203\214\346\231\257\345\217\230\344\270\272\346\233\264\346\267\261\347\232\204\350\223\235\350\211\262 */\n"
"    transform: scale(0.95);     /* \346\214\211"
                        "\351\222\256\346\214\211\344\270\213\346\227\266\347\250\215\345\276\256\347\274\251\345\260\217 */\n"
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
"    font-size: 12px;\n"
"    color: #0078D4;  /* \345\233\276\346\240\207\347\232\204\351\242\234\350\211\262\344\270\216\346\214\211\351\222\256\344\270\200\350\207\264\357\274\214\350\220"
                        "\245\351\200\240\347\273\237\344\270\200\346\204\237 */\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        loginButton = new QPushButton(frame);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(640, 520, 201, 40));
        closeButton = new QToolButton(frame);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(1380, 0, 35, 35));
        txt_password = new QLineEdit(frame);
        txt_password->setObjectName("txt_password");
        txt_password->setGeometry(QRect(550, 310, 411, 32));
        minimizeButton = new QToolButton(frame);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(1340, 0, 35, 35));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(minimizeButton->sizePolicy().hasHeightForWidth());
        minimizeButton->setSizePolicy(sizePolicy1);
        minimizeButton->setAcceptDrops(false);
        txt_user = new QLineEdit(frame);
        txt_user->setObjectName("txt_user");
        txt_user->setGeometry(QRect(550, 230, 411, 32));
        txt_user->setAutoFillBackground(false);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 240, 66, 24));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(430, 310, 44, 24));
        registerButton = new QCommandLinkButton(frame);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(840, 420, 141, 51));
        registerButton->setStyleSheet(QString::fromUtf8("QCommandLinkButton {\n"
"    background: transparent;   /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: white;              /* \345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    font-size: 14pt;           /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27210pt */\n"
"    border: none;              /* \345\216\273\346\216\211\350\276\271\346\241\206 */\n"
"    padding: 5px;              /* \350\260\203\346\225\264\346\214\211\351\222\256\345\206\205\351\203\250\351\227\264\350\267\235\357\274\214\345\217\257\344\273\245\346\240\271\346\215\256\351\234\200\350\246\201\345\276\256\350\260\203 */\n"
"}"));
        registerButton->setAutoRepeatDelay(100);
        forgetButton = new QCommandLinkButton(frame);
        forgetButton->setObjectName("forgetButton");
        forgetButton->setGeometry(QRect(490, 420, 186, 41));
        forgetButton->setStyleSheet(QString::fromUtf8("QCommandLinkButton {\n"
"    background: transparent;   /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: white;              /* \345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    font-size: 14pt;           /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27210pt */\n"
"    border: none;              /* \345\216\273\346\216\211\350\276\271\346\241\206 */\n"
"    padding: 5px;              /* \350\260\203\346\225\264\346\214\211\351\222\256\345\206\205\351\203\250\351\227\264\350\267\235\357\274\214\345\217\257\344\273\245\346\240\271\346\215\256\351\234\200\350\246\201\345\276\256\350\260\203 */\n"
"}"));
        managerUiButton = new QCommandLinkButton(frame);
        managerUiButton->setObjectName("managerUiButton");
        managerUiButton->setGeometry(QRect(20, 40, 186, 41));
        managerUiButton->setStyleSheet(QString::fromUtf8("QCommandLinkButton {\n"
"    background: transparent;   /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    color: white;              /* \345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    font-size: 14pt;           /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27210pt */\n"
"    border: none;              /* \345\216\273\346\216\211\350\276\271\346\241\206 */\n"
"    padding: 5px;              /* \350\260\203\346\225\264\346\214\211\351\222\256\345\206\205\351\203\250\351\227\264\350\267\235\357\274\214\345\217\257\344\273\245\346\240\271\346\215\256\351\234\200\350\246\201\345\276\256\350\260\203 */\n"
"}"));

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1505, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        txt_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Please input Password", nullptr));
        minimizeButton->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        txt_user->setPlaceholderText(QCoreApplication::translate("MainWindow", "Please input UserName", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\347\224\250\346\210\267", nullptr));
        forgetButton->setText(QCoreApplication::translate("MainWindow", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        managerUiButton->setText(QCoreApplication::translate("MainWindow", "\350\267\263\350\275\254\345\210\260\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
