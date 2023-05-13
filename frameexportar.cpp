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
#include <QFileDialog>
#include <QDebug>


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
    ui->radioButtonPDF->setChecked(true);
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

    if(ui->radioButtonPDF->isChecked()){
        if(FiltrosBarra::indexComboBox == 0 ){
            imprimirPdfIntervaloBarras();
        }else if(FiltrosBarra::indexComboBox == 1){
            imprimirPdfCombonentesBarras();
        }else{
            imprimirPdfBarrasInfectadas();
        }
    }else if(ui->radioButtonCsv->isChecked()){
        if(FiltrosBarra::indexComboBox == 0 ){
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                CsvInterBarrasTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                CsvInterBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                CsvInterBarrasTodL1InterL2();
            }else{
                CsvInterBarrasInterL1InterL2();
            }
        }else if(FiltrosBarra::indexComboBox == 1 ){
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                CsvCompBarrasaTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                CsvCompBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                CsvCompBarrasTodL1InterL2();
            }else{
                CsvCompBarrasInterL2InterL2();
            }
        }else{
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                CsvInfecBarrasTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                CsvInfecBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                CsvInfecBarrasTodL1InterL2();
            }else{
                CsvInfecBarrasInterL1InterL2();
            }
        }
    }else{
        if(FiltrosBarra::indexComboBox == 0 ){
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                ExcelInterBarrasTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                ExcelInterBInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                ExcelInterBarrasTodL1InterL2();
            }else{
                ExcelInterBInterL1InterL2();
            }
        }else if(FiltrosBarra::indexComboBox == 1 ){
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                ExcelCompBarrasaTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                ExcelCompBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                ExcelCompBarrasTodL1InterL2();
            }else{
                ExcelCompBarrasInterL2InterL2();
            }
        }else{
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                ExcelvInfecBarrasTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                ExcelInfecBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                ExcelInfecBarrasTodL1InterL2();
            }else{
                ExcelInfecBarrasInterL1InterL2();
            }
        }
    }
}
void FrameExportar::imprimirPdfIntervaloBarras(){
    QString nome = QDir::currentPath()+"/arquivo.pdf";
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
    painter.end();
    QDesktopServices::openUrl(QUrl("file:///"+nome));


}
void FrameExportar::imprimirPdfCombonentesBarras(){

    QString nome = QDir::currentPath()+"/arquivo.pdf";
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
    int i ;
    for (auto it = FiltrosBarra::indiceBarrasEscolhidas.begin(); it != FiltrosBarra::indiceBarrasEscolhidas.end(); it++) {
        QString barra = *it;
        i = barra.toInt()-1;
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
    painter.end();
    QDesktopServices::openUrl(QUrl("file:///"+nome));


}
void FrameExportar::imprimirPdfBarrasInfectadas(){
    QString nome = QDir::currentPath()+"/arquivo.pdf";
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
    bool infectada;
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        infectada = false;
        if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                }
            }
        }else{
            infectada = true;
        }
        if(infectada){
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

//--------------Funções Excel
//Funções para imprimir excel com barras em intervalo
void FrameExportar::ExcelInterBInterL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha , linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1InterL2(planilha , linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelInterBInterL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha , linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1TodL2(planilha , linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelInterBarrasTodL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha ,linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1InterL2(planilha , linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelInterBarrasTodL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
//Funções para imprimir Excel com barras em componentes
void FrameExportar::ExcelCompBarrasInterL2InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelCompBarrasInterL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelCompBarrasTodL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelCompBarrasaTodL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
//Funções de para imprimir Excel com barras infectadas
void FrameExportar::ExcelInfecBarrasInterL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelInfecBarrasInterL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelInfecBarrasTodL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
void FrameExportar::ExcelvInfecBarrasTodL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}
//Funções Auxiliares
//Cria planilha
QXlsx::Document* FrameExportar::criaPlanilha(){
        QXlsx::Document* planilha = new QXlsx::Document;
        return planilha;
}
//Pua linha entre as barras e as linhas
void FrameExportar::ExcelPulaLinha(int* linha){
        for(int i = 0 ; i < 4 ; i++){
        (*linha)++;
        }
}
//Salva a planilha
void FrameExportar::salvaPlanilha(QXlsx::Document* saida){
    QString filtro="Arquivo de planilha Excel. (*.xlsx)";
    QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
    saida->saveAs(localSalvamento);
}
//escreve as barras em intervalo
void FrameExportar::ExcelEscreveBarrasIntervalo(QXlsx::Document* saida, int* linha ){
        int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
        int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
        //Barras
        saida->write("A1","Barra");
        for(int i= inicio , pos = 1 ; i <= fim ; i++, pos++){
            saida->write(QString(numeroParaLetra(pos+1))+"1",QString::number(i+1));
        }
        *linha = 2;
        if(FiltrosBarra::tensaoPu){
            saida->write("A"+QString::number(*linha),"Tensão na Barra[pu]");
            int pos =1 ;
            for(int i= inicio ; i <= fim ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5));
                    pos++;
            }
            (*linha)++;
        }
        if(FiltrosBarra::tensaoNominal){
            saida->write("A"+QString::number(*linha),"Tensão Nominal[kV]");
                int pos =1 ;
            for(int i= inicio ; i <= fim ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5));
                pos++;
            }
            (*linha)++;
        }
        if(FiltrosBarra::thdv){
            saida->write("A"+QString::number(*linha),"THDV[%]");
                int pos =1 ;
            for(int i= inicio ; i <= fim ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5));
                pos++;
            }
            (*linha)++;
        }
        if(FiltrosBarra::dit){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                saida->write("A"+QString::number(*linha),"TDI"+QString::number(j));
                int pos =1 ;
                for(int i= inicio ; i <= fim ; i++){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5));
                    pos++;
                }
                (*linha)++;
            }
        }
        if(FiltrosBarra::ditPercent){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                saida->write("A"+QString::number(*linha),"TDI"+QString::number(j)+"[%]");
                int pos =1 ;
                for(int i= inicio ; i <= fim ; i++){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5));
                    pos++;
                }
                (*linha)++;
            }
        }
        if(FiltrosBarra::tensaoEficaz){
            saida->write("A"+QString::number(*linha),"Tensao Eficaz[pu]");
            int pos =1 ;
            for(int i= inicio ; i <= fim ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5));
                pos++;
            }
            (*linha)++;
        }

}
//escreve as barras em componentes
void FrameExportar::ExcelEscreveBarrasComp(QXlsx::Document* saida, int* linha){

    saida->write("A1","Barra");
        int pos = 1;
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+"1",QString::number(i+1));
                    pos++;
                    break;
            }
        }
    }
    *linha = 2;
    if(FiltrosBarra::tensaoPu){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão na Barra[pu]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::tensaoNominal){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão Nominal[kV]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::thdv){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"THDV[%]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j));
            pos = 1;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5));
                        pos++;
                        break;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j)+"[%]");
            pos = 1;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5));
                        pos++;
                        break;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensao Eficaz[pu]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }

}
//escreve as barras Infectadas
void FrameExportar::ExcelEscreveBarrasInfec(QXlsx::Document* saida, int* linha){
    saida->write("A1","Barra");
    int pos = 1 ;
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        bool infectada = false;
        if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                    infectada = true;
                    break;
                }
            }
        }else{
            infectada = true;
        }
        if(infectada){
            saida->write(QString(numeroParaLetra(pos+1))+"1",QString::number(i+1));
            pos++;
        }
    }
    *linha = 2;
    if(FiltrosBarra::tensaoPu){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão na Barra[pu]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                    }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::tensaoNominal){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão Nominal[kV]");
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                    }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::thdv){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"THDV[%]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                    }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j));
            pos = 1;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                bool infectada = false;
                if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                    for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                        if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                            infectada = true;
                            break;
                        }
                    }
                }else{
                    infectada = true;
                }
                if(infectada){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5));
                    pos++;
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j)+"[%]");
            pos = 1;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                bool infectada = false;
                if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                    for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                        if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                            infectada = true;
                            break;
                        }
                    }
                }else{
                    infectada = true;
                }
                if(infectada){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5));
                    pos++;
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensao Eficaz[pu]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                    }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
}
//escreve Linhas com origens e destinos em estado de componentes
void FrameExportar::ExcelEscreveLInterL1InterL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos =1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
                        pos++;
                    }
                }
            }
        }
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"Dit"+QString::number(p));
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5));
                                pos++;
                            }
                        }
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"Dit"+QString::number(p)+"[%]");
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5));
                                pos++;
                            }
                        }
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Resistencia[ohm]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdasEficaz){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }

}
//escreve Linhas com origens em estado de componentes e todos destinos
void FrameExportar::ExcelEscreveLInterL1TodL2(QXlsx::Document* saida, int* linha){

}
//escreve Linhas com todas origens e destinos em componenetes
void FrameExportar::ExcelEscreveLTodL1InterL2(QXlsx::Document* saida, int* linha){

}
//escreve Linhas de todas origens e destinos
void FrameExportar::ExcelEscreveLTodL1TodL2(QXlsx::Document* saida, int* linha){

}

