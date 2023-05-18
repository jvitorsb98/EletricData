/**
 * @class ExportarExcel
 * @brief Classe responsável por realizar as exportações para csv
 * Classe sem atributos. Utilizada para realização de métodos
 * @author João Vitor N. Ramos
*/

#include "exportarexcel.h"
#include "filtrolinha.h"
#include "filtrosbarra.h"
#include "framebarras.h"
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>

/**
 * @variable QWidget *parentExportarExcel;
 * @brief Variavel que permite acessar seu parent. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
QWidget *parentExportarExcel;

/**
 * @name ExportarExcel::ExportarExcel
 * @brief Construtor da classe ExportarExcel
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 */
ExportarExcel::ExportarExcel(QWidget *parent)
{
    parentExportarExcel = parent;
}

/**
 * @name ExportarExcel::ExcelInterBInterL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarExcel::ExcelInterBInterL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha , linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1InterL2(planilha , linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInterBInterL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Um intervalo de barras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarExcel::ExcelInterBInterL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha , linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1TodL2(planilha , linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInterBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Um intervalo de barras, com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarExcel::ExcelInterBarrasTodL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha ,linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1InterL2(planilha , linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInterBarrasTodL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Um intervalo de barras, com todas as linhas.
 * @return void
 */
void ExportarExcel::ExcelInterBarrasTodL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasIntervalo(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelCompBarrasInterL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Escolha individual das barras, com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarExcel::ExcelCompBarrasInterL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelCompBarrasInterL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Escolha individual das barras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarExcel::ExcelCompBarrasInterL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelCompBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Escolha individual das barras, com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarExcel::ExcelCompBarrasTodL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelCompBarrasaTodL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : Escolha individual das barras, com todas as barras
 * @return void
 */
void ExportarExcel::ExcelCompBarrasaTodL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasComp(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInfecBarrasInterL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : As barras poluidoras , com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarExcel::ExcelInfecBarrasInterL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInfecBarrasInterL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarExcel::ExcelInfecBarrasInterL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLInterL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInfecBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas apenas nos detinos
 * @return void
 */
void ExportarExcel::ExcelInfecBarrasTodL1InterL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1InterL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}

/**
 * @name ExportarExcel::ExcelInfecBarrasTodL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar uma planilha e inserir a ela os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com todas as barras
 * @return void
 */
void ExportarExcel::ExcelInfecBarrasTodL1TodL2(){
    QXlsx::Document* planilha = criaPlanilha();
    int* linha = new int;
    ExcelEscreveBarrasInfec(planilha, linha);
    ExcelPulaLinha(linha);
    ExcelEscreveLTodL1TodL2(planilha, linha);
    salvaPlanilha(planilha);
    delete planilha;
    delete linha;
}


/**
 * @name ExportarExcel::ExcelEscreveBarrasIntervalo
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Um intervalo de barras
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveBarrasIntervalo(QXlsx::Document* saida, int* linha ){
    int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
    int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
    //Barras
    saida->write("A1","Barra");
    for(int i= inicio , pos = 1 ; i <= fim ; i++, pos++){
        saida->write(QString(numeroParaLetra(pos+1))+"1",QString::number(i+1));
    }
    *linha = 2;
    if(FiltrosBarra::tensaoPu){
        saida->write("A"+QString::number(*linha),"Tensão na Barra[pu]");
            int pos =1 ;
        for(int i= inicio ; i <= fim ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5));
            pos++;
        }
        (*linha)++;
    }
    if(FiltrosBarra::tensaoNominal){
        saida->write("A"+QString::number(*linha),"Tensão Nominal[kV]");
            int pos =1 ;
        for(int i= inicio ; i <= fim ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5));
            pos++;
        }
        (*linha)++;
    }
    if(FiltrosBarra::thdv){
        saida->write("A"+QString::number(*linha),"THDV[%]");
        int pos =1 ;
        for(int i= inicio ; i <= fim ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5));
            pos++;
        }
        (*linha)++;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j));
            int pos =1 ;
            for(int i= inicio ; i <= fim ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5));
                pos++;
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j)+"[%]");
            int pos =1 ;
            for(int i= inicio ; i <= fim ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5));
                pos++;
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        saida->write("A"+QString::number(*linha),"Tensao Eficaz[pu]");
        int pos =1 ;
        for(int i= inicio ; i <= fim ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5));
            pos++;
        }
        (*linha)++;
    }

}

/**
 * @name ExportarExcel::ExcelEscreveBarrasComp
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Uma escolha individual das barras
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveBarrasComp(QXlsx::Document* saida, int* linha){

    saida->write("A1","Barra");
    int pos = 1;
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                saida->write(QString(numeroParaLetra(pos+1))+"1",QString::number(i+1));
                pos++;
                break;
            }
        }
    }
    *linha = 2;
    if(FiltrosBarra::tensaoPu){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão na Barra[pu]");
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::tensaoNominal){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão Nominal[kV]");
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::thdv){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"THDV[%]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j));
            pos = 1;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5));
                        pos++;
                        break;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j)+"[%]");
            pos = 1;
            for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
                for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5));
                        pos++;
                        break;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensao Eficaz[pu]");
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5));
                    pos++;
                    break;
                }
            }
        }
        (*linha)++;
    }

}

/**
 * @name ExportarExcel::ExcelEscreveBarrasInfec
 * @brief Método responsável por imprimir em um arquivo pré-preparado : AS barras poluidoras
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveBarrasInfec(QXlsx::Document* saida, int* linha){
    saida->write("A1","Barra");
    int pos = 1 ;
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
            saida->write(QString(numeroParaLetra(pos+1))+"1",QString::number(i+1));
            pos++;
        }
    }
    *linha = 2;
    if(FiltrosBarra::tensaoPu){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão na Barra[pu]");
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
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::tensaoNominal){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensão Nominal[kV]");
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
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::thdv){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"THDV[%]");
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
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j));
            pos = 1;
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
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5));
                    pos++;
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(j)+"[%]");
            pos = 1;
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
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5));
                    pos++;
                }
            }
            (*linha)++;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Tensao Eficaz[pu]");
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
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5));
                pos++;
            }
        }
        (*linha)++;
    }
}

/**
 * @name ExportarExcel::ExcelEscreveLInterL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Uma escolha individual de linhas na origem e no destino
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveLInterL1InterL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos =1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
                        pos++;
                    }
                }
            }
        }
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            pos =1 ;
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5));
                                pos++;
                            }
                        }
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            pos =1 ;
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5));
                                pos++;
                            }
                        }
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Resistencia[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdasEficaz){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
                            pos++;
                        }
                    }
                }
            }
        }
        (*linha)++;
    }

}


/**
 * @name ExportarExcel::ExcelEscreveLInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Uma escolha individual de linhas apenas na origem
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveLInterL1TodL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos = 1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
                pos++;
            }
        }
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos = 1;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            pos =1 ;
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5));
                        pos++;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            pos =1 ;
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5));
                        pos++;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Resistencia[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdasEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
}

/**
 * @name ExportarExcel::ExcelEscreveLInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Uma escolha individual de linhas apenas no destino
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveLTodL1InterL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos = 1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
                pos++;
            }
        }
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos = 1 ;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos =1 ;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos =1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5));
                        pos++;                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos =1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5));
                        pos++;
                    }
                }
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Resistencia[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
                    pos++;
                }
            }
        }
        (*linha)++;
    }
}

/**
 * @name ExportarExcel::ExcelEscreveLInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Todas a linhas
 * @param saida
 * @param linha
 */
void ExportarExcel::ExcelEscreveLTodL1TodL2(QXlsx::Document* saida, int* linha){
    saida->write("A"+QString::number(*linha),"Linha");
    int pos = 1;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino));
        pos++;
    }
    (*linha)++;
    if(FiltroLinha::correntePu){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrente()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::dht){
        pos = 1;
        saida->write("A"+QString::number(*linha),"DHT[%]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDhtPercent()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos = 1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p));
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first));
                pos++;
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            pos = 1 ;
            saida->write("A"+QString::number(*linha),"TDI"+QString::number(p)+"[%]");
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second));
                pos++;
            }
            (*linha)++;
        }
    }
    if(FiltroLinha::correnteEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Corrente Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getCorrenteEficaz()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::resistencia){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Resistencia[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getResistencia()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::perdas){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdas()));
            pos++;
        }
        (*linha)++;
    }
    if(FiltroLinha::perdasEficaz){
        pos = 1;
        saida->write("A"+QString::number(*linha),"Perdas Eficaz[pu]");
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            saida->write(QString(numeroParaLetra(pos+1))+QString::number(*linha),QString::number(FrameBarras::linhas[i].getPerdasEficaz()));
            pos++;
        }
        (*linha)++;
    }
}

