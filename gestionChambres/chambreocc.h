#ifndef CHAMBREOCC_H
#define CHAMBREOCC_H

#include <QWidget>
#include <QSqlRelationalTableModel>

namespace Ui {
class ChambreOcc;
}

class ChambreOcc : public QWidget
{
    Q_OBJECT

public:
    explicit ChambreOcc(QWidget *parent = nullptr);
    ~ChambreOcc();

    void displayTable();
private:
    Ui::ChambreOcc *ui;
};

#endif // CHAMBREOCC_H
