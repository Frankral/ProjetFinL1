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
    ui->verifierButton->hide();
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
    connect(ui->VueChambre->horizontalHeader(), &QHeaderView::sectionClicked, this, &ListeChambre::handleSectionClicked);
}


// slots
void ListeChambre::handleSectionClicked(int logicalIndex){
    Q_UNUSED(logicalIndex);
    ui->voirButton->hide();
    ui->verifierButton->hide();
}

void ListeChambre::on_row_selected(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    if(!selected.indexes().isEmpty())
    {
        ui->voirButton->show();
        ui->verifierButton->show();
    } else {
        ui->voirButton->hide();
        ui->verifierButton->hide();
    }
}


void ListeChambre::on_searchInput_textEdited(const QString &arg1)
{
    ui->voirButton->hide();
    ui->verifierButton->hide();
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

void ListeChambre::verifierDisponibiliteChambre()
{

    QModelIndex ind = ui->VueChambre->selectionModel()->currentIndex();
    ind = ui->VueChambre->model()->index(ind.row(), 0);
    QString refBat = ui->VueChambre->model()->data(ind).toString();
    ind = ui->VueChambre->model()->index(ind.row(), 1);
    QString numChambre = ui->VueChambre->model()->data(ind).toString();


    QString query = "SELECT chambre.REFBAT, chambre.NUMCHAMBRE FROM chambre "
                    "LEFT JOIN louer ON chambre.REFBAT = louer.REFBAT AND chambre.NUMCHAMBRE = louer.NUMCHAMBRE "
                    "WHERE louer.NUMET IS NULL "
                    "AND chambre.REFBAT = :refBat "
                    "AND chambre.NUMCHAMBRE = :numChambre";

    QSqlQuery qry;
    qry.prepare(query);
    qry.bindValue(":refBat", refBat);
    qry.bindValue(":numChambre", numChambre);


    if (qry.exec() && qry.next())
    {

        ui->resultatLabel->setText("La chambre est disponible.");
    }
    else
    {

        ui->resultatLabel->setText("La chambre n'est pas disponible.");
    }
}

void ListeChambre::on_verifierButton_clicked()
{
    verifierDisponibiliteChambre();
}

