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
