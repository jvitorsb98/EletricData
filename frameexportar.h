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

private slots:
    void on_btnVoltar_clicked();

    void on_btnExportar_clicked();

private:
    Ui::FrameExportar *ui;
};

#endif // FRAMEEXPORTAR_H
