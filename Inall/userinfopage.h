#ifndef USERINFOPAGE_H
#define USERINFOPAGE_H
#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class UserInfoPage;
}

class UserInfoPage : public QWidget {
    Q_OBJECT

public:
    explicit UserInfoPage(Database *db, const QString &username, QWidget *parent = nullptr);
    ~UserInfoPage();

private slots:
    void displayUserInfo();
    void changePassword();
    void changePhoneNumber();

private:
    Ui::UserInfoPage *ui;
    Database *dbcon;
    QString currentUsername;
};

#endif // USERINFOPAGE_H
