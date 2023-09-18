#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydb->open();

    displayTable();

}

MainWindow::~MainWindow()
{
    delete ui;
    mydb->close();
}

void MainWindow::displayTable(){
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

    model->setTable("etudiant");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numéro Etudiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Etudiant"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom Etudiant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro Téléphone"));

    model->sort(0, Qt::AscendingOrder);
    model->select();

    ui->tableEtudiant->setItemDelegate(new QSqlRelationalDelegate(ui->tableEtudiant));
    ui->tableEtudiant->setItemDelegateForColumn(0, new CustomDelegate(this, "unedit", "", "", ""));
    ui->tableEtudiant->setItemDelegateForColumn(3, new CustomDelegate(this, "", "phoneNumber", "^(032|033|034|038)\\d{7}$", "Le numero de téléphone doit être de la forme 03XXXXXXXX"));

    ui->tableEtudiant->setModel(model);


    ui->tableEtudiant->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::resetTable(){
    displayTable();
    ui->tableEtudiant->repaint();
}

