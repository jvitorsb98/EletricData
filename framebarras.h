#ifndef FRAMEBARRAS_H
#define FRAMEBARRAS_H

#include <QFrame>
#include "ui_frametensoes.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "frametensoes.h"
#include "filtrosbarra.h"
#include "ui_filtrosbarra.h"
#include "filtrolinha.h"
#include "ui_filtrolinha.h"
#include "Barra.h"
#include "Linha.h"

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
    static int indiceHarmMax;
    static int numeroDeLinhas;
    static int quantidadeDeComponentesHarm;

    QStringList cabecalhoBarras();
    QStringList cabecalhoLinhas();
    QList<Barra> preencheBarra(QList<Barra>);
    QList<Barra> inicializaBarra(QList<Barra> );
    QStringList linhasDoSistema();
    inline double potencia(double , int );
    void insereQssBtnAvancar();
    void insereQssBtnVoltar();
    void insereQssTabWidget();
    void insereQssTableBarras();
    void insereQssTableLinhas();
    void insereQssFrameBarras();
    void preencheTabela(QList<Barra>);
    void preencheTabela(QList<Linha>);
    void preencheLimites();
    static QList<Barra> barras;
    static QList<Linha> linhas;
    void insereQSSBtnFiltrar();
    QList<Linha> preencheLinha(QList<Linha>);
    QList<Linha> inicializaLinha(QList<Linha>);
     std::map<int , std::map<int , double >> getLimitesDti(){
        return limitesDti;
    }

     void setLimitesDti(int nivelTensao , int harmonica , double limite){
        limitesDti[nivelTensao][harmonica] = limite;
    }

    void insereBackgroundNasPoluidoras(QList<Barra> );
    void atualizarRowBarras();
    void atualizarColumnBarras();

private slots:


    void on_btnFiltrar_clicked();

    void on_tabLinhas_currentChanged(int index);

    void on_btnVoltar_clicked();

    void on_btnAvancar_clicked();

private:
    Ui::FrameBarras *ui;
    std::map<int , std::map<int , double >> limitesDti;

};

#endif // FRAMEBARRAS_H
