#include "frameexportar.h"
#include "ui_frameexportar.h"
#include "style.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "framebarras.h"
#include "ui_framebarras.h"

#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>
#include <QFileDialog>
#include <QDebug>
#include <QFont>
#include <QPdfWriter>
#include <QUrl>
#include <QPainter>
#include <QFontMetrics>



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
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                PdfInterBarrasTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                PdfInterBInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                PdfInterBarrasTodL1InterL2();
            }else{
                PdfInterBInterL1InterL2();
            }
        }else if(FiltrosBarra::indexComboBox == 1 ){
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                PdfCompBarrasaTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                PdfCompBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                PdfCompBarrasTodL1InterL2();
            }else{
                PdfCompBarrasInterL2InterL2();
            }
        }else{
            if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
                PdfInfecBarrasTodL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
                PdfInfecBarrasInterL1TodL2();
            }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
                PdfInfecBarrasTodL1InterL2();
            }else{
                PdfInfecBarrasInterL1InterL2();
            }
        }
    }else if(ui->radioButtonCsv->isChecked()){ // exportação CSV
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
    }else{  // Exportação Excel
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
                ExcelInfecBarrasTodL1TodL2();
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


//-------------Funções PDF
//Funções para imprimir PDF com barras em intervalo
void FrameExportar::PdfInterBInterL1InterL2(){
        QPrinter printer;
        printer.setPrinterName("PDF");



        QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

        if (filename.isEmpty()) {
        return;
        }

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        ContInterBInterL1InterL2(&printer);

        QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfInterBInterL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);


    ContInterBInterL1TodL2(&printer);



    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfInterBarrasTodL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);


    ContInterBarrasTodL1InterL2(&printer);



    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfInterBarrasTodL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInterBarrasTodL1TodL2(&printer);



    QDesktopServices::openUrl(QUrl(filename));
}
//Funções para imprimir PDF com barras em componentes
void FrameExportar::PdfCompBarrasInterL2InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);


    ContCompBarrasInterL2InterL2(&printer);


    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfCompBarrasInterL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContCompBarrasInterL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfCompBarrasTodL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);


    ContCompBarrasTodL1InterL2(&printer);


    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfCompBarrasaTodL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");


    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);


    ContCompBarrasaTodL1TodL2(&printer);


    QDesktopServices::openUrl(QUrl(filename));
}
//Funções de para imprimir PDF com barras infectadas
void FrameExportar::PdfInfecBarrasInterL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");


    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);


    ContInfecBarrasInterL1InterL2(&printer);


    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfInfecBarrasInterL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasInterL1TodL2(&printer);


    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfInfecBarrasTodL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");



    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasTodL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}
