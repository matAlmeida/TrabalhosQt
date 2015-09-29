#include "processar.h"

processar::processar(QWidget *parent) : QWidget(parent)
{

    imgFinal = new QLabel;
    imgFinal->setBackgroundRole(QPalette::Base);
    imgFinal->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgFinal->setScaledContents(true);

}

processar::~processar()
{

    delete imgFinal;

}

void processar::aplicar(QImage tempImg, int red, int green, int blue, bool isImage){


    if(isImage)
    {
        QColor tempColor;
        QRgb   cor;
        int r, g, b;
       // int controleR = 1, controleG = 1, controleB = 1;

        for(int i = 0; i < tempImg.width(); i++){
            for(int j = 0; j < tempImg.height(); j++){

                tempColor = tempImg.pixel(i,j);

                r = red + tempColor.red();
                g = green + tempColor.green();
                b = blue + tempColor.blue();

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
        }

        imgFinal -> setPixmap(QPixmap::fromImage(tempImg));
        imgFinal -> adjustSize();
    }
}

