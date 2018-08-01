#ifndef SALEDIALOG_H
#define SALEDIALOG_H

#include <QDialog>

namespace Ui {
class SaleDialog;
}

class SaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaleDialog(QWidget *parent = 0);
    ~SaleDialog();

private:
    Ui::SaleDialog *ui;
};

#endif // SALEDIALOG_H
