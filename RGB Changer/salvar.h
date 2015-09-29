#ifndef SALVAR_H
#define SALVAR_H

#include <QWidget>

class salvar : public QWidget
{
    Q_OBJECT
public:
    explicit salvar(QWidget *parent = 0);
    ~salvar();

    void wololo(QImage);

signals:

public slots:
};

#endif // SALVAR_H
