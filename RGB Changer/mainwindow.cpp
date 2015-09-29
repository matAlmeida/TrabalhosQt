#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    load = new carregar;
    process = new processar;

    ui->scrollOrig->setWidget(load->imgOrig);

    ui->scrollFinal->setWidget(process->imgFinal);

    connect(ui->pushLoad, SIGNAL(clicked()), load, SLOT(slotCarregar()));
    connect(ui->pushProcess, SIGNAL(clicked()), this, SLOT(slotProcessar()));
    connect(ui->pushSave, SIGNAL(clicked()), this, SLOT(slotSalvar()));
    connect(ui->sliderR, SIGNAL(sliderMoved(int)), this, SLOT(slotSliderR(int)));
    connect(ui->sliderG, SIGNAL(sliderMoved(int)), this, SLOT(slotSliderG(int)));
    connect(ui->sliderB, SIGNAL(sliderMoved(int)), this, SLOT(slotSliderB(int)));

    red = 0;
    green = 0;
    blue = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotProcessar(){

    process->aplicar(load->imgOrig->pixmap()->toImage(), red, green, blue, load->isImage);

}


void MainWindow::slotSalvar(){

   save->wololo(process->imgFinal->pixmap()->toImage());

   QMessageBox::information(this, tr ("Salvando Imagem"), tr ("Imagem Salva com Sucesso!"));


}

void MainWindow::slotSliderR(int r){

    red = r;
}

void MainWindow::slotSliderG(int g){

    green = g;
}

void MainWindow::slotSliderB(int b){

    blue = b;
}
