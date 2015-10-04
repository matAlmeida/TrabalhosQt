#include "processar.h"

processar::processar(QWidget *parent) : QWidget(parent)
{

    imgFinal = new QLabel;
    imgFinal->setBackgroundRole(QPalette::Base);
    imgFinal->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgFinal->setScaledContents(true);

    imgFinalCopy = new QImage;

}

processar::~processar()
{

    delete imgFinal;

}

void processar::aplicar(QImage tempImg, int brilho, bool isImage){


    if(isImage)
    {
        QColor tempColor;
        QRgb   cor;
        //int r, g, b;
        int cinza;

        if (tempImg.isGrayscale()){
            for(int i = 0; i < tempImg.width(); i++){
                for(int j = 0; j < tempImg.height(); j++){
                    tempColor = tempImg.pixel(i,j);

                    cinza = 255 - (brilho + tempColor.black());

                    if (cinza > 255)
                        cinza = 255;
                    else if(cinza < 0)
                        cinza = 0;

                    cor = qRgb(cinza, cinza, cinza);
                    tempImg.setPixel(i, j, cor);

                } //Final For Altura

            } //Final For Largura

            imgFinal -> setPixmap(QPixmap::fromImage(tempImg));
            imgFinal -> adjustSize();

            imgFinalCopy = imgFinal->pixmap()->toImage();

        } //Final do If greyScale

        /*for(int i = 0; i < tempImg.width(); i++){
            for(int j = 0; j < tempImg.height(); j++){

                tempColor = tempImg.pixel(i,j);

                r = brilho + tempColor.red();
                g = brilho + tempColor.green();
                b = brilho + tempColor.blue();

                if (r > 255)
                    r = 255;
                else if (r < 0)
                    r = 0;

                if (g > 255)
                    g = 255;
                else if (g < 0)
                    g = 0;

                if (b > 255)
                    b = 255;
                else if (b < 0)
                    b = 0;

                cor = qRgb(r, g, b);
                tempImg.setPixel(i, j, cor);
            }
        } */


    }
}

