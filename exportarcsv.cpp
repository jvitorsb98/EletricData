/**
 * @class ExportarCsv
 * @brief Classe responsável por realizar as exportações para csv
 * Classe sem atributos. Utilizada para realização de métodos
 * @author João Vitor N. Ramos
*/

#include "exportarcsv.h"
#include "filtrolinha.h"
#include "filtrosbarra.h"
#include "framebarras.h"
#include "frametensoes.h"
#include <QFileDialog>
#include <QMessageBox>

/**
 * @variable QWidget *parentExportarCsv;
 * @brief Variavel que permite acessar seu parent. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
QWidget *parentExportarCsv;

/**
 * @name ExportarCsv::ExportarCsv
 * @brief Construtor da classe ExportarCsv
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 */
ExportarCsv::ExportarCsv(QWidget *parent)
{
    parentExportarCsv = parent;
}


/**
 * @name ExportarCsv::CsvInterBarrasInterL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarCsv::CsvInterBarrasInterL1InterL2(){

    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);

    CsvEscreveBarrasIntervalo(&saida);
    CsvEscreveLInterL1InterL2(&saida);
    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInterBarrasInterL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas apenas na origem
 * @return void
 */
void ExportarCsv::CsvInterBarrasInterL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);

    CsvEscreveBarrasIntervalo(&saida);
    CsvEscreveLInterL1TodL2(&saida);

    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInterBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas apenas no destino
 * @return void
 */
void ExportarCsv::CsvInterBarrasTodL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);

    CsvEscreveBarrasIntervalo(&saida);
    CsvEscreveLTodL1InterL2(&saida);

    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInterBarrasTodL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Escolha individual das barras,com todas as linhas
 * @return void
 */
void ExportarCsv::CsvInterBarrasTodL1TodL2(){

    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasIntervalo(&saida);
    CsvEscreveLTodL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();

}

/**
 * @name ExportarCsv::CsvCompBarrasInterL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarCsv::CsvCompBarrasInterL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLInterL1InterL2(&saida);
    //Linhas
    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvCompBarrasInterL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarCsv::CsvCompBarrasInterL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLInterL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvCompBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarCsv::CsvCompBarrasTodL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLTodL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();

}

/**
 * @name ExportarCsv::CsvCompBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : Um intervalo de barras,com todas as linhas
 * @return void
 */
void ExportarCsv::CsvCompBarrasaTodL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasComp(&saida);
    CsvEscreveLTodL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInfecBarrasInterL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarCsv::CsvInfecBarrasInterL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLInterL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInfecBarrasInterL1TodL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas apenas nas origens
 * @return void
 */
void ExportarCsv::CsvInfecBarrasInterL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLInterL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInfecBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com escolha individual de linhas apenas nos destinos
 * @return void
 */
void ExportarCsv::CsvInfecBarrasTodL1InterL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLTodL1InterL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvInfecBarrasTodL1InterL2
 * @brief Método responsável por realizar chamada de métodos que irão criar um arquivo e inserir a ele os dados seguindo o seguinte filtro escolhido : As barras poluidoras, com todas as barras
 * @return void
 */
void ExportarCsv::CsvInfecBarrasTodL1TodL2(){
    QFile *arquivoSaida = criaArquivo();
    QTextStream saida(arquivoSaida);
    CsvEscreveBarrasInfec(&saida);
    CsvEscreveLTodL1TodL2(&saida);


    arquivoSaida->flush();
    arquivoSaida->close();
}

/**
 * @name ExportarCsv::CsvEscreveBarrasIntervalo
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Um intervalo de Barras
 * @return void
 */
void ExportarCsv::CsvEscreveBarrasIntervalo(QTextStream* saida){
    int inicio = FiltrosBarra::indiceBarrasEscolhidas.at(0).toInt()-1;
    int fim = FiltrosBarra::indiceBarrasEscolhidas.at(1).toInt()-1;
    //Barras
    *saida << "Barra" ;
    for(int i= inicio ; i <= fim ; i++){
        *saida << ","+QString::number(i+1);
    } *saida << Qt::endl;
    if(FiltrosBarra::tensaoPu){
        *saida << "Tensao na Barra[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
        } *saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        *saida << "Tensao Nominal[kV]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
        } *saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        *saida << "THDV[%]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
        } *saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int i= inicio ; i <= fim ; i++){
                *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
            } *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[%]" ;
            for(int i= inicio ; i <= fim ; i++){
                *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
            } *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        *saida << "Tensao Eficaz[pu]" ;
        for(int i= inicio ; i <= fim ; i++){
            *saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
        } *saida << Qt::endl;
    }

    for(int i = 0 ; i < 4 ; i++){
        *saida << Qt::endl;
    }
}

