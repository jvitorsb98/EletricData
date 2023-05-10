
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<ui_mainwindow.h>
#include "style.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void atualizarStatus(Ui::MainWindow *ui){
        Style style;
        switch(frameAtual){
        case 0:
            ui->txtCarregarArquivos->setStyleSheet(style.cssTxtSelected);
            ui->txtTensoesNasBarras->setStyleSheet(style.cssTxt);
            ui->txtPrepararSaida->setStyleSheet(style.cssTxt);
            ui->txtExportar->setStyleSheet(style.cssTxt);
            ui->lblVerifica1->hide();
            ui->lblVerifica2->hide();
            ui->lblVerifica3->hide();
            ui->lblVerifica4->hide();
            break;
        case 1:
            ui->txtCarregarArquivos->setStyleSheet(style.cssTxt);
            ui->txtTensoesNasBarras->setStyleSheet(style.cssTxtSelected);
            ui->txtPrepararSaida->setStyleSheet(style.cssTxt);
            ui->txtExportar->setStyleSheet(style.cssTxt);
            ui->lblVerifica1->show();
            ui->lblVerifica2->hide();
            ui->lblVerifica3->hide();
            ui->lblVerifica4->hide();
            break;
        case 2:
            ui->txtCarregarArquivos->setStyleSheet(style.cssTxt);
            ui->txtTensoesNasBarras->setStyleSheet(style.cssTxt);
            ui->txtPrepararSaida->setStyleSheet(style.cssTxtSelected);
            ui->txtExportar->setStyleSheet(style.cssTxt);
            ui->lblVerifica1->show();
            ui->lblVerifica2->show();
            ui->lblVerifica3->hide();
            ui->lblVerifica4->hide();
            break;
        case 3:
            ui->txtCarregarArquivos->setStyleSheet(style.cssTxt);
            ui->txtTensoesNasBarras->setStyleSheet(style.cssTxt);
            ui->txtPrepararSaida->setStyleSheet(style.cssTxt);
            ui->txtExportar->setStyleSheet(style.cssTxtSelected);
            ui->lblVerifica1->show();
            ui->lblVerifica2->show();
            ui->lblVerifica3->show();
            ui->lblVerifica4->hide();
            break;
        }
    }

    void insereCssMainWindow();
    void insereIcon();
    void insereQssBarraDeStatus();
    void verificarAvanco();
    void insereQssTitulosLineEdit();
    void insereQssLineEdit();
    void insereQssPlaceHolderLineEdit();
    void insereQssBtnArquivos();
    void insereQssBtnAvancar();
    void insereQssBtnLixeira();
    void insereQssLblVerifica();
    void setaFileNameNosArq();


    static QFile *arquivoVsoln;
    static QFile *arquivoIsoln;
    static QFile *arquivoThdi;
    static QFile *arquivoThdv;
    static QFile *arquivoLdat;
    static QFile *arquivoTensoes;
    static int frameAtual;
    bool getStatusDePreenchimento(int posicao){
        if(posicao < 5 && posicao >=0){
            return statusDePreenchimento[posicao];
        }
        else{
            return false;
        }
    }
    void setStatusDePreenchimento(int posicao, bool status){
        if(posicao < 5 && posicao >=0){
            statusDePreenchimento[posicao]=status;
        }
    }


private slots:
    void on_btnAvancar_clicked();

    void on_btnVsoln_clicked();

    void on_btnThdv_clicked();

    void on_btnThdi_clicked();

    void on_btnIsoln_clicked();

    void on_btnLdat_clicked();

    void on_btnLixeiraVsoln_clicked();

    void on_btnLixeiraThdv_clicked();

    void on_btnLixeiraThdi_clicked();

    void on_btnLixeiraIsoln_clicked();

    void on_btnLixeiraLdat_clicked();

private:
    Ui::MainWindow *ui;
    bool statusDePreenchimento[5]{0};



    //Metodo para atualizar a barra de Status

};





#endif // MAINWINDOW_H
