#ifndef HISTORIQUECHAMBRE_H
#define HISTORIQUECHAMBRE_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

namespace Ui {
class historiqueChambre;
}

class historiqueChambre : public QDialog
{
    Q_OBJECT

public:
    explicit historiqueChambre(QWidget *parent = nullptr, QString refbat = QString(), QString numChambre = QString());
    ~historiqueChambre();

    void displayTable();
private slots:
    void on_pushButton_clicked();

private:
    QString refbat;
    QString numChambre;
    Ui::historiqueChambre *ui;
};

#endif // HISTORIQUECHAMBRE_H
