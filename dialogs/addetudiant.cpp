#include "addetudiant.h"
#include "ui_addetudiant.h"

addEtudiant::addEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEtudiant)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Ajouter Etudiant");
    this->setFixedSize(405,300);

    ui->numEtInput->setupUI("^E\\d{4}$", "Le numéro étudiant doit être de la forme E0000");
    ui->numTelInput->setupUI("^(032|033|034|038)\\d{7}$", "Le numero de téléphone doit être de la forme\n03XXXXXXXX");
}

addEtudiant::~addEtudiant()
{
    delete ui;
}


void addEtudiant::on_OkButton_clicked()
{
    QString numEt, nomEt, prenomEt, numTel;
    numEt = ui->numEtInput->text();
    nomEt = ui->nomEtInput->text();
    prenomEt = ui->prenomEtInput->text();
    numTel = ui->numTelInput->text();

    MainWindow* parent = static_cast<MainWindow*>(this->parent());
    if(parent->addNewEtudiant(numEt, nomEt, prenomEt, numTel)){
        parent->resetTable();
        this->close();
    }
}


void addEtudiant::on_CancelButton_clicked()
{
    this->close();
}

