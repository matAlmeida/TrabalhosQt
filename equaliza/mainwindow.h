#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "carregar.h"
#include "processar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    carregar *load;
    processar *process;

private:
    Ui::MainWindow *ui;

public slots:
    void slotBrilho(int);
};

#endif // MAINWINDOW_H