void FrameExportar::PdfInfecBarrasTodL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasTodL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}
//Funções Auxiliares
//Funções os conteudos com barras em intervalo
void FrameExportar::ContInterBInterL1InterL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContInterBInterL1TodL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContInterBarrasTodL1InterL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContInterBarrasTodL1TodL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);

    printer->newPage();

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString TituloBarras = "Barras";


    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, TituloBarras);

    printer->newPage();



    // Define a posição e tamanho da imagem
    QRectF logoMenorRect(20, 20, 100, 19);

    // Desenha a imagem na página
    painter.drawImage(logoMenorRect, logo);

    int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
    int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


    for (int i = inicio; i <= fim; i++) {

        if((h - (inicioItem+100+30*QtdLinhasInfoBarra()) < 10 )){
             printer->newPage();
            inicioItem = 100;
             painter.drawImage(logoMenorRect, logo);

        }

        QLabel* labelHeader = new QLabel();
        labelHeader->setGeometry((w-500)/2, inicioItem, 500, 30);
        labelHeader->setStyleSheet("background-color: #1E385B; border-top-left-radius: 10px; border-top-right-radius: 10px; padding: 10px;");
        labelHeader->setFont(fontHeader);
        labelHeader->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
        labelHeader->setTextFormat(Qt::RichText);

        // Cria a QString atributos com a tag <html>
        QString atributos = "<html><div style='color: black; border-radius: 10px; padding: 10px'>";

        if (FiltrosBarra::tensaoPu) {
            atributos += "<p><b>Tensão na Barra[pu]:</b> %1</p>";
                QString tensao = QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            atributos = atributos.arg(tensao);
        }

        if (FiltrosBarra::tensaoNominal) {
            atributos += "<p><b>Tensão Nominal[kV]:</b> %1</p>";
                QString tensaoNominal = QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
            atributos = atributos.arg(tensaoNominal);
        }

        if (FiltrosBarra::thdv) {
            (FrameBarras::barras[i].getBarraInfectadaThdv()) ? atributos +=  "<p style='background-color: #FF8080;'><b>DHT[%]:</b> %1</p>" : atributos += "<p><b>THDV[%]:</b> %1</p>";
                QString thdv = QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
            atributos = atributos.arg(thdv);
        }

        if(FiltrosBarra::dit){
            for( int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                (FrameBarras::barras[i].getDti().find(j)->second.second.second) ? atributos +=  "<p style='background-color: #FF8080;'><b>TDI%1[pu]:</b> %2</p>" : atributos += "<p><b>TDI%1[pu]:</b> %2</p>";
                    QString tdi = QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'g',5);
                atributos = atributos.arg(j);
                atributos = atributos.arg(tdi);
            }
        }

        if(FiltrosBarra::ditPercent){
            for( int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                (FrameBarras::barras[i].getDti().find(j)->second.second.second) ? atributos +=  "<p style='background-color: #FF8080;'><b>TDI%1[%]:</b> %2</p>" : atributos += "<p><b>TDI%1[%]:</b> %2</p>";
                QString tdi = QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
                atributos = atributos.arg(j);
                atributos = atributos.arg(tdi);
            }
        }

        if(FiltrosBarra::tensaoEficaz){
            atributos += "<p><b>Tensao Eficaz[pu]:</b> %1</p>";
            QString tensaoEficaz = QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
            atributos = atributos.arg(tensaoEficaz);
        }

        // Fecha a tag </div> e </html>
        atributos += "</div></html>";

        // Cria a QLabel com os atributos
        QLabel* labelAtributos = new QLabel();
        labelAtributos->setGeometry((w-500)/2, inicioItem + 30, 500,10+ 30*QtdLinhasInfoBarra());
        labelAtributos->setStyleSheet("background-color: #F5F5F5; border-radius: 10px; padding: 10px;");
        labelAtributos->setFont(fontConteudo);
        labelAtributos->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        labelAtributos->setTextFormat(Qt::RichText);
        labelAtributos->setText(atributos);

        // Cria o título com o número da barra
        QString titulo = QString("Barra %1").arg(i+1);
        painter.fillRect(QRectF((w-500)/2, inicioItem, 500, 30), QBrush(QColor("#1E385B")));
        painter.setFont(fontHeader);
        painter.setPen(QPen(Qt::white));
        painter.drawText(QRectF((w-500)/2, inicioItem, 500, 30), titulo, QTextOption(Qt::AlignCenter));

        // Desenha a QLabel na imagem
        QPixmap pixmap = labelAtributos->grab();
        painter.drawPixmap(QRectF((w-500)/2, inicioItem + 30, 500,10+ 30*QtdLinhasInfoBarra()).toRect(), pixmap);

        inicioItem += 100 + 30*QtdLinhasInfoBarra();

    }

    printer->newPage();

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString TituloLinhas = "Linhas";

    painter.setPen(QPen());
    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, TituloLinhas);


    printer->newPage();

    // Desenha a imagem na página
    painter.drawImage(logoMenorRect, logo);

    inicioItem = 100;

    for(int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){

        if((h - (inicioItem+100+30*QtdLinhasInfoLinha()) < 10 )){
            printer->newPage();
            inicioItem = 100;
            painter.drawImage(logoMenorRect, logo);

        }

        QLabel* labelHeader = new QLabel();
        labelHeader->setGeometry((w-500)/2, inicioItem, 500, 30);
        labelHeader->setStyleSheet("background-color: #1E385B; border-top-left-radius: 10px; border-top-right-radius: 10px; padding: 10px;");
        labelHeader->setFont(fontHeader);
        labelHeader->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
        labelHeader->setTextFormat(Qt::RichText);


        // Cria a QString atributos com a tag <html>
        QString atributos = "<html><div style='color: black; border-radius: 10px; padding: 10px'>";

        if(FiltroLinha::correntePu){
            atributos += "<p><b>Corrente na Linha[pu]:</b> %1</p>";
                QString corrente = QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
            atributos = atributos.arg(corrente);
        }
        if(FiltroLinha::dht){
            atributos += "<p><b>DHT[%]:</b> %1</p>";
            QString dht = QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
            atributos = atributos.arg(dht);
        }
        if(FiltroLinha::dit){
            for( int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                atributos += "<p><b>DHI%1[pu]:</b> %2</p>";
                QString tdi = QString::number(FrameBarras::linhas[i].getDti().find(j)->second.first,'g',5);
                atributos = atributos.arg(j);
                atributos = atributos.arg(tdi);
            }
        }
        if(FiltroLinha::ditPercent){
            for( int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                atributos += "<p><b>DHI%1[%]:</b> %2</p>";
                QString tdiPercent = QString::number(FrameBarras::linhas[i].getDti().find(j)->second.second,'f',5);
                atributos = atributos.arg(j);
                atributos = atributos.arg(tdiPercent);
            }
        }
        if(FiltroLinha::correnteEficaz){
            atributos += "<p><b>Corrente Eficaz[pu]:</b> %1</p>";
            QString correnteEficaz = QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
            atributos = atributos.arg(correnteEficaz);
        }
        if(FiltroLinha::resistencia){
            atributos += "<p><b>Resistencia[ohm]:</b> %1</p>";
            QString resistencia = QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
            atributos = atributos.arg(resistencia);
        }
        if(FiltroLinha::perdas){
            atributos += "<p><b>Perdas[pu]:</b> %1</p>";
            QString perdas = QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
            atributos = atributos.arg(perdas);
        }
        if(FiltroLinha::perdasEficaz){
            atributos += "<p><b>Perdas[pu]:</b> %1</p>";
            QString perdasEficaz = QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
            atributos = atributos.arg(perdasEficaz);
        }

        // Fecha a tag </div> e </html>
        atributos += "</div></html>";

        // Cria a QLabel com os atributos
        QLabel* labelAtributos = new QLabel();
        labelAtributos->setGeometry((w-500)/2, inicioItem + 30, 500,10+ 30*QtdLinhasInfoLinha());
        labelAtributos->setStyleSheet("background-color: #F5F5F5; border-radius: 10px; padding: 10px;");
        labelAtributos->setFont(fontConteudo);
        labelAtributos->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        labelAtributos->setTextFormat(Qt::RichText);
        labelAtributos->setText(atributos);

        // Cria o título com o número da linha
        QString titulo = QString("Linha %1 \u279E %2");
        titulo = titulo.arg(FrameBarras::linhas[i].getOrigem());
        titulo = titulo.arg(FrameBarras::linhas[i].getDestino());


        painter.fillRect(QRectF((w-500)/2, inicioItem, 500, 30), QBrush(QColor("#1E385B")));
        painter.setFont(fontHeader);
        painter.setPen(QPen(Qt::white));
        painter.drawText(QRectF((w-500)/2, inicioItem, 500, 30), titulo, QTextOption(Qt::AlignCenter));

        // Desenha a QLabel na imagem
        QPixmap pixmap = labelAtributos->grab();
        painter.drawPixmap(QRectF((w-500)/2, inicioItem + 30, 500,10+ 30*QtdLinhasInfoLinha()).toRect(), pixmap);

        inicioItem += 100 + 30*QtdLinhasInfoLinha();

    }

    painter.end();
}
//Funções para imprimir PDF com barras em componentes
void FrameExportar::ContCompBarrasInterL2InterL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContCompBarrasInterL1TodL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContCompBarrasTodL1InterL2(QPrinter* printer ){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContCompBarrasaTodL1TodL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
//Funções de para imprimir PDF com barras infectadas
void FrameExportar::ContInfecBarrasInterL1InterL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContInfecBarrasInterL1TodL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContInfecBarrasTodL1InterL2(QPrinter* printer ){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);
    painter.end();
}
void FrameExportar::ContInfecBarrasTodL1TodL2(QPrinter* printer){
    QPainter painter(printer);
    painter.begin(printer);
    int w = painter.device()->width();
    int h = painter.device()->height();

    // Carrega a imagem do arquivo
    QImage logo(":/logo/imgs/logo/logo.jpg");

    // Define a posição e tamanho da imagem
    QRectF logoRect(20, 20, 300, 56);

    // Desenha a imagem na página
    painter.drawImage(logoRect, logo);

    QString textoPrincipal = "Relatório de Sistema Elétrico";
    QString subtexto = "Sistema com " + QString::number(FrameTensoes::numeroDeBarras) + " barras e " + QString::number(FrameBarras::numeroDeLinhas) + " linhas";

    QFont fontePrincipal("Arial", 20, QFont::Bold);
    QFont fonteSubtexto("Arial", 12);

    QFontMetrics fmPrincipal(fontePrincipal);
    QFontMetrics fmSubtexto(fonteSubtexto);

    int alturaTextoPrincipal = fmPrincipal.height();
    int alturaSubtexto = fmSubtexto.height();

    painter.setFont(fontePrincipal);
    painter.drawText(QRectF(0, (h - alturaTextoPrincipal - alturaSubtexto) / 2, w, alturaTextoPrincipal), Qt::AlignHCenter | Qt::AlignTop, textoPrincipal);

    painter.setFont(fonteSubtexto);
    painter.drawText(QRectF(0, (h - alturaSubtexto) / 2 + alturaTextoPrincipal, w, alturaSubtexto), Qt::AlignHCenter | Qt::AlignTop, subtexto);


    painter.end();
}


