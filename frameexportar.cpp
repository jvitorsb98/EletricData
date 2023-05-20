/**
 * @class FrameExportar
 * @brief Janela responsável pela exportação dos dados em 3 formatos diferentes ( Pdf , Excel e .csv )
 * Essa janela foi construida com 1 tabWidget e dois TableWidget entro dela, um para as Barras e outro para as linhas, além de botões para filtragem, avanço e voltar.
 * @author João Vitor N. Ramos
*/

#include "frameexportar.h"
#include "ui_frameexportar.h"
#include "style.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_framebarras.h"
#include "exportarpdf.h"
#include "exportarexcel.h"
#include "exportarcsv.h"
#include "filtrolinha.h"
#include "filtrosbarra.h"

#include <QDebug>

/**
 * @variable Ui::MainWindow *frameMa
 * @brief Variavel que permite acessar o 'Ui' do MainWindow. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::MainWindow *frameMa;

/**
 * @variable Ui::FrameBarras *frameB
 * @brief Variavel que permite acessar o 'Ui' do FrameBarras. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::FrameBarras *frameB;

/**
 * @variable QWidget *pa;
 * @brief Variavel que permite acessar seu parent. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
QWidget *pa;


/**
 * @name FrameExportar::FrameExportar
 * @brief Construtor da classe FrameExportar
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 * @param mw (Parãmetro do tipo Ui::MainWindow para permitir acesso aos componentes da interface do frame MainWindow)
 * @param fb (Parãmetro do tipo Ui::FrameTensoes para permitir acesso aos componentes da interface do frame FrameBarras)
 */
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

/**
 * @name FrameExportar::~FrameExportar
 * @brief Destrutor da classe FrameExportar
 */
FrameExportar::~FrameExportar()
{
    delete ui;
}

/**
 * @name FrameExportar::inicializaFrame
 * @brief Primeiro método a ser chamada no construtor, responsável por chamar os métodos subsequêntes que modelam a Interface do frame.
 * @return void
 */
void FrameExportar::inicializaFrame(){
    inserirQssFrame();
}

/**
 * @name FrameExportar::inserirQssFrame
 * @brief Método responsável por chamar métodos que inserem Qss nos componentes do frame
 * @return void
 */
void FrameExportar::inserirQssFrame(){
    inserirQssImg();
    inserirQssRadioButton();
    inserirQssBtn();
}

/**
 * @name FrameExportar::inserirQssImg
 * @brief Método responsável por inserir um imagem ilustrativa no Frame e Qss nela.
 * @return void
 */
void FrameExportar::inserirQssImg(){
    Style style;
    ui->img->setPixmap(QPixmap(":/imgExportar/imgs/descritiva/relatorio.png"));
    ui->img->setStyleSheet(style.cssImgExportar);
}

/**
 * @name FrameExportar::inserirQssRadioButton
 * @brief Método responsável por inserir Qss no RadioButton
 * @return void
 */
void FrameExportar::inserirQssRadioButton(){
    Style style;
    ui->radioButtonCsv->setStyleSheet(style.cssRadioButton);
    ui->radioButtonPDF->setChecked(true);
    ui->radioButtonExcel->setStyleSheet(style.cssRadioButton);
    ui->radioButtonPDF->setStyleSheet(style.cssRadioButton);
}

/**
 * @name FrameExportar::inserirQssRadioButton
 * @brief Método responsável por inserir Qss nos botões exportar e voltar
 * @return void
 */
void FrameExportar::inserirQssBtn(){
    Style style;
    ui->btnExportar->setStyleSheet(style.cssBtn);
    ui->btnExportar->setIcon(QIcon(":/icons/imgs/icons/exportar.png"));
    ui->btnExportar->setLayoutDirection(Qt::RightToLeft);
    ui->btnVoltar->setStyleSheet(style.cssBtn);
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png"));
}

/**
 * @sa FrameExportar::on_btnVoltar_clicked
 * @brief Método responsável por implementar o evento do botão voltar
 * @return void
 */
void FrameExportar::on_btnVoltar_clicked()
{
    MainWindow::frameAtual = 2; //subtrai de 1 a variavel que conta em qua frame o usuario está
    MainWindow::atualizarStatus(frameMa); //atualiza a Barra de Status

    pa->show(); // mostra o Frame Anterior
    this->close(); //Fecha o frame atual
}

