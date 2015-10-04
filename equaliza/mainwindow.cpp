#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    load = new carregar;
    process = new processar;

    ui->setupUi(this);

    connect(ui->pushCarregar, SIGNAL(clicked()), load, SLOT(slotCarregar()));
    connect(ui->sliderBrilho, SIGNAL(sliderMoved(int)), this, SLOT(slotBrilho(int)));

    ui->scrollImagem->setWidget(load->imgCop1);

}

MainWindow::~MainWindow()
{
    delete load;
    delete process;
    delete ui;
}

void MainWindow::slotBrilho(int brilho){

    process->aplicar(load->imgOrig->pixmap()->toImage(), brilho, load->isImage);

    load->imgCop1->setPixmap(QPixmap::fromImage(process->imgFinal->pixmap()->toImage()));

}
