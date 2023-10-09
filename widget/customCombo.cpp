#include "customCombo.h"

CustomCombo::CustomCombo(QWidget *parent)
    :QComboBox(parent)
{
}

void CustomCombo::getItems(Db* database, QString table, QString column)
{
    QSqlQuery qry = database->getAll(table, column);
    while(qry.next()){
        this->addItem(qry.value(0).toString(), qry.value(0).toString());
    }
}

void CustomCombo::getItemsDate(Db* database, QString table, QString column)
{
    QSqlQuery qry = database->getAll(table, column);
    while(qry.next()){
        this->addItem(qry.value(0).toDate().toString("dd/MM/yyyy"), qry.value(0).toDate().toString("yyyy/MM/dd"));
    }
}

void CustomCombo::getChambre(Db* database, QString refbat, QString numChambre){
    QSqlQuery qry = database->getChambre(refbat);
    this->clear();
    while(qry.next()){
        this->addItem(qry.value(0).toString(), qry.value(0).toString());
    }
    if(numChambre != ""){
        this->setCurrentText(numChambre);
    } else {
        this->setCurrentIndex(0);
    }
}

void CustomCombo::setupUI(QString table, QString column, Db* database){
    if(table == "calendrier"){
        getItemsDate(database, table, column);
    } else {
        getItems(database, table, column);
    }
}

void CustomCombo::setupUI(QString refbat, Db* database, QString numchambre){
    getChambre(database, refbat, numchambre);
}
