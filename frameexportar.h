#ifndef FRAMEEXPORTAR_H
#define FRAMEEXPORTAR_H

#include <QFrame>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_framebarras.h"
#include "framebarras.h"


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


    void CsvInterBarrasInterL1InterL2();
    void CsvInterBarrasInterL1TodL2();
    void CsvInterBarrasTodL1InterL2();
    void CsvInterBarrasTodL1TodL2();

    void CsvCompBarrasInterL2InterL2();
    void CsvCompBarrasInterL1TodL2();
    void CsvCompBarrasTodL1InterL2();
    void CsvCompBarrasaTodL1TodL2();

    void CsvInfecBarrasInterL1InterL2();
    void CsvInfecBarrasInterL1TodL2();
    void CsvInfecBarrasTodL1InterL2();
    void CsvInfecBarrasTodL1TodL2();

    QFile* criaArquivo();
    void CsvEscreveBarrasIntervalo(QTextStream* );
    void CsvEscreveBarrasComp(QTextStream* );
    void CsvEscreveBarrasInfec(QTextStream* );


    void CsvEscreveLInterL1InterL2(QTextStream* );
    void CsvEscreveLInterL1TodL2(QTextStream* );
    void CsvEscreveLTodL1InterL2(QTextStream* );
    void CsvEscreveLTodL1TodL2(QTextStream* );




private slots:
    void on_btnVoltar_clicked();

    void on_btnExportar_clicked();

private:
    Ui::FrameExportar *ui;
};

#endif // FRAMEEXPORTAR_H
