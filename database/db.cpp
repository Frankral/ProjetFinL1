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


// etudiant


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

void Db::deleteEtudiant(QString numEt){
    QSqlQuery qry;
    qry.prepare("DELETE FROM louer WHERE numet=:numEt");
    qry.bindValue(":numEt", numEt);

    if (!qry.exec()) {
        qDebug() << "Query execution failed!";
        return;
    }

    qry.prepare("DELETE FROM etudiant WHERE numet=:numEt");
    qry.bindValue(":numEt", numEt);

    if (!qry.exec()) {
        qDebug() << "Query execution failed!";
    } else {
        qDebug() << "Deleted Successfully";
    }
}

void Db::addEtudiant(QString numEt, QString nomEt, QString prenomEt, QString numTel){
    QSqlQuery qry;
    qry.prepare("INSERT INTO etudiant VALUES (:numEt, :nomEt, :prenomEt, :numTel)");

    qry.bindValue(":numEt", numEt);
    qry.bindValue(":nomEt", nomEt);
    qry.bindValue(":prenomEt", prenomEt);
    qry.bindValue(":numTel", numTel);

    if (!qry.exec()) {
        qDebug() << "Query execution failed!";
    } else {
        qDebug() << "Added Successfully";
    }
}

bool Db::numEtudiantExist(QString numEt){
    QSqlQuery qry;
    qry.prepare("SELECT numet FROM etudiant WHERE numEt=:numEt");

    qry.bindValue(":numEt", numEt);

    if (qry.exec() & qry.next()) {
        return true;
    }
    return false;

}
