/**
 * @class ExportarPdf
 * @brief Classe responsável por realizar as exportações para pdf
 * Classe sem atributos. Utilizada para realização de métodos
 * @author João Vitor N. Ramos
*/

#include "exportarpdf.h"
#include "framebarras.h"
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>
#include <QFileDialog>
#include <QDebug>
#include <QFont>
#include <QUrl>
#include <QFontMetrics>

/**
 * @variable QWidget *parenteExportarPdf;
 * @brief Variavel que permite acessar seu parent. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
QWidget *parenteExportarPdf;

/**
 * @name ExportarPdf::ExportarPdf
 * @brief Construtor da classe ExportarPdf
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 */
ExportarPdf::ExportarPdf(QWidget *parent)
{
    parenteExportarPdf = parent;
}

/**
 * @name ExportarPdf::PdfInterBInterL1InterL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarPdf::PdfInterBInterL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInterBInterL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInterBInterL1TodL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : Um intervalo de barras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarPdf::PdfInterBInterL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInterBInterL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInterBarrasTodL1InterL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : Um intervalo de barras, com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarPdf::PdfInterBarrasTodL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInterBarrasTodL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInterBarrasTodL1TodL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : Um intervalo de barras, com todas as linhas
 * @return void
 */
void ExportarPdf::PdfInterBarrasTodL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInterBarrasTodL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfCompBarrasInterL1InterL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : Escolha individual das barras,com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarPdf::PdfCompBarrasInterL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContCompBarrasInterL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfCompBarrasInterL1TodL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : Escolha individual das barras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarPdf::PdfCompBarrasInterL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContCompBarrasInterL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfCompBarrasTodL1InterL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido :  Escolha individual das barras, com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarPdf::PdfCompBarrasTodL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContCompBarrasTodL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfCompBarrasaTodL1TodL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido :  Escolha individual das barras, com todas as linhas
 * @return void
 */
void ExportarPdf::PdfCompBarrasaTodL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContCompBarrasaTodL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInfecBarrasInterL1InterL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarPdf::PdfInfecBarrasInterL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasInterL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInfecBarrasInterL1TodL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarPdf::PdfInfecBarrasInterL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasInterL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInfecBarrasTodL1InterL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido :  As barras poluidoras, com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarPdf::PdfInfecBarrasTodL1InterL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasTodL1InterL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ExportarPdf::PdfInfecBarrasTodL1TodL2
 * @brief Método responsável por preparar um arquivo para exportação pdf e chamar o método responsável por imprimir no arquivo seguindo o seguinte filtro escolhido :  As barras poluidoras, com todas as linhas
 * @return void
 */
void ExportarPdf::PdfInfecBarrasTodL1TodL2(){
    QPrinter printer;
    printer.setPrinterName("PDF");

    QString filename = QFileDialog::getSaveFileName(parenteExportarPdf, "Salvar Arquivo", QDir::homePath(), "Arquivos PDF (*.pdf)");

    if (filename.isEmpty()) {
        return;
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ContInfecBarrasTodL1TodL2(&printer);

    QDesktopServices::openUrl(QUrl(filename));
}

/**
 * @name ContInterBInterL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Um intervalo de barras,com escolha individual de linhas na origem e no destino
 * @param printer
 * @return void
 */
void ExportarPdf::ContInterBInterL1InterL2(QPrinter* printer){
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

    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
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
                            atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
                }
            }
        }
    }

    painter.end();
}


/**
 * @name ContInterBInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Um intervalo de barras, com escolha individual de linhas apenas nas origens
 * @param printer
 * @return void
 */
void ExportarPdf::ContInterBInterL1TodL2(QPrinter* printer){
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
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
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
                    atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
        }
    }

    painter.end();
}

/**
 * @name ContInterBarrasTodL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Um intervalo de barras, com escolha individual de linhas apenas nos destinos
 * @param printer
 * @return void
 */
void ExportarPdf::ContInterBarrasTodL1InterL2(QPrinter* printer){
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

    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
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
                    atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
        }
    }

    painter.end();
}

/**
 * @name ContInterBarrasTodL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Um intervalo de barras, com todas as linhas
 * @param printer
 * @return void
 */
