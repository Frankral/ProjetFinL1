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

    // etudiant
    void addEtudiant(QString numEt, QString NomEt, QString prenomEt, QString numTel);
    bool numEtudiantExist(QString numEt);


    void update(QString table, QStringList columns, QStringList values, QStringList id, QStringList idVal);

    void del(QStringList tables, QStringList id, QStringList idVal);

    void add(QString table, QStringList values);

private:
    QSqlDatabase mydb;
};

#endif // DB_H