/**
 * @name ExportarCsv::CsvEscreveBarrasComp
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Escolha individual das barras
 * @return void
 */
void ExportarCsv::CsvEscreveBarrasComp(QTextStream* saida){
    *saida << "Barra";
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
            if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                *saida << ","+QString::number(i+1);
                break;
            }
        }
    }
    *saida << Qt::endl;

    if(FiltrosBarra::tensaoPu){
        *saida << "Tensao na Barra[pu]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    *saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
                    break;
                }
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        *saida << "Tensao Nominal[kV]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    *saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
                    break;
                }
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        *saida << "THDV[%]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    *saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
                    break;
                }
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[pu]" ;
            for(int k = 0 ; k < FrameTensoes::numeroDeBarras ; k++){
                for(int p = 0 ; p < FiltrosBarra::indiceBarrasEscolhidas.size() ; p++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(p).toInt()-1) == k ){
                        *saida << ","+QString::number(FrameBarras::barras[k].getDti().find(j)->second.first.first,'f',5);
                        break;
                    }
                }
            }
            *saida << Qt::endl;
        }
    }

    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[%]" ;
            for(int k = 0 ; k < FrameTensoes::numeroDeBarras ; k++){
                for(int p = 0 ; p < FiltrosBarra::indiceBarrasEscolhidas.size() ; p++){
                    if((FiltrosBarra::indiceBarrasEscolhidas.at(p).toInt()-1) == k ){
                        *saida << ","+QString::number(FrameBarras::barras[k].getDti().find(j)->second.first.second,'f',5);
                        break;
                    }
                }
            }
            *saida << Qt::endl;
        }
    }

    if(FiltrosBarra::tensaoEficaz){
        *saida << "Tensao Eficaz[pu]" ;
        for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            for(int j = 0 ; j < FiltrosBarra::indiceBarrasEscolhidas.size() ; j++){
                if((FiltrosBarra::indiceBarrasEscolhidas.at(j).toInt()-1) == i ){
                    *saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
                    break;
                }
            }
        }
        *saida << Qt::endl;
    }


}

/**
 * @name ExportarCsv::CsvEscreveBarrasInfec
 * @brief Método responsável por imprimir em um arquivo pré-preparado : As barras poluidoras
 * @return void
 */
void ExportarCsv::CsvEscreveBarrasInfec(QTextStream* saida){
    *saida << "Barra";
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
            *saida << ","+QString::number(i+1);
        }
    }
    *saida << Qt::endl;
    if(FiltrosBarra::tensaoPu){
        *saida << "Tensao na Barra[pu]" ;
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
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoPu(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::tensaoNominal){
        *saida << "Tensao Nominal[kV]" ;
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
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoNominalKv(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::thdv){
        *saida << "THDV[%]" ;
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
                *saida << ","+QString::number(FrameBarras::barras[i].getThdvPercent(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
    if(FiltrosBarra::dit){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[pu]" ;
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
                    *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.first,'f',5);
                }
            }
            *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::ditPercent){
        for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
            *saida << "TDI"+QString::number(j)+"[%]" ;
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
                    *saida << ","+QString::number(FrameBarras::barras[i].getDti().find(j)->second.first.second,'f',5);
                }
            }
            *saida << Qt::endl;
        }
    }
    if(FiltrosBarra::tensaoEficaz){
        *saida << "THDV[%]" ;
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
                *saida << ","+QString::number(FrameBarras::barras[i].getTensaoEficaz(),'f',5);
            }
        }
        *saida << Qt::endl;
    }
}

/**
 * @name ExportarCsv::CsvEscreveLInterL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : A escolha individual de linhas na origem e no destino
 * @return void
 */
