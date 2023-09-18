#include "db.h"

Db::Db()
{
    mydb = QSqlDatabase::addDatabase("QPSQL");
    mydb.setHostName("localhost");
    mydb.setUserName("postgres");
    mydb.setPassword("root");
    mydb.setPort(5433);
    mydb.setDatabaseName("citeUniv");

}

void Db::open(){
    if(!mydb.open()){
        qDebug() << "Error, not connected";
    } else {
        qDebug() << "connected";
    }
}

void Db::close(){
    mydb.close();
    qDebug() << "Closed";
}

QSqlDatabase Db::getDb(){
    return mydb;
}

void Db::updateEtudiant(QString numEt, QString nomEt, QString prenomEt, QString numTel){
    QSqlQuery qry;
    qry.prepare("UPDATE etudiant SET nomet=:nomEt , prenomet=:prenomEt , numtel=:numTel WHERE numEt=:numEt");

    qry.bindValue(":nomEt", nomEt);
    qry.bindValue(":prenomEt", prenomEt);
    qry.bindValue(":numTel", numTel);
    qry.bindValue(":numEt", numEt);

    if (!qry.exec()) {
        qDebug() << "Query execution failed!";
    } else {
        qDebug() << "Updated Successfully";
    }
}
