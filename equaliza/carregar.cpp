#include "carregar.h"

carregar::carregar(QWidget *parent) : QWidget(parent)
{

    isImage = false;

    imgOrig = new QLabel;
    imgOrig->setBackgroundRole(QPalette::Base);
    imgOrig->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgOrig->setScaledContents(true);

    imgCop1 = new QLabel;
    imgCop1->setBackgroundRole(QPalette::Base);
    imgCop1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgCop1->setScaledContents(true);

}

carregar::~carregar()
{
    delete imgCop1;
    delete imgOrig;
}

void carregar::slotCarregar()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Carregar Arquivo"), QDir::currentPath());

    if(!filename.isEmpty())
    {
        QImage ibagem( filename );
        if( ibagem.isNull() ){
            QMessageBox::information(this, tr("Image Viewer"),tr("Nao foi possivel carregar %1.").arg(filename));
            return;
        }

        imgOrig -> setPixmap(QPixmap::fromImage(ibagem));
        imgOrig -> adjustSize();

        imgCop1 -> setPixmap(QPixmap::fromImage(ibagem));
        imgCop1 -> adjustSize();

        imgCop2 = ibagem.copy();

        isImage = true;
    }
}

