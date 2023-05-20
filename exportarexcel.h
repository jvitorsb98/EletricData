
#ifndef EXPORTAREXCEL_H
#define EXPORTAREXCEL_H

#include "xlsxdocument.h"

using namespace QXlsx;


class ExportarExcel
{
public:
    explicit ExportarExcel(QWidget *parent = nullptr);

    //----------Funções Excel
    //Funções para imprimir excel com barras em intervalo
    void ExcelInterBInterL1InterL2();
    void ExcelInterBInterL1TodL2();
    void ExcelInterBarrasTodL1InterL2();
    void ExcelInterBarrasTodL1TodL2();
    //Funções para imprimir Excel com barras em componentes
    void ExcelCompBarrasInterL1InterL2();
    void ExcelCompBarrasInterL1TodL2();
    void ExcelCompBarrasTodL1InterL2();
    void ExcelCompBarrasaTodL1TodL2();
    //Funções de para imprimir Excel com barras infectadas
    void ExcelInfecBarrasInterL1InterL2();
    void ExcelInfecBarrasInterL1TodL2();
    void ExcelInfecBarrasTodL1InterL2();
    void ExcelInfecBarrasTodL1TodL2();

private:

    //Funções Auxiliares
    QString numeroParaLetra(int numero);
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

};

#endif // EXPORTAREXCEL_H
