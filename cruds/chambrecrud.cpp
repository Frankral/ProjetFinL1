#include "chambrecrud.h"
#include "ui_chambrecrud.h"

ChambreCrud::ChambreCrud(QWidget *parent, Db* database) :
    QWidget(parent),
    ui(new Ui::ChambreCrud)
{
    ui->setupUi(this);
}

ChambreCrud::~ChambreCrud()
{
    delete ui;
}
