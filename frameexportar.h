#ifndef FRAMEEXPORTAR_H
#define FRAMEEXPORTAR_H

#include <QFrame>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_framebarras.h"
#include "framebarras.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include <QPdfWriter>
#include <QPrinter>
#include<QPainter>
using namespace QXlsx;


namespace Ui {
class FrameExportar;
}

class FrameExportar : public QFrame
{
    Q_OBJECT

public:
    explicit FrameExportar(QWidget *parent = nullptr, Ui::MainWindow *mw=nullptr,  Ui::FrameBarras *fb=nullptr);
    ~FrameExportar();

    void inserirQssFrame();
    void inserirQssImg();
    void inserirQssRadioButton();
    void inserirQssBtn();
    void inicializaFrame();
    void imprimirPdfIntervaloBarras();
    void imprimirPdfCombonentesBarras();
    void imprimirPdfBarrasInfectadas();

    //----------Funções PDF
    //Funções para imprimir PDF com barras em intervalo
    void PdfInterBInterL1InterL2();
    void PdfInterBInterL1TodL2();
    void PdfInterBarrasTodL1InterL2();
    void PdfInterBarrasTodL1TodL2();
    //Funções para imprimir PDF com barras em componentes
    void PdfCompBarrasInterL2InterL2();
    void PdfCompBarrasInterL1TodL2();
    void PdfCompBarrasTodL1InterL2();
    void PdfCompBarrasaTodL1TodL2();
    //Funções de para imprimir PDF com barras infectadas
    void PdfInfecBarrasInterL1InterL2();
    void PdfInfecBarrasInterL1TodL2();
    void PdfInfecBarrasTodL1InterL2();
    void PdfInfecBarrasTodL1TodL2();
    //Funções Auxiliares

    void PdfInsereCapa(QPainter* painter);
    //escreve as barras em intervalo
    void PdfEscreveBarrasIntervalo(QPdfWriter*);
    //escreve as barras em componentes
    void PdfEscreveBarrasComp(QPdfWriter*);
    //escreve as barras Infectadas
    void PdfEscreveBarrasInfec(QPdfWriter*);
    //escreve Linhas com origens e destinos em estado de componentes
    void PdfEscreveLInterL1InterL2(QPdfWriter*);
    //escreve Linhas com origens em estado de componentes e todos destinos
    void PdfEscreveLInterL1TodL2(QPdfWriter*);
    //escreve Linhas com todas origens e destinos em componenetes
    void PdfEscreveLTodL1InterL2(QPdfWriter*);
    //escreve Linhas de todas origens e destinos
    void PdfEscreveLTodL1TodL2(QPdfWriter*);





    //----------Funções Excel
    //Funções para imprimir excel com barras em intervalo
    void ExcelInterBInterL1InterL2();
    void ExcelInterBInterL1TodL2();
    void ExcelInterBarrasTodL1InterL2();
    void ExcelInterBarrasTodL1TodL2();
    //Funções para imprimir Excel com barras em componentes
    void ExcelCompBarrasInterL2InterL2();
    void ExcelCompBarrasInterL1TodL2();
    void ExcelCompBarrasTodL1InterL2();
    void ExcelCompBarrasaTodL1TodL2();
    //Funções de para imprimir Excel com barras infectadas
    void ExcelInfecBarrasInterL1InterL2();
    void ExcelInfecBarrasInterL1TodL2();
    void ExcelInfecBarrasTodL1InterL2();
    void ExcelInfecBarrasTodL1TodL2();
    QString numeroParaLetra(int numero);
    //Funções Auxiliares
    //Cria planilha
    QXlsx::Document* criaPlanilha();
    //pula linhas entre barras e Linhas
    void ExcelPulaLinha(int* );
    //Salva Planilha
    void salvaPlanilha(QXlsx::Document* );
    //escreve as barras em intervalo
    void ExcelEscreveBarrasIntervalo(QXlsx::Document* , int* );
    //escreve as barras em componentes
    void ExcelEscreveBarrasComp(QXlsx::Document* , int*  );
    //escreve as barras Infectadas
    void ExcelEscreveBarrasInfec(QXlsx::Document* , int* );
    //escreve Linhas com origens e destinos em estado de componentes
    void ExcelEscreveLInterL1InterL2(QXlsx::Document* , int* );
    //escreve Linhas com origens em estado de componentes e todos destinos
    void ExcelEscreveLInterL1TodL2(QXlsx::Document*, int*  );
    //escreve Linhas com todas origens e destinos em componenetes
    void ExcelEscreveLTodL1InterL2(QXlsx::Document* , int* );
    //escreve Linhas de todas origens e destinos
    void ExcelEscreveLTodL1TodL2(QXlsx::Document*, int* );

    //----------funções CSV
    //Funções para imprimir csv com barras em intervalo
    void CsvInterBarrasInterL1InterL2();
    void CsvInterBarrasInterL1TodL2();
    void CsvInterBarrasTodL1InterL2();
    void CsvInterBarrasTodL1TodL2();
    //Funções para imprimir csv com barras em componentes
    void CsvCompBarrasInterL2InterL2();
    void CsvCompBarrasInterL1TodL2();
    void CsvCompBarrasTodL1InterL2();
    void CsvCompBarrasaTodL1TodL2();
    //Funções de para imprimir csv com barras infectadas
    void CsvInfecBarrasInterL1InterL2();
    void CsvInfecBarrasInterL1TodL2();
    void CsvInfecBarrasTodL1InterL2();
    void CsvInfecBarrasTodL1TodL2();
    //Funções Auxiliares
    //Cria arquivo
    QFile* criaArquivo();
    //escreve as barras em intervalo
    void CsvEscreveBarrasIntervalo(QTextStream* );
    //escreve as barras em componentes
    void CsvEscreveBarrasComp(QTextStream* );
    //escreve as barras Infectadas
    void CsvEscreveBarrasInfec(QTextStream* );
    //escreve Linhas com origens e destinos em estado de componentes
    void CsvEscreveLInterL1InterL2(QTextStream* );
    //escreve Linhas com origens em estado de componentes e todos destinos
    void CsvEscreveLInterL1TodL2(QTextStream* );
    //escreve Linhas com todas origens e destinos em componenetes
    void CsvEscreveLTodL1InterL2(QTextStream* );
    //escreve Linhas de todas origens e destinos
    void CsvEscreveLTodL1TodL2(QTextStream* );




private slots:
    void on_btnVoltar_clicked();

    void on_btnExportar_clicked();

private:
    Ui::FrameExportar *ui;
};

#endif // FRAMEEXPORTAR_H
