#include "frameexportar.h"
#include "ui_frameexportar.h"
#include "style.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "framebarras.h"
#include "ui_framebarras.h"
#include <QPrinter>
#include<QPainter>
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>

Ui::MainWindow *frameMa;
Ui::FrameBarras *frameB;
QWidget *pa;



FrameExportar::FrameExportar(QWidget *parent, Ui::MainWindow *mw, Ui::FrameBarras *fb) :
    QFrame(parent),
    ui(new Ui::FrameExportar)
{
    ui->setupUi(this);

    frameMa = mw;
    pa = parent;
    frameB = fb;

    inicializaFrame();


}

void FrameExportar::inicializaFrame(){
    inserirQssFrame();
}

void FrameExportar::inserirQssFrame(){
    inserirQssImg();
    inserirQssRadioButton();
    inserirQssBtn();
}

void FrameExportar::inserirQssImg(){
    Style style;
    ui->img->setPixmap(QPixmap(":/imgExportar/imgs/descritiva/relatorio.png"));
    ui->img->setStyleSheet(style.cssImgExportar);
}

void FrameExportar::inserirQssRadioButton(){
    Style style;
    ui->radioButtonCsv->setStyleSheet(style.cssRadioButton);
    ui->radioButtonExcel->setStyleSheet(style.cssRadioButton);
    ui->radioButtonPDF->setStyleSheet(style.cssRadioButton);
}

void FrameExportar::inserirQssBtn(){
    Style style;
    ui->btnExportar->setStyleSheet(style.cssBtn);
    ui->btnExportar->setIcon(QIcon(":/icons/imgs/icons/exportar.png"));
    ui->btnExportar->setLayoutDirection(Qt::RightToLeft);
    ui->btnVoltar->setStyleSheet(style.cssBtn);
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png"));
}

FrameExportar::~FrameExportar()
{
    delete ui;
}
void FrameExportar::on_btnVoltar_clicked()
{
    MainWindow::frameAtual = 2; //subtrai de 1 a variavel que conta em qua frame o usuario está
    MainWindow::atualizarStatus(frameMa); //atualiza a Barra de Status

    pa->show(); // mostra o Frame Anterior
    this->close(); //Fecha o frame atual

}
void FrameExportar::on_btnExportar_clicked()
{

    QString nome = QDir::currentPath()+"/arquivo.pdf";
    if(ui->radioButtonPDF->isChecked()){
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(nome);
        QPainter painter;
        if(!painter.begin(&printer)){
            QMessageBox::warning(this,"Erro","Arquivo não pôde ser criado "); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
            return;
        }
        int linha = 25;
        int coluna = 25;

        if(FiltrosBarra::indexComboBox == 0 ){
            int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
            int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;

            for(int i = inicio ; i < fim ; i++){
                painter.drawText(coluna,linha,"Barra "+QString::number(i+1));
                linha +=20;
                if(FiltrosBarra::tensaoPu){
                    painter.drawText(coluna+40,linha,"Tensão na Barra [pu] : "+QString::number(FrameBarras::barras[i].getTensaoPu()));
                    linha +=20;
                }
                if(FiltrosBarra::tensaoNominal){
                    painter.drawText(coluna+40,linha,"Tensão Nominal [kV] : "+QString::number(FrameBarras::barras[i].getTensaoNominalKv()));
                    linha +=20;
                }
                if(FiltrosBarra::thdv){
                    painter.drawText(coluna+40,linha,"THDV[%] : "+QString::number(FrameBarras::barras[i].getThdvPercent()));
                    linha +=20;
                }
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FiltrosBarra::dit){
                        painter.drawText(coluna+40,linha,"DIT"+QString::number(j)+" : "+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first));
                        linha +=20;
                    }
                }
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FiltrosBarra::ditPercent){
                        painter.drawText(coluna+40,linha,"DIT"+QString::number(j)+"[%] : "+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second));
                        linha +=20;
                    }
                }
                if(FiltrosBarra::tensaoEficaz){
                    painter.drawText(coluna+40,linha,"Tensao Eficaz : "+QString::number(FrameBarras::barras[i].getTensaoEficaz()));
                }
                linha+=20;
                painter.drawText(coluna+40,linha,"Observações : ");
                linha+=20;
                if(FrameBarras::barras[i].getBarraInfectadaThdv()){
                    if(FrameBarras::barras[i].getTensaoNominalKv() < 2.3){
                        painter.drawText(coluna+120,linha,"THDV[%] acima do limite regulamentado pelo Prodist , limite máximo de 10% para este nível de tensão ");
                        linha+=20;
                    }else if(FrameBarras::barras[i].getTensaoNominalKv() >= 2.3 && FrameBarras::barras[i].getTensaoNominalKv() < 69){
                        painter.drawText(coluna+120,linha,"THDV[%] acima do limite regulamentado pelo Prodist , limite máximo de 8% para este nível de tensão ");
                        linha+=20;
                    }else{
                        painter.drawText(coluna+120,linha,"THDV[%] acima do limite regulamentado pelo Prodist , limite máximo de 5% para este nível de tensão ");
                        linha+=20;                    }
                }else{
                    painter.drawText(coluna+120,linha,"THDV[%] dentro dos limites regulamentados pelo Prodist");
                    linha+=20;
                }
                if(FiltrosBarra::ditPercent || FiltrosBarra::dit){
                    for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2 ){
                        if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                            painter.drawText(coluna+120,linha,"TDI"+QString::number(j)+"[%] acima do limite regulamentado pelo Prodist , limite máximo de "+QString::number(FrameBarras::getLimitesDti()[FrameBarras::barras[i].getClasseTensaoThdv()][j])+"% para este nível de tensão ");
                        }else{
                            painter.drawText(coluna+120,linha,"TDI"+QString::number(j)+"[%] dentro dos limites regulamentados pelo Prodist");
                    }
                    linha +=20;
                    }
                }

            }
        }
        painter.end();

        QDesktopServices::openUrl(QUrl("file:///"+nome));


    }
}

