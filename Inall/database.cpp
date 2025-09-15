#include "database.h"

Database::Database() {
    // 使用 ODBC 驱动
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Database::connectToDatabase() {
    // 设置 DSN 数据源
//    db.setDatabaseName("flightdb");
    db.setDatabaseName("abc");
    // 尝试连接到数据库
    if (!db.open()) {
        qDebug() << "Failed to connect to database: " << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}

QSqlDatabase Database::getDatabase() const {
    return db;
}
