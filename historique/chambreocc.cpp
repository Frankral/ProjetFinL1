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

    model->sort(3, Qt::AscendingOrder);
    model->select();

    ui->ListeChambre->setModel(model);


    ui->ListeChambre->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->ListeChambre->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

