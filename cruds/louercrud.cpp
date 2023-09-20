#include "louercrud.h"
#include "ui_louercrud.h"

LouerCrud::LouerCrud(QWidget *parent, Db* database) :
    QWidget(parent),
    ui(new Ui::LouerCrud)
{
    ui->setupUi(this);
}

LouerCrud::~LouerCrud()
{
    delete ui;
}
