
#ifndef EXPORTARPDF_H
#define EXPORTARPDF_H

#include <QPdfWriter>
#include <QPrinter>
#include<QPainter>


class ExportarPdf
{
public:
    explicit ExportarPdf(QWidget *parent = nullptr);

    //----------Funções PDF
    //Funções para imprimir PDF com barras em intervalo
    void PdfInterBInterL1InterL2();
    void PdfInterBInterL1TodL2();
    void PdfInterBarrasTodL1InterL2();
    void PdfInterBarrasTodL1TodL2();
    //Funções para imprimir PDF com barras em componentes
    void PdfCompBarrasInterL1InterL2();
    void PdfCompBarrasInterL1TodL2();
    void PdfCompBarrasTodL1InterL2();
    void PdfCompBarrasaTodL1TodL2();
    //Funções de para imprimir PDF com barras infectadas
    void PdfInfecBarrasInterL1InterL2();
    void PdfInfecBarrasInterL1TodL2();
    void PdfInfecBarrasTodL1InterL2();
    void PdfInfecBarrasTodL1TodL2();


private:

    //Funções Auxiliares
    //Funções os conteudos com barras em intervalo
    void ContInterBInterL1InterL2(QPrinter* );
    void ContInterBInterL1TodL2(QPrinter* );
    void ContInterBarrasTodL1InterL2(QPrinter* );
    void ContInterBarrasTodL1TodL2(QPrinter* );
    //Funções para imprimir PDF com barras em componentes
    void ContCompBarrasInterL1InterL2(QPrinter* );
    void ContCompBarrasInterL1TodL2(QPrinter* );
    void ContCompBarrasTodL1InterL2(QPrinter* );
    void ContCompBarrasaTodL1TodL2(QPrinter* );
    //Funções de para imprimir PDF com barras infectadas
    void ContInfecBarrasInterL1InterL2(QPrinter* );
    void ContInfecBarrasInterL1TodL2(QPrinter* );
    void ContInfecBarrasTodL1InterL2(QPrinter* );
    void ContInfecBarrasTodL1TodL2(QPrinter* );


    //cacula quantidade de linhas que uma barra irá ocupar no sistema
    int  QtdLinhasInfoBarra();
    int  QtdLinhasInfoLinha();

};

#endif // EXPORTARPDF_H