/**
 * @name ExportarExcel::criaPlanilha
 * @brief Método auxiliar responsável por iniciar uma planilha
 * @return uma planilha vazia do tipo QXlsx::Document*
 */
QXlsx::Document* ExportarExcel::criaPlanilha(){
    QXlsx::Document* planilha = new QXlsx::Document;
    return planilha;
}

/**
 * @name ExportarExcel::ExcelPulaLinha
 * @brief Método auxiliar responsável por pular 4 linhas no excel para dar um espaço entre as informações das barras e das linhas
 * @param linha
 */
void ExportarExcel::ExcelPulaLinha(int* linha){
    for(int i = 0 ; i < 4 ; i++){
        (*linha)++;
    }
}

/**
 * @name ExportarExcel::salvaPlanilha
 * @brief Método auxiliar responsável por salvar a planiha que em um local escolhido
 * @param saida
 */
void ExportarExcel::salvaPlanilha(QXlsx::Document* saida){
    QString filtro="Arquivo de planilha Excel. (*.xlsx)";
    QString localSalvamento =QFileDialog::getSaveFileName(parentExportarExcel,"Salvar Arquivo",QDir::homePath(),filtro);
    saida->saveAs(localSalvamento);
}


/**
 * @name ExportarExcel::numeroParaLetra
 * @brief Método auxiliar responsável por converter um numero de um indice em uma QString correspondente a uma posição da coluna do Excel.
 * @param numero
 * @return a Qstring convertida
 */
QString ExportarExcel::numeroParaLetra(int numero) {

    QString coluna = "";
    int resto;

    while (numero > 0) {
        resto = (numero - 1) % 26;
        coluna.prepend(QChar(resto + 'A'));
        numero = (numero - resto - 1) / 26;
    }

    return coluna;
}
