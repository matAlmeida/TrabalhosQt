#include "carregar.h"

carregar::carregar(QWidget *parent) : QWidget(parent)
{

    isImage = false;

    imgOrig = new QLabel;
    imgOrig->setBackgroundRole(QPalette::Base);
    imgOrig->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgOrig->setScaledContents(true);

}

carregar::~carregar()
{
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

        isImage = true;
    }
}

