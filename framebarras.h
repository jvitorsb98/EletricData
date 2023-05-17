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
    static int indexTab;
    static int indiceHarmMax;
    static int numeroDeLinhas;
    static int quantidadeDeComponentesHarm;
    void preencheFrameBarras();
    void inicializaVariaveisStatic();
    void inicializaFrame();
    QStringList cabecalhoBarras();
    QStringList cabecalhoLinhas();
    void preencheBarra();
    void inicializaBarra();
    QStringList linhasDoSistema();
    inline double potencia(double , int );
    void insereQssBtnAvancar();
    void insereQssBtnVoltar();
    void insereQssTabWidget();
    void insereQssTableBarras();
    void insereQssTableLinhas();
    void insereQssFrameBarras();
    void preencheTabelaBarra();
    void preencheTabelaLinha();
    void preencheLimites();
    static QList<Barra> barras;
    static QList<Linha> linhas;
    void insereQSSBtnFiltrar();
    void preencheLinha();
    void inicializaLinha();
    static bool filtroLinhaInserido;
    static bool filtroBarraInserido;
    static std::map<int , std::map<int , double >> getLimitesDti(){
        return limitesDti;
    }

    static void setLimitesDti(int nivelTensao , int harmonica , double limite){
        limitesDti[nivelTensao][harmonica] = limite;
    }


    void insereBackgroundNasPoluidoras();
    void verificaAvanco();

private slots:


    void on_btnFiltrar_clicked();

    inline void on_tabLinhas_currentChanged(int index);

    void on_btnVoltar_clicked();

    void on_btnAvancar_clicked();

private:
    Ui::FrameBarras *ui;
    static std::map<int , std::map<int , double >> limitesDti;

};

#endif // FRAMEBARRAS_H