void ExportarCsv::CsvEscreveLInterL1InterL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
                    }
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                        }
                    }
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                        }
                    }
                }
            }
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                            }
                        }
                    }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                                *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                            }
                        }
                    }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                        }
                    }
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                        }
                    }
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                        }
                    }
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                        if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                            *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                        }
                    }
                }
            }
        }
    }
    *saida << Qt::endl;

}

/**
 * @name ExportarCsv::CsvEscreveLInterL1TodL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : A escolha individual de linhas apenas na origem
 * @return void
 */
void ExportarCsv::CsvEscreveLInterL1TodL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
            if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino,'f',5);
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                }
            }
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                    }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
                for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                    if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                        *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                    }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
            for( int j = 0 ; j < FiltroLinha::indiceOrigensEscolhidas.size() ; j++){
                if(FiltroLinha::indiceOrigensEscolhidas.at(j).toInt() == barraDeOrigem){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

}

/**
 * @name ExportarCsv::CsvEscreveLTodL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : A escolha individual de linhas apenas no destino
 * @return void
 */
void ExportarCsv::CsvEscreveLTodL1InterL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
            if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
                }
            }
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
                    }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                int barraDeDestino = FrameBarras::linhas[i].getDestino();
                for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                    if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                        *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
                    }
                }
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            int barraDeDestino = FrameBarras::linhas[i].getDestino();
            for( int k = 0 ; k < FiltroLinha::indiceDestinosEscolhidos.size() ; k++){
                if(FiltroLinha::indiceDestinosEscolhidos.at(k).toInt() == barraDeDestino){
                    *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
                }
            }
        }
    }
    *saida << Qt::endl;
}

/**
 * @name ExportarCsv::CsvEscreveLTodL1InterL2
 * @brief Método responsável por imprimir em um arquivo pré-preparado : Todas as linhas
 * @return void
 */
void ExportarCsv::CsvEscreveLTodL1TodL2(QTextStream* saida){
    *saida << "Linha" ;
    for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        int barraDeOrigem = FrameBarras::linhas[i].getOrigem();
        int barraDeDestino = FrameBarras::linhas[i].getDestino();
        *saida << ","+QString::number(barraDeOrigem)+"->"+QString::number(barraDeDestino);
    }
    *saida << Qt::endl;
    if(FiltroLinha::correntePu){
        *saida << "Corrente[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getCorrente(),'f',5);
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::dht){
        *saida << "DHT[%]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getDhtPercent(),'f',5);
        }
    }
    *saida <<Qt::endl;
    if(FiltroLinha::dit){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p);
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.first,'f',5);
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::ditPercent){
        for(int p = 3 ; p <= FrameBarras::indiceHarmMax ; p+=2){
            *saida << "DHT"+QString::number(p)+"[%]";
            for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
                *saida << ","+QString::number(FrameBarras::linhas[i].getDti().find(p)->second.second,'f',5);
            }
            *saida <<Qt::endl;
        }
    }
    if(FiltroLinha::correnteEficaz){
        *saida << "Corrente Eficaz[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getCorrenteEficaz(),'f',5);
        }
    }
    *saida << Qt::endl;
    if(FiltroLinha::resistencia){
        *saida << "Resistencia[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getResistencia(),'f',5);
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdas){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getPerdas(),'f',5);
        }
    }
    *saida << Qt::endl;

    if(FiltroLinha::perdasEficaz){
        *saida << "Perdas[pu]";
        for( int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
            *saida << ","+QString::number(FrameBarras::linhas[i].getPerdasEficaz(),'f',5);
        }
    }
    *saida << Qt::endl;
}


/**
 * @name ExportarCsv::criaArquivo
 * @brief Método auxiliar responsável por criar um arquvo e setar um local de salvamento
 * @return um arquivo vazio do tipo QFile*
 */
QFile* ExportarCsv::criaArquivo(){
    //Configura-se um filtro para pesquisa do diretorio
    QFile *arquivoSaida = new QFile();
    QString filtro="Arquivos separados por virgula (*.csv)";
    QString localSalvamento =QFileDialog::getSaveFileName(parentExportarCsv,"Salvar Arquivo",QDir::homePath(),filtro);
    arquivoSaida->setFileName(localSalvamento);
    if(!arquivoSaida->open(QFile::WriteOnly | QFile::Text)){
        if(arquivoSaida->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return nullptr;
        }
        QMessageBox::warning(parentExportarCsv,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return nullptr;
    }

    return arquivoSaida;

}


