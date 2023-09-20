#ifndef CALENDRIERCRUD_H
#define CALENDRIERCRUD_H


#include <QWidget>
#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>
#include <QMessageBox>

#include "database/db.h"
#include "tableDelegate/customDelegate.h"

namespace Ui {
class CalendrierCrud;
}

class CalendrierCrud : public QWidget
{
    Q_OBJECT

public:
    explicit CalendrierCrud(QWidget *parent = nullptr, Db* database = new Db());
    ~CalendrierCrud();

private:
    Ui::CalendrierCrud *ui;
};

#endif // CALENDRIERCRUD_H
