#ifndef FRAMEEXPORTAR_H
#define FRAMEEXPORTAR_H

#include <QFrame>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_framebarras.h"




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

    void ExportacaoParaPdf();
    void ExportacaoParaExcel();
    void ExportacaoParaCsv();


private slots:
    void on_btnVoltar_clicked();

    void on_btnExportar_clicked();

private:
    Ui::FrameExportar *ui;
};

#endif // FRAMEEXPORTAR_H
