#ifndef FRAMEEXPORTAR_H
#define FRAMEEXPORTAR_H

#include <QFrame>
#include "ui_mainwindow.h"
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

    void inicializaFrame();




private slots:
    void on_btnVoltar_clicked();

    void on_btnExportar_clicked();

private:
    Ui::FrameExportar *ui;

    void inserirQssFrame();
    void inserirQssImg();
    void inserirQssRadioButton();
    void inserirQssBtn();

    void ExportacaoParaPdf();
    void ExportacaoParaExcel();
    void ExportacaoParaCsv();
};

#endif // FRAMEEXPORTAR_H