//--------------Funções Csv
//Funções para imprimir csv com barras em intervalo
void FrameExportar::CsvInterBarrasInterL1InterL2(){

        QFile *arquivoSaida = criaArquivo();
        QTextStream saida(arquivoSaida);
        CsvEscreveBarrasIntervalo(&saida);
        CsvEscreveLInterL1InterL2(&saida);
        //Linhas
        arquivoSaida->flush();
        arquivoSaida->close();
}
void FrameExportar::CsvInterBarrasInterL1TodL2(){
        QFile *arquivoSaida = criaArquivo();
        QTextStream saida(arquivoSaida);
        CsvEscreveBarrasIntervalo(&saida);
        CsvEscreveLInterL1TodL2(&saida);


        arquivoSaida->flush();
        arquivoSaida->close();
}
void FrameExportar::CsvInterBarrasTodL1InterL2(){
        QFile *arquivoSaida = criaArquivo();
        QTextStream saida(arquivoSaida);
        CsvEscreveBarrasIntervalo(&saida);
        CsvEscreveLTodL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();


}
void FrameExportar::CsvInterBarrasTodL1TodL2(){

    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasIntervalo(&saida);
    CsvEscreveLTodL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();

}
//Funções para imprimir csv com barras em componentes
void FrameExportar::CsvCompBarrasInterL2InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLInterL1InterL2(&saida);
    //Linhas
    arquivoSaida->flush();
    arquivoSaida->close();
}
void FrameExportar::CsvCompBarrasInterL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLInterL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}
void FrameExportar::CsvCompBarrasTodL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLTodL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();

}
void FrameExportar::CsvCompBarrasaTodL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLTodL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}
//Funções de para imprimir csv com barras infectadas
void FrameExportar::CsvInfecBarrasInterL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLInterL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}
void FrameExportar::CsvInfecBarrasInterL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLInterL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}
void FrameExportar::CsvInfecBarrasTodL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLTodL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}
void FrameExportar::CsvInfecBarrasTodL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLTodL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}
//Funções Auxiliares
//Cria arquivo
QFile* FrameExportar::criaArquivo(){
    //Configura-se um filtro para pesquisa do diretorio
    QFile *arquivoSaida = new QFile();
    QString filtro="Arquivos separados por virgula (*.csv)";
    QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
    arquivoSaida->setFileName(localSalvamento);
    if(!arquivoSaida->open(QFile::WriteOnly | QFile::Text)){
        if(arquivoSaida->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return nullptr;
        }
        QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return nullptr;
    }

    return arquivoSaida;

}
//escreve as barras em intervalo
void FrameExportar::CsvEscreveBarrasIntervalo(QTextStream* saida){
    int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
    int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
    //Barras
    *saida << "Barra" ;
    for(int i= inicio ; i <= fim ; i++){
        *saida << ","+QString::number(i+1);
    } *saida << Qt::endl;
    if(FiltrosBarra::tensaoPu){
        *saida << "Tensao na Barra[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
        } *saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        *saida << "Tensao Nominal[kV]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
        } *saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        *saida << "THDV[%]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
        } *saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
            } *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[%]" ;
            for(int i= inicio ; i <= fim ; i++){
                *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
            } *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        *saida << "Tensao Eficaz[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
        } *saida << Qt::endl;
    }

    for(int i = 0 ; i < 4 ; i++){
        *saida << Qt::endl;
    }
}
//escreve as barras em componentes
void FrameExportar::CsvEscreveBarrasComp(QTextStream* saida){
    *saida << "Barra";
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                *saida << ","+QString::number(i+1);
                break;
            }
        }
    }
    *saida << Qt::endl;

    if(FiltrosBarra::tensaoPu){
        *saida << "Tensao na Barra[pu]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
                break;
                }
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        *saida << "Tensao Nominal[kV]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
                break;
                }
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        *saida << "THDV[%]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                *saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
                break;
                }
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int k = 0 ; k < FrameTensoes::numeroDeBarras ; k++){
                for(int p = 0 ; p < FiltrosBarra::indiceBarrasEscolhidas.size() ; p++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(p).toInt()-1) == k ){
                            *saida << ","+QString::number(FrameBarras::barras[k].getDti().find(j)->second.first.first,'f',5);
                            break;
                    }
                }
            }
            *saida << Qt::endl;
        }
    }

    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[%]" ;
            for(int k = 0 ; k < FrameTensoes::numeroDeBarras ; k++){
                for(int p = 0 ; p < FiltrosBarra::indiceBarrasEscolhidas.size() ; p++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(p).toInt()-1) == k ){
                        *saida << ","+QString::number(FrameBarras::barras[k].getDti().find(j)->second.first.second,'f',5);
                        break;
                }
                }
            }
            *saida << Qt::endl;
        }
    }

    if(FiltrosBarra::tensaoEficaz){
        *saida << "Tensao Eficaz[pu]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
                break;
                }
            }
        }
        *saida << Qt::endl;
    }


}
//escreve as barras Infectadas
void FrameExportar::CsvEscreveBarrasInfec(QTextStream* saida){
    *saida << "Barra";
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        bool infectada = false;
        if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                infectada = true;
                break;
                }
            }
        }else{
            infectada = true;
        }
        if(infectada){
            *saida << ","+QString::number(i+1);
        }
    }
    *saida << Qt::endl;
    if(FiltrosBarra::tensaoPu){
        *saida << "Tensao na Barra[pu]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        *saida << "Tensao Nominal[kV]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        *saida << "THDV[%]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                *saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                bool infectada = false;
                if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                        if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                            infectada = true;
                            break;
                        }
                }
                }else{
                infectada = true;
                }
                if(infectada){
                    *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
                }
            }
            *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[%]" ;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                bool infectada = false;
                if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                    for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                        if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                            infectada = true;
                            break;
                        }
                    }
                }else{
                    infectada = true;
                }
                if(infectada){
                    *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
                }
            }
            *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        *saida << "THDV[%]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            bool infectada = false;
            if(!FrameBarras::barras[i].getBarraInfectadaThdv()){
                for(int j = 3 ; j <= FrameBarras::indiceHarmMax  ; j+=2 ){
                    if(FrameBarras::barras[i].getDti().find(j)->second.second.second){
                        infectada = true;
                        break;
                    }
                }
            }else{
                infectada = true;
            }
            if(infectada){
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
}
//escreve Linhas com origens e destinos em estado de componentes
void FrameExportar::CsvEscreveLInterL1InterL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                      if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                          *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
                      }
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                          if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                              *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                          }
                      }
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                          if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                              *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                          }
                      }
                }
            }
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                      if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                          for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                              if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                              }
                          }
                      }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                      if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                          for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                              if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                              }
                          }
                      }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[ohm]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                          if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                              *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                          }
                      }
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                          if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                              *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                          }
                      }
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                          if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                              *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                          }
                      }
                }
            }
        }
    }
    *saida << Qt::endl;

}
//escreve Linhas com origens em estado de componentes e todos destinos
void FrameExportar::CsvEscreveLInterL1TodL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino,'f',5);
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                }
            }
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                      if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                          *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                      }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                      if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                          *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                      }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[ohm]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

}
//escreve Linhas com todas origens e destinos em componenetes
void FrameExportar::CsvEscreveLTodL1InterL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                }
            }
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                      if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                          *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                      }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                      if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                          *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                      }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[ohm]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
}
//escreve Linhas de todas origens e destinos
void FrameExportar::CsvEscreveLTodL1TodL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[ohm]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
        }
    }
    *saida << Qt::endl;
}

QString FrameExportar::numeroParaLetra(int numero) {

    QString coluna = "";
    int resto;

    while (numero > 0) {
        resto = (numero - 1) % 26;
        coluna.prepend(QChar(resto + 'A'));
        numero = (numero - resto - 1) / 26;
    }

    return coluna;
}




