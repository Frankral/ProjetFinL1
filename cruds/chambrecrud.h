#ifndef CHAMBRECRUD_H
#define CHAMBRECRUD_H


#include <QWidget>
#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>
#include <QMessageBox>

#include "database/db.h"
#include "tableDelegate/customDelegate.h"

namespace Ui {
class ChambreCrud;
}

class ChambreCrud : public QWidget
{
    Q_OBJECT

public:
    explicit ChambreCrud(QWidget *parent = nullptr, Db* database = new Db());
    ~ChambreCrud();

private:
    Ui::ChambreCrud *ui;
};

#endif // CHAMBRECRUD_H
