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
    void updateEtudiant(QString numEt, QString nomEt, QString prenomEt, QString numTel);
    void deleteEtudiant(QString numEt);
    void addEtudiant(QString numEt, QString NomEt, QString prenomEt, QString numTel);
    bool numEtudiantExist(QString numEt);

private:
    QSqlDatabase mydb;
};

#endif // DB_H
