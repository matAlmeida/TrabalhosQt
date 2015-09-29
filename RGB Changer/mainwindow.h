#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QFileDialog>
#include <QMessageBox>
#include "carregar.h"
#include "processar.h"
#include "salvar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int red;
    int green;
    int blue;
    processar *process;
    carregar *load;
    salvar *save;

private:
    Ui::MainWindow *ui;

public slots:
    void slotProcessar();
    void slotSalvar();
    void slotSliderR(int );
    void slotSliderG(int );
    void slotSliderB(int );

};

#endif // MAINWINDOW_H
