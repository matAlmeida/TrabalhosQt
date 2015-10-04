#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    load = new carregar;
    process = new processar;
    escalaCinza = new int[256];

    ui->setupUi(this);

    connect(ui->pushCarregar, SIGNAL(clicked()), load, SLOT(slotCarregar()));
    connect(ui->sliderBrilho, SIGNAL(sliderMoved(int)), this, SLOT(slotBrilho(int)));
    connect(ui->pushHistograma, SIGNAL(clicked()), this, SLOT(slotGrafico()));

    ui->widgetGrafico->xAxis->setLabel("Escala");
    ui->widgetGrafico->yAxis->setLabel("Qntd");
    ui->widgetGrafico->xAxis->setRange(0, 255);
    ui->widgetGrafico->yAxis->setRange(0, 1000);

    ui->scrollImagem->setWidget(load->imgCop1);

}

MainWindow::~MainWindow()
{
    delete escalaCinza;
    delete load;
    delete process;
    delete ui;
}

void MainWindow::slotBrilho(int brilho){

    process->aplicar(load->imgOrig->pixmap()->toImage(), brilho, load->isImage);

    load->imgCop1->setPixmap(QPixmap::fromImage(process->imgFinal->pixmap()->toImage()));

}

void MainWindow::slotGrafico(){

    if(load->isImage){

        QVector<double> x(256), y(256);
        criaEscala(process->imgFinalCopy);

        for(int i = 0; i < 256; i++){
            x[i] = i;
            y[i] = escalaCinza[i];
        }

        ui->widgetGrafico->addGraph();
        ui->widgetGrafico->graph(0)->setData(x, y);
        ui->widgetGrafico->replot();

    }

}

void MainWindow::criaEscala(QImage imagem){

    QColor tempColor;
    int cinza;

    limpaEscala();

    if(imagem.isGrayscale()){

        for (int i = 0; i < imagem.width(); i++){
            for (int j = 0; j < imagem.height(); j++){

                tempColor = imagem.pixel(i, j);
                cinza = 255 - tempColor.black();
                escalaCinza[cinza]++;

            }
        }

    }
}

void MainWindow::limpaEscala(){

    for(int i = 0; i < 256; i++)
        escalaCinza[i] = 0;

}
