#ifndef CARREGAR_H
#define CARREGAR_H

#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>

class carregar : public QWidget
{
    Q_OBJECT
public:
    explicit carregar(QWidget *parent = 0);
    ~carregar();

    QLabel *imgOrig;
    QLabel *imgCop1;
    QImage *imgCop2;
    bool isImage;

signals:

public slots:
    void slotCarregar();

};

#endif // CARREGAR_H
