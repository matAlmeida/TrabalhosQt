#include "salvar.h"

salvar::salvar(QWidget *parent) : QWidget(parent)
{

}

salvar::~salvar()
{

}

void salvar::wololo(QImage imgFinal){

   imgFinal.save("IMGdoPOJ.png");

}
