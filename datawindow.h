#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QMainWindow>

namespace Ui {
class DataWindow;
}

class DataWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataWindow(QWidget *parent = 0);
    ~DataWindow();

private:
    Ui::DataWindow *ui;
};

#endif // DATAWINDOW_H