//Insere sumário


int FrameExportar::QtdLinhasInfoBarra(){
    int linhas = 0 ;

    linhas += (int)FiltrosBarra::tensaoPu;
    linhas += (int)FiltrosBarra::tensaoNominal;
    linhas += (int)FiltrosBarra::thdv;
    linhas += (int)FiltrosBarra::dit * (FrameBarras::quantidadeDeComponentesHarm);
    linhas += (int)FiltrosBarra::ditPercent * (FrameBarras::quantidadeDeComponentesHarm);
    linhas += (int)FiltrosBarra::tensaoEficaz;

    return linhas;
}

int FrameExportar::QtdLinhasInfoLinha(){
    int linhas = 0 ;

    linhas += (int) FiltroLinha::correntePu;
    linhas += (int) FiltroLinha::dht;
    linhas += (int) FiltroLinha::dit * (FrameBarras::quantidadeDeComponentesHarm);
    linhas += (int) FiltroLinha::ditPercent * (FrameBarras::quantidadeDeComponentesHarm);
    linhas += (int) FiltroLinha::correnteEficaz;
    linhas += (int) FiltroLinha::resistencia;
    linhas += (int) FiltroLinha::perdas;
    linhas += (int) FiltroLinha::perdasEficaz;

    return linhas;
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
void FrameExportar::ExcelInfecBarrasTodL1TodL2(){
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
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            pos =1 ;
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
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            pos =1 ;
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
    saida->write("A"+QString::number(*linha),"Linha");
    int pos = 1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
                pos++;
            }
        }
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos = 1;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            pos =1 ;
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5));
                        pos++;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            pos =1 ;
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5));
                        pos++;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Resistencia[ohm]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdasEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
}
//escreve Linhas com todas origens e destinos em componenetes
void FrameExportar::ExcelEscreveLTodL1InterL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos = 1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
                pos++;
            }
        }
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos =1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5));
                        pos++;                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos =1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5));
                        pos++;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Resistencia[ohm]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
}
//escreve Linhas de todas origens e destinos
void FrameExportar::ExcelEscreveLTodL1TodL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos = 1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
        pos++;
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos = 1;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos = 1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first));
                pos++;
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos = 1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second));
                pos++;
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Resistencia[ohm]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::perdasEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
            pos++;
        }
        (*linha)++;
    }
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
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
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
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
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
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                      *saida << ","+QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
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
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
        }
    }
    *saida << Qt::endl;
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
//utilizavel para escrevernos locais certos no excel
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

