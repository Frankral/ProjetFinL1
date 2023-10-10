#ifndef LISTECHAMBRE_H
#define LISTECHAMBRE_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>

#include "database/db.h"
#include "historique/historiquechambre.h"

namespace Ui {
class ListeChambre;
}

class ListeChambre : public QWidget
{
    Q_OBJECT

public:
    explicit ListeChambre(QWidget *parent = nullptr, Db* database = new Db());
    ~ListeChambre();
    void displayTable();

    void verifierDisponibiliteChambre();

private slots:
    void on_searchInput_textEdited(const QString &arg1);

    void on_voirButton_clicked();

    void on_verifierButton_clicked();

    void handleSectionClicked(int logicalIndex);

private:
    Db* mydb;
    Ui::ListeChambre *ui;

    void on_row_selected(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif // LISTECHAMBRE_H
