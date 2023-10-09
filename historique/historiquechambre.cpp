#include "historiquechambre.h"
#include "ui_historiquechambre.h"

historiqueChambre::historiqueChambre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historiqueChambre)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Ajouter Batiment");
}

historiqueChambre::~historiqueChambre()
{
    delete ui;
}
