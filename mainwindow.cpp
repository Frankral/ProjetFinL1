#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydb->open();

    this->setWindowTitle("GESTION DE CITE UNIVERSITAIRE");

}

MainWindow::~MainWindow()
{
    delete ui;
    mydb->close();
}


void MainWindow::on_actionBatiment_triggered()
{
    BatimentCrud* crudBat = new BatimentCrud(this, mydb);
    this->setCentralWidget(crudBat);
}


void MainWindow::on_actionCalendrier_triggered()
{
    CalendrierCrud* crudCalendrier = new CalendrierCrud(this, mydb);
    this->setCentralWidget(crudCalendrier);
}


void MainWindow::on_actionChambre_triggered()
{
    ChambreCrud* crudChambre = new ChambreCrud(this, mydb);
    this->setCentralWidget(crudChambre);
}

void MainWindow::on_actionEtudiant_triggered()
{
    EtudiantCrud* crudEt = new EtudiantCrud(this, mydb);
    this->setCentralWidget(crudEt);
}

void MainWindow::on_actionLouer_triggered()
{
    LouerCrud* crudLouer = new LouerCrud(this, mydb);
    this->setCentralWidget(crudLouer);
}


void MainWindow::on_actionhistorique_de_chambre_triggered()
{
    ListeChambre* listechambre = new ListeChambre(this, mydb);
    this->setCentralWidget(listechambre);
}


void MainWindow::on_actionListe_des_Chambres_Occup_es_triggered()
{
    ChambreOcc* chambreOcc = new ChambreOcc(this);
    this->setCentralWidget(chambreOcc);
}


void MainWindow::on_crudBat_clicked()
{
    BatimentCrud* crudBat = new BatimentCrud(this, mydb);
    this->setCentralWidget(crudBat);
}


void MainWindow::on_crudCal_clicked()
{
    CalendrierCrud* crudCalendrier = new CalendrierCrud(this, mydb);
    this->setCentralWidget(crudCalendrier);
}


void MainWindow::on_crudChamb_clicked()
{
    ChambreCrud* crudChambre = new ChambreCrud(this, mydb);
    this->setCentralWidget(crudChambre);
}


void MainWindow::on_crudEt_clicked()
{
    EtudiantCrud* crudEt = new EtudiantCrud(this, mydb);
    this->setCentralWidget(crudEt);
}


void MainWindow::on_crudLouer_clicked()
{
    LouerCrud* crudLouer = new LouerCrud(this, mydb);
    this->setCentralWidget(crudLouer);
}


void MainWindow::on_ListeChambre_clicked()
{
    ListeChambre* listechambre = new ListeChambre(this, mydb);
    this->setCentralWidget(listechambre);
}


void MainWindow::on_ListeOccupee_clicked()
{
    ChambreOcc* chambreOcc = new ChambreOcc(this);
    this->setCentralWidget(chambreOcc);
}

