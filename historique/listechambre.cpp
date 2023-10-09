#include "listechambre.h"
#include "ui_listechambre.h"

ListeChambre::ListeChambre(QWidget *parent, Db* database) :
    QWidget(parent),
    ui(new Ui::ListeChambre)
{
    ui->setupUi(this);
    this->mydb = database;

    displayTable();

    ui->voirButton->hide();
}

ListeChambre::~ListeChambre()
{
    delete ui;
}

void ListeChambre::displayTable(){
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel();

    model->setTable("chambre");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Réference Batiment"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro de Chambre"));

    model->removeColumn(2);

    model->sort(0, Qt::AscendingOrder);
    model->select();

    ui->VueChambre->setItemDelegate(new QSqlRelationalDelegate(ui->VueChambre));

    ui->VueChambre->setModel(model);


    ui->VueChambre->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->VueChambre->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->VueChambre->selectionModel(), &QItemSelectionModel::selectionChanged, this, &ListeChambre::on_row_selected);
}


// slots
void ListeChambre::on_row_selected(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    if(!selected.indexes().isEmpty())
    {
        ui->voirButton->show();
    } else {
        ui->voirButton->hide();
    }
}


void ListeChambre::on_searchInput_textEdited(const QString &arg1)
{
    ui->voirButton->hide();
    QSqlRelationalTableModel* model = static_cast<QSqlRelationalTableModel*>(ui->VueChambre->model());
    if(arg1 != ""){
        QString arg = arg1.toLower();
        QString filter = "LOWER(refbat) LIKE '%" + arg + "%' OR LOWER(numchambre) LIKE '%" + arg + "%'";
        model->setFilter(filter);
        model->select();
    } else {
        model->setFilter("");
        model->select();
    }
}


void ListeChambre::on_voirButton_clicked()
{
    QModelIndex ind = ui->VueChambre->selectionModel()->currentIndex();
    ind = ui->VueChambre->model()->index(ind.row(), 0);
    QString refbat = ui->VueChambre->model()->data(ind).toString();
    ind = ui->VueChambre->model()->index(ind.row(), 1);
    QString numChambre = ui->VueChambre->model()->data(ind).toString();
    historiqueChambre* historique = new historiqueChambre(this, refbat, numChambre);
    historique->show();
}

