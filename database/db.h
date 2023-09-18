#ifndef DB_H
#define DB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class Db
{
public:
    Db();
    void open();
    void close();
    QSqlDatabase getDb();
    void updateEtudiant(QString numEt, QString nomEt, QString prenomEt, QString numTel);

private:
    QSqlDatabase mydb;
};

#endif // DB_H
