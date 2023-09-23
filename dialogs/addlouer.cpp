#include "addlouer.h"
#include "ui_addlouer.h"

addLouer::addLouer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addLouer)
{
    ui->setupUi(this);
    LouerCrud* par = static_cast<LouerCrud*>(parent);

    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Ajouter Location");
    this->setFixedSize(405,300);

    ui->numEt->setupUI("etudiant", "numet", par->getDb());
    ui->refBat->setupUI("batiment", "refbat", par->getDb());
    ui->dateDebLoc->setupUI("calendrier", "datedebutlocation", par->getDb());
}

addLouer::~addLouer()
{
    delete ui;
}

//slots

void addLouer::on_OkButton_clicked()
{
    QString numEt, refBat, numChambre, dateDebLoc;
    QDate dateFinLoc = ui->dateFinLoc->date();
    numEt = ui->numEt->currentText();
    refBat = ui->refBat->currentText();
    numChambre = ui->numChambre->currentText();
    dateDebLoc = ui->dateDebLoc->currentText();


    LouerCrud* parent = static_cast<LouerCrud*>(this->parent());
    if(parent->addNewLocation(numEt, refBat, numChambre, dateDebLoc, dateFinLoc)){
        parent->resetTable();
        this->close();
    }

}


void addLouer::on_CancelButton_clicked()
{
    this->close();
}

void addLouer::on_refBat_currentTextChanged(const QString &arg1)
{
    LouerCrud* parent = static_cast<LouerCrud*>(this->parent());
    ui->numChambre->setupUI(arg1, parent->getDb(), "");
}