/**
 * @sa FrameExportar::on_btnExportar_clicked
 * @brief Método responsável por implementar o evento do botão Exportar.
 * Este método é responsável por verificar qual tipo de exportação foi escolhido e chamar o método responsável por aquela ação
 * @return void
 */
void FrameExportar::on_btnExportar_clicked()
{
    if(ui->radioButtonPDF->isChecked()){
        ExportacaoParaPdf();
    }else if(ui->radioButtonCsv->isChecked()){
        ExportacaoParaCsv();
    }else{
        ExportacaoParaExcel();
    }
}

/**
 * @name FrameExportar::ExportacaoParaPdf
 * @brief Método responsável por implementar a exportação para Pdf.
 * Este método é responsável por verificar quais foram os filtros escolhidos pelo usúario no frame anterior e direcionar para o método responsável pela exportação escolhida.
 */
void FrameExportar::ExportacaoParaPdf(){
    ExportarPdf pdf(pa);
    if(FiltrosBarra::indexComboBox == 0 ){
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            pdf.PdfInterBarrasTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            pdf.PdfInterBInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            pdf.PdfInterBarrasTodL1InterL2();
        }else{
            pdf.PdfInterBInterL1InterL2();
        }
    }else if(FiltrosBarra::indexComboBox == 1 ){
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            pdf.PdfCompBarrasaTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            pdf.PdfCompBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            pdf.PdfCompBarrasTodL1InterL2();
        }else{
            pdf.PdfCompBarrasInterL1InterL2();
        }
    }else{
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            pdf.PdfInfecBarrasTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            pdf.PdfInfecBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            pdf.PdfInfecBarrasTodL1InterL2();
        }else{
            pdf.PdfInfecBarrasInterL1InterL2();
        }
    }
}

/**
 * @name FrameExportar::ExportacaoParaExcel
 * @brief Método responsável por implementar a exportação para Excel.
 * Este método é responsável por verificar quais foram os filtros escolhidos pelo usúario no frame anterior e direcionar para o método responsável pela exportação escolhida.
 */
void FrameExportar::ExportacaoParaExcel(){
    ExportarExcel excel(pa);
    if(FiltrosBarra::indexComboBox == 0 ){
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            excel.ExcelInterBarrasTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            excel.ExcelInterBInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            excel.ExcelInterBarrasTodL1InterL2();
        }else{
            excel.ExcelInterBInterL1InterL2();
        }
    }else if(FiltrosBarra::indexComboBox == 1 ){
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            excel.ExcelCompBarrasaTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            excel.ExcelCompBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            excel.ExcelCompBarrasTodL1InterL2();
        }else{
            excel.ExcelCompBarrasInterL1InterL2();
        }
    }else{
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            excel.ExcelInfecBarrasTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            excel.ExcelInfecBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            excel.ExcelInfecBarrasTodL1InterL2();
        }else{
            excel.ExcelInfecBarrasInterL1InterL2();
        }
    }
}

/**
 * @name FrameExportar::ExportacaoParaCsv
 * @brief Método responsável por implementar a exportação para Csv.
 * Este método é responsável por verificar quais foram os filtros escolhidos pelo usúario no frame anterior e direcionar para o método responsável pela exportação escolhida.
 */
void FrameExportar::ExportacaoParaCsv(){
    ExportarCsv csv(pa);
    if(FiltrosBarra::indexComboBox == 0 ){
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            csv.CsvInterBarrasTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            csv.CsvInterBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            csv.CsvInterBarrasTodL1InterL2();
        }else{
            csv.CsvInterBarrasInterL1InterL2();
        }
    }else if(FiltrosBarra::indexComboBox == 1 ){
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            csv.CsvCompBarrasaTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            csv.CsvCompBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            csv.CsvCompBarrasTodL1InterL2();
        }else{
            csv.CsvCompBarrasInterL1InterL2();
        }
    }else{
        if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==0){
            csv.CsvInfecBarrasTodL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 1 && FiltroLinha::indexComboBoxDestino==0){
            csv.CsvInfecBarrasInterL1TodL2();
        }else if(FiltroLinha::indexComboBoxOrigem == 0 && FiltroLinha::indexComboBoxDestino==1){
            csv.CsvInfecBarrasTodL1InterL2();
        }else{
            csv.CsvInfecBarrasInterL1InterL2();
        }
    }
}




