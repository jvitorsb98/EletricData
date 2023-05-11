#ifndef FRAMEEXPORTAR_H
#define FRAMEEXPORTAR_H

#include <QFrame>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_framebarras.h"


namespace Ui {
class FrameExportar;
}

class FrameExportar : public QFrame
{
    Q_OBJECT

public:
    explicit FrameExportar(QWidget *parent = nullptr, Ui::MainWindow *mw=nullptr, int numeroDeBarras=0 , int quantidadeDeLinhas = 0 , int indiceHarmonicoMax = 0  , QList<Barra> barras =  QList<Barra>() , QList<Linha> linhas= QList<Linha>() ,  Ui::FrameBarras *fb=nullptr);
    ~FrameExportar();

private slots:
    void on_btnVoltar_clicked();

    void on_btnExportar_clicked();

private:
    Ui::FrameExportar *ui;
};

#endif // FRAMEEXPORTAR_H
