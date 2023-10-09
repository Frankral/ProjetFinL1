#ifndef HISTORIQUECHAMBRE_H
#define HISTORIQUECHAMBRE_H

#include <QDialog>

namespace Ui {
class historiqueChambre;
}

class historiqueChambre : public QDialog
{
    Q_OBJECT

public:
    explicit historiqueChambre(QWidget *parent = nullptr);
    ~historiqueChambre();

private:
    Ui::historiqueChambre *ui;
};

#endif // HISTORIQUECHAMBRE_H
