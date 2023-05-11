#ifndef FRAMEBARRAS_H
#define FRAMEBARRAS_H

#include <QFrame>
#include "ui_frametensoes.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "frametensoes.h"
#include "Barra.h"
#include "Linha.h"
#include "filtrosbarra.h"
#include "ui_filtrosbarra.h"
#include "filtrolinha.h"
#include "ui_filtrolinha.h"

namespace Ui {
class FrameBarras;
}

class FrameBarras : public QFrame
{
    Q_OBJECT

public:
    explicit FrameBarras(QWidget *parent = nullptr, Ui::MainWindow *mw=nullptr,Ui::FrameTensoes *ft=nullptr);
    ~FrameBarras();
    int buscaIndiceHarmMax();
    inline int buscaQtdHarm(int );
    int quantidadeDeBarras();
    static int indexTab;
    QStringList cabecalhoBarras(int);
    QStringList cabecalhoLinhas(int);
    QList<Barra> preencheBarra(QList<Barra> ,int, int );
    QList<Barra> inicializaBarra(QList<Barra>,int );
    QStringList linhasDoSistema();
    inline double potencia(double , int );
    void insereQssBtnAvancar();
    void insereQssBtnVoltar();
    void insereQssTabWidget();
    void insereQssTableBarras();
    void insereQssTableLinhas(int ,int );
    void insereQssTableBarras(int, int);
    void insereQssFrameBarras(int , int);
    void preencheTabela(QList<Barra> , int , int );
    void preencheTabela(QList<Linha>, int , int );
    void preencheLimites();
    void insereQSSBtnFiltrar();
    QList<Linha> preencheLinha(QList<Linha>, int , int );
    QList<Linha> inicializaLinha(QList<Linha>, int );
    std::map<int , std::map<int , double >> getLimitesDti(){
        return limitesDti;
    }

    void setLimitesDti(int nivelTensao , int harmonica , double limite){
        limitesDti[nivelTensao][harmonica] = limite;
    }
    void insereBackgroundNasPoluidoras(int , int  , QList<Barra> );
    void atualizarRowBarras();
    void atualizarColumnBarras();

private slots:


    void on_btnFiltrar_clicked();

    void on_tabLinhas_currentChanged(int index);

    void on_btnVoltar_clicked();

private:
    Ui::FrameBarras *ui;
    std::map<int , std::map<int , double >> limitesDti;
};

#endif // FRAMEBARRAS_H
