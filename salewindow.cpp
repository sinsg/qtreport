#include "salewindow.h"
#include "ui_salewindow.h"

SaleWindow::SaleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaleWindow)
{
    ui->setupUi(this);
}

SaleWindow::~SaleWindow()
{
    delete ui;
}
