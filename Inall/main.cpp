#include"inquire.h"
#include"homepage.h"
#include"myorders.h"
#include"manorder.h"
#include"flightinfopage.h"
#include"managerticket.h"
#include"myticket.h"
#include"login.h"
#include "buymenu.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include"homemanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//     // 加载 QSS 文件
//     QFile file(":/manageStyle.qss"); // 假设文件在资源文件中
//     if (file.open(QFile::ReadOnly)) {
//         QTextStream stream(&file);
//         QString qss = stream.readAll();
//         a.setStyleSheet(qss);
//         file.close();
//     } else {
//         qWarning("QSS file not found or cannot be opened.");
//     }
    Login w;
//    homemanager w;
//    recieve w;
//    HomePage w;
    w.show();
    return a.exec();
}
