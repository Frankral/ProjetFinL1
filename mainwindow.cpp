#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydb->open();

    displayTable();

    ui->modifierBox->hide();
    ui->numEtudiant->hide();

    ui->InputNumTel->setupUI("^(032|033|034|038)\\d{7}$", "Le numero de téléphone doit être de la forme\n03XXXXXXXX");

    connect(ui->tableEtudiant->model(), &QAbstractItemModel::dataChanged, this, MainWindow::on_table_value_change);
    connect(ui->tableEtudiant->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_row_selected);
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
    connect(ui->tableEtudiant->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_row_selected);
}

void MainWindow::fillInputChange(QTableView* qv, QModelIndexList indexes){
    ui->numEtudiant->setText(qv->model()->data(indexes.at(0)).toString());
    ui->InputNom->setText(qv->model()->data(indexes.at(1)).toString());
    ui->InputPrenom->setText(qv->model()->data(indexes.at(2)).toString());
    ui->InputNumTel->setText(qv->model()->data(indexes.at(3)).toString());
}

// slots
void MainWindow::on_table_value_change(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles){
    Q_UNUSED(bottomRight);
    Q_UNUSED(roles);
    QModelIndexList qml;
    for (int i = 0; i < ui->tableEtudiant->model()->columnCount(); ++i) {
        QModelIndex ind = ui->tableEtudiant->model()->index(topLeft.row(), i);
        qml.append(ind);
    }

    fillInputChange(ui->tableEtudiant, qml);
}

void MainWindow::on_row_selected(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    QTableView* qv = ui->tableEtudiant;
    if(!selected.indexes().isEmpty())
    {
        fillInputChange(qv, selected.indexes());
        ui->modifierBox->show();
    } else {
        ui->modifierBox->hide();
    }
}


void MainWindow::on_modifierButton_clicked()
{
    QString nomEt, prenomEt, numTel, numEt;
    nomEt = ui->InputNom->text();
    prenomEt = ui->InputPrenom->text();
    numTel = ui->InputNumTel->text();
    numEt = ui->numEtudiant->text();

    QRegularExpression* regex = new QRegularExpression("^(032|033|034|038)\\d{7}$");
    QRegularExpressionMatch match = regex->match(numTel);

    if(match.hasMatch()){
        mydb->updateEtudiant(numEt,nomEt,prenomEt,numTel);
        resetTable();
    }

}

