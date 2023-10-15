#include "chambreocc.h"
#include "ui_chambreocc.h"

ChambreOcc::ChambreOcc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChambreOcc)
{
    ui->setupUi(this);

    displayTable();
}

ChambreOcc::~ChambreOcc()
{
    delete ui;
}

void ChambreOcc::displayTable(){
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

    QString qry = "SELECT datedebutlocation, datefinlocation, etudiant.nomet, etudiant.prenomet, louer.numchambre, louer.refbat, chambre.categorie ";
    qry += "FROM louer ";
    qry += "JOIN chambre ON chambre.numchambre = louer.numchambre ";
    qry += "JOIN etudiant ON etudiant.numet = louer.numet ";
    qry += "WHERE datefinlocation >= CURRENT_TIMESTAMP";

    model->setQuery(qry);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date Début\nlocation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Fin \nlocation"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Etudiant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom Etudiant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numéro \nChambre"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Réference\n Batiment"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Catégorie"));


    model->sort(0, Qt::AscendingOrder);
    model->select();

    ui->ListeChambre->setModel(model);


    ui->ListeChambre->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->ListeChambre->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