void ExportarPdf::ContInterBarrasTodL1TodL2(QPrinter* printer){
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
            atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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

/**
 * @name ContCompBarrasInterL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Escolha individual das barras,com escolha individual de linhas na origem e no destino
 * @param printer
 * @return void
 */
void ExportarPdf::ContCompBarrasInterL1InterL2(QPrinter* printer){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
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
        }
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

    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
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
                            atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
                }
            }
        }
    }

    painter.end();
}

/**
 * @name ContCompBarrasInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Escolha individual das barras, com escolha individual de linhas apenas nas origens
 * @param printer
 * @return void
 */
void ExportarPdf::ContCompBarrasInterL1TodL2(QPrinter* printer){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
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
        }
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
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
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
                    atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
        }
    }

    painter.end();
}

/**
 * @name ContCompBarrasTodL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Escolha individual das barras, com escolha individual de linhas apenas nos destinos
 * @param printer
 * @return void
 */
void ExportarPdf::ContCompBarrasTodL1InterL2(QPrinter* printer ){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
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
        }
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

    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
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
                    atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
        }
    }

    painter.end();
}

/**
 * @name ContCompBarrasaTodL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Escolha individual das barras, com todas as linhas
 * @param printer
 * @return void
 */
void ExportarPdf::ContCompBarrasaTodL1TodL2(QPrinter* printer){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
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
        }
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
            atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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

/**
 * @name ContInfecBarrasInterL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : As barras poluidoras, com escolha individual de linhas na origem e no destino
 * @param printer
 * @return void
 */
void ExportarPdf::ContInfecBarrasInterL1InterL2(QPrinter* printer){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


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

    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
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
                            atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
                }
            }
        }
    }

    painter.end();
}

/**
 * @name ContInfecBarrasInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : As barras poluidoras, com escolha individual de linhas apenas nas origens
 * @param printer
 * @return void
 */
void ExportarPdf::ContInfecBarrasInterL1TodL2(QPrinter* printer){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


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
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
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
                    atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
        }
    }

    painter.end();
}

/**
 * @name ContInfecBarrasTodL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : As barras poluidoras,  com escolha individual de linhas apenas nos destinos
 * @param printer
 * @return void
 */
void ExportarPdf::ContInfecBarrasTodL1InterL2(QPrinter* printer ){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


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

    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
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
                    atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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
        }
    }

    painter.end();
}

/**
 * @name ContInfecBarrasTodL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : As barras poluidoras,  com todas as linhas
 * @param printer
 * @return void
 */
void ExportarPdf::ContInfecBarrasTodL1TodL2(QPrinter* printer){
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

    QLinearGradient gradient = QLinearGradient(0, 0, 0, 50);
    gradient.setColorAt(0, QColor(180, 235, 249));
    gradient.setColorAt(1, QColor(30, 56, 91));
    painter.setBrush(QBrush(gradient));
    //estilo da fonte do header
    QFont fontHeader("Roboto",16,QFont::Bold);

    // Define o estilo da fonte
    QFont fontConteudo("Roboto",12);

    int inicioItem = 100;


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
            atributos += "<p><b>Resistencia[pu]:</b> %1</p>";
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


/**
 * @name ExportarPdf::QtdLinhasInfoBarra
 * @brief cálcula numero de linhas que serão escritas no pdf para elencar os atributos escolhidos para uma barra apartir do filtro.
 * @return um inteiro que representa o numero de linhas que serão escritas no pdf para elencar os atributos escolhidos para uma barra apartir do filtro.
 */
int ExportarPdf::QtdLinhasInfoBarra(){
    int linhas = 0 ;

    linhas += (int)FiltrosBarra::tensaoPu;
    linhas += (int)FiltrosBarra::tensaoNominal;
    linhas += (int)FiltrosBarra::thdv;
    linhas += (int)FiltrosBarra::dit * (FrameBarras::quantidadeDeComponentesHarm);
    linhas += (int)FiltrosBarra::ditPercent * (FrameBarras::quantidadeDeComponentesHarm);
    linhas += (int)FiltrosBarra::tensaoEficaz;

    return linhas;
}

/**
 * @name ExportarPdf::QtdLinhasInfoLinha
 * @brief cálcula numero de linhas que serão escritas no pdf para elencar os atributos escolhidos para uma linha apartir do filtro.
 * @return um inteiro que representa o numero de linhas que serão escritas no pdf para elencar os atributos escolhidos para uma linha apartir do filtro.
 */
int ExportarPdf::QtdLinhasInfoLinha(){
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

