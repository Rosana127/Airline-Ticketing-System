#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include<QSqlError>

class Database {
public:
    Database(); // 构造函数
    bool connectToDatabase(); // 连接数据库的函数
    QSqlDatabase getDatabase() const; // 获取数据库连接的函数
    static Database& instance() {
        static Database instance;
        return instance;
    }
    static Database& getInstance() {
        static Database instance;  // C++11 特性：局部静态变量，确保单例模式
        return instance;
    }


private:
    QSqlDatabase db; // QSqlDatabase 对象，用于管理数据库连接
};

#endif // DATABASE_H
