#include "batimentcrud.h"
#include "ui_batimentcrud.h"

BatimentCrud::BatimentCrud(QWidget *parent, Db* database) :
    QWidget(parent),
    ui(new Ui::BatimentCrud)
{
    ui->setupUi(this);

    this->mydb = database;

    displayTable();

    ui->modifierBox->hide();

}

BatimentCrud::~BatimentCrud()
{
    delete ui;
}

void BatimentCrud::displayTable(){
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

    model->setTable("batiment");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Réference Batiment"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de locations"));

    model->sort(0, Qt::AscendingOrder);
    model->select();

    ui->tableBat->setItemDelegate(new QSqlRelationalDelegate(ui->tableBat));
    ui->tableBat->setItemDelegateForColumn(0, new CustomDelegate(this, "unedit", "", "", ""));
    ui->tableBat->setItemDelegateForColumn(1, new CustomDelegate(this, 0, 999));

    ui->tableBat->setModel(model);


    ui->tableBat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->tableBat->model(), &QAbstractItemModel::dataChanged, this, BatimentCrud::on_table_value_change);
    connect(ui->tableBat->selectionModel(), &QItemSelectionModel::selectionChanged, this, &BatimentCrud::on_row_selected);
}

void BatimentCrud::resetTable(){
    QSqlRelationalTableModel* model = static_cast<QSqlRelationalTableModel*>(ui->tableBat->model());
    model->select();
    ui->tableBat->repaint();
    ui->modifierBox->hide();
}

void BatimentCrud::fillInputChange(QTableView* qv, QModelIndexList indexes){
    ui->refBat->setText(qv->model()->data(indexes.at(0)).toString());
    ui->locationBat->setValue(qv->model()->data(indexes.at(1)).toInt());
}

bool BatimentCrud::addNewBatiment(QString refBat, int nbLocation){
    if(!mydb->refBatExist(refBat)){
        mydb->add("batiment", {refBat, QString::number(nbLocation)});
        return true;
    }
     QMessageBox::critical(this, "Erreur de référence du batiment", "La référence du batiment existe déjà\nVeuillez entrez un nouveau");
    return false;
}


// slots
void BatimentCrud::on_table_value_change(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles){
    Q_UNUSED(bottomRight);
    Q_UNUSED(roles);
    QModelIndexList qml;
    for (int i = 0; i < ui->tableBat->model()->columnCount(); ++i) {
        QModelIndex ind = ui->tableBat->model()->index(topLeft.row(), i);
        qml.append(ind);
    }

    fillInputChange(ui->tableBat, qml);
}

void BatimentCrud::on_row_selected(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    QTableView* qv = ui->tableBat;
    if(!selected.indexes().isEmpty())
    {
        fillInputChange(qv, selected.indexes());
        ui->modifierBox->show();
    } else {
        ui->modifierBox->hide();
    }
}


void BatimentCrud::on_modifierButton_clicked()
{
    QString refBat = ui->refBat->text();
    int nbLocation = ui->locationBat->value();

    mydb->update("batiment", {"location"}, {QString::number(nbLocation)}, {"refbat"}, {refBat});

    resetTable();
}

void BatimentCrud::on_supprimerButton_clicked()
{
    QModelIndex ind = ui->tableBat->selectionModel()->currentIndex();
    ind = ui->tableBat->model()->index(ind.row(), 0);
    QString refBat = ui->tableBat->model()->data(ind).toString();

    mydb->del({"louer", "chambre", "batiment"}, {"refbat"}, {refBat});

    resetTable();
    ui->modifierBox->hide();
}


void BatimentCrud::on_ajoutButton_clicked()
{
    addBatiment* addBat = new addBatiment(this);
    addBat->show();
}


void BatimentCrud::on_searchInput_textEdited(const QString &arg1)
{
    QSqlRelationalTableModel* model = static_cast<QSqlRelationalTableModel*>(ui->tableBat->model());
    if(arg1 != ""){
        QString arg = arg1.toLower();
        QString filter = "LOWER(refbat) LIKE '%" + arg + "%'";
        model->setFilter(filter);
        model->select();
    } else {
        model->setFilter("");
        model->select();
    }

}

