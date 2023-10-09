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

