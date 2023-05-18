
#ifndef EXPORTARCSV_H
#define EXPORTARCSV_H

#include <QFile>


class ExportarCsv
{
public:
    ExportarCsv(QWidget *parent = nullptr);

    //----------funções CSV
    //Funções para imprimir csv com barras em intervalo
    void CsvInterBarrasInterL1InterL2();
    void CsvInterBarrasInterL1TodL2();
    void CsvInterBarrasTodL1InterL2();
    void CsvInterBarrasTodL1TodL2();
    //Funções para imprimir csv com barras em componentes
    void CsvCompBarrasInterL1InterL2();
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
};

#endif // EXPORTARCSV_H
