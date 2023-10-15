#include "historiquechambre.h"
#include "ui_historiquechambre.h"

historiqueChambre::historiqueChambre(QWidget *parent, QString refbat, QString numChambre) :
    QDialog(parent),
    ui(new Ui::historiqueChambre)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Ajouter Batiment");

    this->refbat = refbat;
    this->numChambre = numChambre;

    displayTable();

    ui->title->setText("Historique de la chambre '" + numChambre + "' du batiment '" + refbat + "'");
}

historiqueChambre::~historiqueChambre()
{
    delete ui;
}

void historiqueChambre::displayTable(){
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

    QString qry = "SELECT nomet, prenomet, datedebutlocation, datefinlocation ";
    qry += "FROM louer ";
    qry += "JOIN etudiant ON etudiant.numet = louer.numet ";
    qry += "WHERE numchambre = '" + numChambre + "' AND refbat = '" + refbat +"'";

    model->setQuery(qry);

    model->sort(3, Qt::AscendingOrder);
    model->select();

    ui->Historique->setModel(model);


    ui->Historique->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->Historique->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


// slots
void historiqueChambre::on_pushButton_clicked()
{
    this->close();
}

