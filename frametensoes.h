#ifndef FRAMETENSOES_H
#define FRAMETENSOES_H

#include <QFrame>
#include "mainwindow.h"
#include "QMainWindow"
#include<ui_mainwindow.h>
#include<QObject>
#include<utility>


namespace Ui {
class FrameTensoes;
class MainWindow;
}

class FrameTensoes : public QFrame
{
    Q_OBJECT

public:
    explicit FrameTensoes(QWidget *parent = nullptr, Ui::MainWindow *mw=nullptr);
    ~FrameTensoes();
    int quantidadeDeBarras();
    bool verificaAvanco();
    static QList<double> tensoesNominais;
    void insereQssBotaoAvancar();
    void insereQssImportar();
    void insereQssBtnVoltar();
    void insereQssBtnLixeira();
    void insereQssBtnSalvar();
    inline void insereQssFrame();
    void insereTableTensoes();
    void insereQssFrameTensoes();
    static int numeroDeBarras;

private slots:


    void on_btnVoltar_clicked();

    void on_btnImportar_clicked();

    void on_btnLixeira_clicked();

    void on_btnSalvarTabela_clicked();

    void on_btnAvancar_clicked();

private:
    Ui::FrameTensoes *ui;
};

#endif // FRAMETENSOES_H
