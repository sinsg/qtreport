#include "saledialog.h"
#include "ui_saledialog.h"

SaleDialog::SaleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaleDialog)
{
    ui->setupUi(this);
}

SaleDialog::~SaleDialog()
{
    delete ui;
}
