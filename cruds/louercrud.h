#ifndef LOUERCRUD_H
#define LOUERCRUD_H

#include <QWidget>
#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>
#include <QMessageBox>

#include "database/db.h"
#include "tableDelegate/customDelegate.h"

namespace Ui {
class LouerCrud;
}

class LouerCrud : public QWidget
{
    Q_OBJECT

public:
    explicit LouerCrud(QWidget *parent = nullptr, Db* database = new Db());
    ~LouerCrud();

private:
    Ui::LouerCrud *ui;
};

#endif // LOUERCRUD_H
