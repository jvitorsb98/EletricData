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
int numDeBarras;
int numDeLinhas;
int HarmMax;
QList<Barra> b;
QList<Linha> l;


FrameExportar::FrameExportar(QWidget *parent, Ui::MainWindow *mw, int numeroDeBarras , int quantidadeDeLinhas , int indiceHarmonicoMax , QList<Barra> barra , QList<Linha> linha,  Ui::FrameBarras *fb) :
    QFrame(parent),
    ui(new Ui::FrameExportar)
{
    ui->setupUi(this);

    Style style;
    frameMa = mw;
    pa = parent;
    numDeBarras = numeroDeBarras;
    numDeLinhas = quantidadeDeLinhas;
    HarmMax = indiceHarmonicoMax;
    b = barra;
    l = linha;
    frameB = fb;

    ui->btnExportar->setStyleSheet(style.cssBtn);
    ui->img->setPixmap(QPixmap(":/imgExportar/imgs/descritiva/relatorio.png"));
    ui->img->setStyleSheet(style.cssImgExportar);
    ui->radioButtonCsv->setStyleSheet(style.cssRadioButton);
    ui->radioButtonExcel->setStyleSheet(style.cssRadioButton);
    ui->radioButtonPDF->setStyleSheet(style.cssRadioButton);
    ui->btnVoltar->setStyleSheet(style.cssBtn);
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png"));
    ui->btnExportar->setIcon(QIcon(":/icons/imgs/icons/exportar.png"));
    ui->btnExportar->setLayoutDirection(Qt::RightToLeft);


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
                    painter.drawText(coluna+40,linha,"Tensão na Barra [pu] : "+frameB->tableBarras->item(0,i)->text());
                    linha +=20;
                }
                if(FiltrosBarra::tensaoNominal){
                    painter.drawText(coluna+40,linha,"Tensão Nominal [kV] : "+frameB->tableBarras->item(1,i)->text());
                    linha +=20;
                }
                if(FiltrosBarra::thdv){
                    painter.drawText(coluna+40,linha,"THDV [%] : "+frameB->tableBarras->item(2,i)->text());
                    linha +=20;
                }
                int cont=3;
                for(int j = 3 ; j <= HarmMax ; j+=2 ){
                    if(FiltrosBarra::dit){
                        painter.drawText(coluna+40,linha,"DIT"+QString::number(j)+" : "+frameB->tableBarras->item(cont,i)->text());
                        linha +=20;
                    }
                    cont++;
                }
                for(int j = 3 ; j <= HarmMax ; j+=2 ){
                    if(FiltrosBarra::ditPercent){
                        painter.drawText(coluna+40,linha,"DIT"+QString::number(j)+"[%] : "+frameB->tableBarras->item(cont,i)->text());
                        linha +=20;
                    }
                    cont++;
                }
                if(FiltrosBarra::tensaoEficaz){
                    painter.drawText(coluna+40,linha,"Tensao Eficaz : "+frameB->tableBarras->item(cont,i)->text());
                }
                linha+=20;
                painter.drawText(coluna+40,linha,"Observações : ");
                linha+=20;
                if(frameB->tableBarras->item(2,i)->background() == QColor(255, 128, 128)){
                    if(frameB->tableBarras->item(1,i)->text().toDouble() < 2.3){
                        painter.drawText(coluna+120,linha,"THDV[%] acima do limite regulamentado pelo Prodist , limite máximo de 10% para este nível de tensão ");
                        linha+=20;
                    }else if(frameB->tableBarras->item(1,i)->text().toDouble() >= 2.3 && frameB->tableBarras->item(1,i)->text().toDouble() < 69){
                        painter.drawText(coluna+120,linha,"THDV[%] acima do limite regulamentado pelo Prodist , limite máximo de 8% para este nível de tensão ");
                        linha+=20;
                    }else{
                        painter.drawText(coluna+120,linha,"THDV[%] acima do limite regulamentado pelo Prodist , limite máximo de 5% para este nível de tensão ");
                        linha+=20;                    }
                }else{
                    painter.drawText(coluna+120,linha,"THDV[%] dentro dos limites regulamentados pelo Prodist");
                    linha+=20;
                }
                cont = 3 ;
                for(int j = 3 ; j <= HarmMax ; j+=2 ){
                    cont++;
                }
//                if(FiltrosBarra::ditPercent || FiltrosBarra::dit){
//                    int nivelDeTensao;
//                    for(int j = 3 ; j <= HarmMax ; j+=2 ){
//                        if(frameB->tableBarras->item(1,i)->text().toDouble() <= 1){
//                            nivelDeTensao=1;
//                        }else if(frameB->tableBarras->item(1,i)->text().toDouble() > 1 && frameB->tableBarras->item(1,i)->text().toDouble() <= 13.8){
//                            nivelDeTensao =2;
//                        }else if(frameB->tableBarras->item(1,i)->text().toDouble() > 13.8 && frameB->tableBarras->item(1,i)->text().toDouble() <= 69){
//                            nivelDeTensao = 3;
//                        }else{
//                            nivelDeTensao = 4;
//                        }
//                        if(frameB->tableBarras->item(cont,i)->text().toDouble() > FrameBarras::limitesDti){
//                            painter.drawText(coluna+120,linha,"TDI"+QString::number(j)+"[%] acima do limite regulamentado pelo Prodist , limite máximo de "+QString::number(FrameBarras::getLimitesDti().find(j)->second.find(nivelDeTensao)->second)+"% para este nível de tensão ");
//                        }else{
//                            painter.drawText(coluna+120,linha,"TDI"+QString::number(j)+"[%] dentro dos limites regulamentados pelo Prodist");
//                        }
//                        linha +=20;
//                        cont++;
//                    }
//                }

            }
        }
        painter.end();

        QDesktopServices::openUrl(QUrl("file:///"+nome));


    }
}

