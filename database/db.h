#ifndef DB_H
#define DB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>


class Db
{
public:
    Db();
    void open();
    void close();
    QSqlDatabase getDb();

    void update(QString table, QStringList columns, QStringList values, QStringList id, QStringList idVal);

    void del(QStringList tables, QStringList id, QStringList idVal);

    void add(QString table, QStringList values);

    // etudiant
    bool numEtudiantExist(QString numEt);

    // batiment
    bool refBatExist(QString refBat);

    // calendrier
    bool dateDebLocExist(QDate dateDebLoc);

private:
    QSqlDatabase mydb;
};

#endif // DB_H
