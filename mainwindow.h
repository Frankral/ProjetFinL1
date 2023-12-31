#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "cruds/etudiantcrud.h"
#include "cruds/batimentcrud.h"
#include "cruds/calendriercrud.h"
#include "cruds/chambrecrud.h"
#include "cruds/louercrud.h"

#include "gestionChambres//listechambre.h"
#include "gestionChambres/chambreocc.h"

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

private slots:
    void on_actionEtudiant_triggered();

    void on_actionBatiment_triggered();

    void on_actionCalendrier_triggered();

    void on_actionChambre_triggered();

    void on_actionLouer_triggered();

    void on_actionhistorique_de_chambre_triggered();

    void on_actionListe_des_Chambres_Occup_es_triggered();

    void on_crudBat_clicked();

    void on_crudCal_clicked();

    void on_crudChamb_clicked();

    void on_crudEt_clicked();

    void on_crudLouer_clicked();

    void on_ListeChambre_clicked();

    void on_ListeOccupee_clicked();

private:
    Db* mydb = new Db;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
