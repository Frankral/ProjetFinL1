#include "calendriercrud.h"
#include "ui_calendriercrud.h"

CalendrierCrud::CalendrierCrud(QWidget *parent, Db* database) :
    QWidget(parent),
    ui(new Ui::CalendrierCrud)
{
    ui->setupUi(this);
}

CalendrierCrud::~CalendrierCrud()
{
    delete ui;
}
