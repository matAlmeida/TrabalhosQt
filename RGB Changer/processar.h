#ifndef PROCESSAR_H
#define PROCESSAR_H

#include <QWidget>
#include <QLabel>

class processar : public QWidget
{
    Q_OBJECT
public:
    explicit processar(QWidget *parent = 0);
    ~processar();

    QLabel *imgFinal;
    void aplicar(QImage, int , int , int , bool);

signals:

public slots:
};

#endif // PROCESSAR_H
