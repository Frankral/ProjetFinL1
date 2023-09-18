#ifndef DB_H
#define DB_H

#include <QSql>
#include <QSqlDatabase>
#include <QDebug>

class Db
{
public:
    Db();
    void open();
    void close();
    QSqlDatabase getDb();

private:
    QSqlDatabase mydb;
};

#endif // DB_H
