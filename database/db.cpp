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

void Db::update(QString table, QStringList columns, QStringList values, QStringList id, QStringList idVal)
{
    QSqlQuery qry;
    QString qryStr = "UPDATE " + table + " SET ";

    for(int i = 0; i< columns.length(); i++){
        qryStr += columns.at(i) + "='" + values.at(i) + "'";
        if(i+1 != columns.length()) qryStr += ", ";
    }

    qryStr += " WHERE ";

    for(int i = 0; i <id.length(); i++){
        qryStr += id.at(i) + "='" + idVal.at(i) + "'";
        if(i + 1 != id.length()) qryStr += " AND ";
    }

    qry.prepare(qryStr);

    if (!qry.exec()) {
        qDebug() << "Query execution failed!";
    } else {
        qDebug() << "Updated Successfully";
    }

}

void Db::del(QStringList tables, QStringList id, QStringList idVal)
{
    QSqlQuery qry;

    QString qryStr;

    foreach (QString table, tables) {
        qryStr = "DELETE FROM " + table + " WHERE ";
        for(int i = 0; i< id.length(); i++){
            qryStr += id.at(i) + "='" + idVal.at(i) + "'";
            if(i + 1 != id.length()) qryStr += " AND ";
        }

        qry.prepare(qryStr);

        if (!qry.exec()) {
            qDebug() << "Query execution failed!";
            return;
        }
    }

    qDebug() << "Deleted Successully";

}

void Db::add(QString table, QStringList values)
{
    QSqlQuery qry;

    QString qryStr = "INSERT INTO " + table + " VALUES(";

    for (int i = 0; i < values.length(); i++) {
        qryStr += "'" + values.at(i) + "'";
        if(i+1 != values.length()) qryStr += ",";

    }

    qryStr += ")";

    qDebug() << qryStr;

    qry.prepare(qryStr);

    if (!qry.exec()) {
        qDebug() << "Query execution failed!";
    } else {
        qDebug() << "Added Successfully";
    }


}





