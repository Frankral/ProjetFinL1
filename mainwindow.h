#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>
#include <QMessageBox>

#include "database/db.h"
#include "tableDelegate/customDelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayTable();
    void resetTable();
    void fillInputChange(QTableView* qv, QModelIndexList indexes);
    bool addNewEtudiant(QString numEt, QString nomEt, QString prenomEt, QString numTel);

private slots:

    void on_modifierButton_clicked();

    void on_supprimerButton_clicked();

    void on_ajoutButton_clicked();

private:
    Db* mydb = new Db;
    Ui::MainWindow *ui;

    void on_table_value_change(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);
    void on_row_selected(const QItemSelection &selected, const QItemSelection &deselected);
};
#endif // MAINWINDOW_H
