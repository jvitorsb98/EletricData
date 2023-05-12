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
//                CsvInterBarrasTodL2TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
//                CsvInterBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==1){

            }else{
                CsvInterBarrasInterL1InterL2();
            }
        }else{
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
//                CsvInterBarrasTodL2TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
//                CsvInterBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==1){

            }else{
//                CsvInterBarrasInterL1InterL2();
            }
        }
    }else{
        if(FiltrosBarra::indexComboBox == 0 ){
//            imprimirPdfIntervaloBarras();
        }else if(FiltrosBarra::indexComboBox == 1){
//            imprimirPdfCombonentesBarras();
        }else{
//            imprimirPdfBarrasInfectadas();
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




void FrameExportar::CsvInterBarrasInterL1InterL2(){
        //Configura-se um filtro para pesquisa do diretorio
        QFile *arquivoSaida = new QFile();
        QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
        QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
        arquivoSaida->setFileName(localSalvamento);
        if(!arquivoSaida->open(QFile::WriteOnly | QFile::Text)){
        if(arquivoSaida->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return;
        }
        QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return;
        }

        QTextStream saida(arquivoSaida);
        int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
        int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
        //entra com o numero das Barras:
        saida << "Barra" ;
        for(int i= inicio ; i <= fim ; i++){
        saida << ","+QString::number(i+1);
        } saida << Qt::endl;
        if(FiltrosBarra::tensaoPu){
            saida << "Tensao na Barra[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            qDebug() << QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            } saida << Qt::endl;
        }
        if(FiltrosBarra::tensaoNominal){
            saida << "Tensao Nominal[kV]" ;
                for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
            } saida << Qt::endl;
        }
        if(FiltrosBarra::thdv){
            saida << "THDV[%]" ;
                for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
            } saida << Qt::endl;
        }
        if(FiltrosBarra::dit){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida << "TDI"+QString::number(j)+"[pu]" ;
                for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
                } saida << Qt::endl;
            }
        }
        if(FiltrosBarra::ditPercent){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                saida << "TDI"+QString::number(j)+"[pu]" ;
                for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
                } saida << Qt::endl;
            }
        }
        if(FiltrosBarra::tensaoEficaz){
            saida << "Tensao Eficaz[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
            } saida << Qt::endl;
        }

        for(int i = 0 ; i < 4 ; i++){
            saida << Qt::endl;
        }

        //Linhas
        saida << "Linha" ;
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                              saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
                        }
                    }
                }
            }
        }
        saida << Qt::endl;
        if(FiltroLinha::correntePu){
            saida << "Corrente[pu]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                              if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                              }
                        }
                    }
                }
            }
        }
        saida << Qt::endl;
        if(FiltroLinha::dht){
            saida << "DHT[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                              if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                              }
                        }
                    }
                }
            }
        }
        saida <<Qt::endl;
        if(FiltroLinha::dit){
            for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
                saida << "DHT"+QString::number(p);
                for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                    int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                    int barraDeDestino = FrameBarras::linhas[i].getDestino();
                    for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                        if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                                  if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                      saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                                  }
                            }
                        }
                    }
                }
                saida <<Qt::endl;
            }
        }
        if(FiltroLinha::ditPercent){
            for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
                saida << "DHT"+QString::number(p)+"[%]";
                for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                    int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                    int barraDeDestino = FrameBarras::linhas[i].getDestino();
                    for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                        if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                                  if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                      saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                                  }
                            }
                        }
                    }
                }
                saida <<Qt::endl;
            }
        }
        if(FiltroLinha::resistencia){
            saida << "Resistencia[ohm]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                            }
                        }
                    }
                }
            }
        }
        saida << Qt::endl;

        if(FiltroLinha::perdas){
            saida << "Perdas[pu]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                            }
                        }
                    }
                }
            }
        }
        saida << Qt::endl;

        if(FiltroLinha::perdasEficaz){
            saida << "Perdas[pu]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                  saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                            }
                        }
                    }
                }
            }
        }
        saida << Qt::endl;

        arquivoSaida->flush();
        arquivoSaida->close();
}
void FrameExportar::CsvInterBarrasInterL1TodL2(){
        //Configura-se um filtro para pesquisa do diretorio
        QFile *arquivoSaida = new QFile();
        QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
        QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
        arquivoSaida->setFileName(localSalvamento);
        if(!arquivoSaida->open(QFile::WriteOnly | QFile::Text)){
            if(arquivoSaida->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
                return;
            }
            QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
            return;
        }

        QTextStream saida(arquivoSaida);
        int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
        int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
        //entra com o numero das Barras:
        saida << "Barra" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(i+1);
        } saida << Qt::endl;
        if(FiltrosBarra::tensaoPu){
            saida << "Tensao na Barra[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            } saida << Qt::endl;
        }
        if(FiltrosBarra::tensaoNominal){
            saida << "Tensao Nominal[kV]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
            } saida << Qt::endl;
        }
        if(FiltrosBarra::thdv){
            saida << "THDV[%]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
            } saida << Qt::endl;
        }
        if(FiltrosBarra::dit){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                saida << "TDI"+QString::number(j)+"[pu]" ;
                for(int i= inicio ; i <= fim ; i++){
                    saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
                } saida << Qt::endl;
            }
        }
        if(FiltrosBarra::ditPercent){
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                saida << "TDI"+QString::number(j)+"[pu]" ;
                for(int i= inicio ; i <= fim ; i++){
                    saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
                } saida << Qt::endl;
            }
        }
        if(FiltrosBarra::tensaoEficaz){
            saida << "Tensao Eficaz[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
            } saida << Qt::endl;
        }

        for(int i = 0 ; i < 4 ; i++){
            saida << Qt::endl;
        }

        //Linhas
        saida << "Linha" ;
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino,'f',5);
                }
            }
        }
        saida << Qt::endl;
        if(FiltroLinha::correntePu){
            saida << "Corrente[pu]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                    }
                }
            }
        }
        saida << Qt::endl;
        if(FiltroLinha::dht){
            saida << "DHT[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                       saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                    }
                }
            }
        }
        saida <<Qt::endl;
        if(FiltroLinha::dit){
            for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
                saida << "DHT"+QString::number(p);
                for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                    int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                    for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                        if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                            saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                        }
                    }
                }
                saida <<Qt::endl;
            }
        }
        if(FiltroLinha::ditPercent){
            for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
                saida << "DHT"+QString::number(p)+"[%]";
                for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                    int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                    for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                        if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                            saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                        }
                    }
                }
                saida <<Qt::endl;
            }
        }
        if(FiltroLinha::resistencia){
            saida << "Resistencia[ohm]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                    }
                }
            }
        }
        saida << Qt::endl;

        if(FiltroLinha::perdas){
            saida << "Perdas[pu]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                    }
                }
            }
        }
        saida << Qt::endl;

        if(FiltroLinha::perdasEficaz){
            saida << "Perdas[pu]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                    }
                }
            }
        }
        saida << Qt::endl;

        arquivoSaida->flush();
        arquivoSaida->close();
}
void FrameExportar::CsvInterBarrasTodL1InterL2(){
    //Configura-se um filtro para pesquisa do diretorio
    QFile *arquivoSaida = new QFile();
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
    arquivoSaida->setFileName(localSalvamento);
    if(!arquivoSaida->open(QFile::WriteOnly | QFile::Text)){
        if(arquivoSaida->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return;
        }
        QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return;
    }

    QTextStream saida(arquivoSaida);
    int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
    int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
    //entra com o numero das Barras:
    saida << "Barra" ;
    for(int i= inicio ; i <= fim ; i++){
        saida << ","+QString::number(i+1);
    } saida << Qt::endl;
    if(FiltrosBarra::tensaoPu){
        saida << "Tensao na Barra[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
        } saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        saida << "Tensao Nominal[kV]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
        } saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        saida << "THDV[%]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
        } saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
            } saida << Qt::endl;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
            } saida << Qt::endl;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        saida << "Tensao Eficaz[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
        } saida << Qt::endl;
    }

    for(int i = 0 ; i < 4 ; i++){
        saida << Qt::endl;
    }

    //Linhas
    saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
            }
    }
    }
    saida << Qt::endl;
    if(FiltroLinha::correntePu){
        saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                }
            }
        }
    }
    saida << Qt::endl;
    if(FiltroLinha::dht){
        saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                }
            }
        }
    }
    saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                      if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                          saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                      }
                }
            }
            saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                      if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                          saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                      }
                }
            }
            saida <<Qt::endl;
        }
    }
    if(FiltroLinha::resistencia){
        saida << "Resistencia[ohm]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                }
            }
        }
    }
    saida << Qt::endl;

    if(FiltroLinha::perdas){
        saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                }
            }
        }
    }
    saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                }
            }
        }
    }
    saida << Qt::endl;

    arquivoSaida->flush();
    arquivoSaida->close();


}
void FrameExportar::CsvInterBarrasTodL1TodL2(){

    //Configura-se um filtro para pesquisa do diretorio
    QFile *arquivoSaida = new QFile();
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
    arquivoSaida->setFileName(localSalvamento);
    if(!arquivoSaida->open(QFile::WriteOnly | QFile::Text)){
        if(arquivoSaida->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return;
        }
        QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return;
    }

    QTextStream saida(arquivoSaida);
    int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
    int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
    //entra com o numero das Barras:
    saida << "Barra" ;
    for(int i= inicio ; i <= fim ; i++){
        saida << ","+QString::number(i+1);
    } saida << Qt::endl;
    if(FiltrosBarra::tensaoPu){
        saida << "Tensao na Barra[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            qDebug() << QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
        } saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        saida << "Tensao Nominal[kV]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
        } saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        saida << "THDV[%]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
        } saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
            } saida << Qt::endl;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
            } saida << Qt::endl;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        saida << "Tensao Eficaz[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
        } saida << Qt::endl;
    }

    for(int i = 0 ; i < 4 ; i++){
        saida << Qt::endl;
    }

    //Linhas
    saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
    }
    saida << Qt::endl;
    if(FiltroLinha::correntePu){
        saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
        }
    }
    saida << Qt::endl;
    if(FiltroLinha::dht){
        saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
        }
    }
    saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
            }
            saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
            }
            saida <<Qt::endl;
        }
    }
    if(FiltroLinha::resistencia){
        saida << "Resistencia[ohm]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
        }
    }
    saida << Qt::endl;

    if(FiltroLinha::perdas){
        saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
        }
    }
    saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
        }
    }
    saida << Qt::endl;

    arquivoSaida->flush();
    arquivoSaida->close();


}
