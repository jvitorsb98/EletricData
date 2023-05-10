#include "framebarras.h"
#include "ui_framebarras.h"
#include "style.h"
#include<QMessageBox>
#include<QDebug>
#include<QCoreApplication>
#include<QtMath>
#include "Barra.h"

std::map<int , std::map<int , double >> limitesDti;
FrameBarras::FrameBarras(QWidget *parent,Ui::MainWindow *mw,Ui::FrameTensoes *ft) :
    QFrame(parent),
    ui(new Ui::FrameBarras)
{
    ui->setupUi(this);
    QList<Barra> barras;
    QList<Linha> linhas;
    int indiceharmonicoMax = buscaIndiceHarmMax() ;
    int quantidadeDeComponentesHarm = buscaQtdHarm(indiceharmonicoMax);
    int numeroDeBarras = quantidadeDeBarras();

    preencheLimites();

    barras = inicializaBarra(barras,numeroDeBarras);
    barras = preencheBarra(barras,numeroDeBarras,quantidadeDeComponentesHarm);
    insereQssFrameBarras( numeroDeBarras ,  quantidadeDeComponentesHarm);
    preencheTabela(barras, numeroDeBarras, indiceharmonicoMax);
    insereBackgroundNasPoluidoras(numeroDeBarras,indiceharmonicoMax,barras);
    insereQssTableLinhas(linhasDoSistema().size(),quantidadeDeComponentesHarm);
    ui->tableLinhas->setHorizontalHeaderLabels(linhasDoSistema());
    linhas = inicializaLinha(linhas,linhasDoSistema().size());
    linhas = preencheLinha(linhas, linhasDoSistema().size(),quantidadeDeComponentesHarm);
    preencheTabela(linhas,linhasDoSistema().size(),indiceharmonicoMax);

}


FrameBarras::~FrameBarras()
{
    delete ui;
}

void FrameBarras::preencheTabela(QList<Linha> linhas, int numeroDeLinhas, int indiceharmonicoMax){
    for(int i = 0 ; i < numeroDeLinhas ; i++){
        QTableWidgetItem* correntePu = new QTableWidgetItem(QString::number(linhas[i].getCorrente(),'f',5));
        QTableWidgetItem* dht = new QTableWidgetItem(QString::number(linhas[i].getDhtPercent(),'f',5));
        ui->tableLinhas->setItem(0,i,correntePu);
        ui->tableLinhas->setItem(1,i,dht);
        int pos =2;
        for(int j = 3 ; j <= indiceharmonicoMax ; j+=2){
            QTableWidgetItem* dtiAbsolut = new QTableWidgetItem(QString::number(linhas[i].getDti().find(j)->second.first,'g',5));
            ui->tableLinhas->setItem(pos,i,dtiAbsolut);
            pos++;
        }
        for(int j = 3 ; j <= indiceharmonicoMax ; j+=2){
            QTableWidgetItem* dtiRelative = new QTableWidgetItem(QString::number(linhas[i].getDti().find(j)->second.second,'f',5));
            ui->tableLinhas->setItem(pos,i,dtiRelative);
            pos++;
        }
        QTableWidgetItem* correnteEficaz = new QTableWidgetItem(QString::number(linhas[i].getCorrenteEficaz(),'f',5));
        ui->tableLinhas->setItem(pos,i,correnteEficaz);
        pos++;

        QTableWidgetItem* resistencia = new QTableWidgetItem(QString::number(linhas[i].getResistencia(),'f',5));
        ui->tableLinhas->setItem(pos,i,resistencia);
        pos++;

        QTableWidgetItem* perdas = new QTableWidgetItem(QString::number(linhas[i].getPerdas(),'f',5));
        ui->tableLinhas->setItem(pos,i,perdas);
        pos++;

        QTableWidgetItem* perdasEficaz = new QTableWidgetItem(QString::number(linhas[i].getPerdasEficaz(),'f',5));
        ui->tableLinhas->setItem(pos,i,perdasEficaz);
        pos++;


    }
}
QStringList FrameBarras::cabecalhoLinhas(int quantidadeDeComponentesHarm){
    QStringList cabecalhos={"Corrente na Linha[pu]","THT[%]"};
                               for(int i = 0 , j = 3; i < quantidadeDeComponentesHarm ; i++ , j+=2){
                                                                                                    QString item = "DIT"+QString::number(j);
    cabecalhos.push_back(item);
}
for(int i = 0 , j = 3; i < quantidadeDeComponentesHarm ; i++ , j+=2){
    QString item = "DIT"+QString::number(j)+"[%]";
    cabecalhos.push_back(item);
}
cabecalhos.push_back("Corrente Eficaz[pu]");
cabecalhos.push_back("Resistencia[ohm");
cabecalhos.push_back("Perdas[pu]");
cabecalhos.push_back("Perdas eficaz[pu]");

    return cabecalhos;
}
QList<Linha> FrameBarras::preencheLinha(QList<Linha> linhas , int quantidadeDeLinhas, int quantidadeDeComponentesHarm){
    if(!MainWindow::arquivoThdi->open(QFile::ReadOnly|QFile::Text)){
    if(MainWindow::arquivoThdi->error() == QFile::OpenError){
        return linhas ;
    }
    QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
    return linhas ;
    }

    for(int i = 0 ; i < 2 ; i++){
    MainWindow::arquivoThdi->readLine();
    }
    int origem , destino;
    double corrente , dht;
    int cont=0;
    double correnteEficaz;
    while(!MainWindow::arquivoThdi->atEnd()){
        QString line = MainWindow::arquivoThdi->readLine();
        QStringList indice = line.split(",");
        origem = indice.at(0).trimmed().toInt();
        destino = indice.at(2).trimmed().toInt();
        corrente = indice.at(5).trimmed().toDouble();
        dht = indice.at(6).trimmed().toDouble();
        correnteEficaz = corrente*sqrt(1+ potencia((dht/100),2));

        if(origem < destino){
            linhas[cont].setOrigem(origem);
            linhas[cont].setDestino(destino);
            linhas[cont].setCorrente(corrente);
            linhas[cont].setDhtPercent(dht);
            linhas[cont].setCorrenteEficaz(correnteEficaz);
            cont++;
        }
    }

    MainWindow::arquivoThdi->close();

    if(!MainWindow::arquivoIsoln->open(QFile::ReadOnly|QFile::Text)){
        if(MainWindow::arquivoIsoln->error() == QFile::OpenError){
            return linhas ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return linhas ;
    }

    for(int i = 0 ; i < 4 ; i++){
        QString line = MainWindow::arquivoIsoln->readLine();
    }

    int numHarm;
    double magHarm;
    double percentHarm;
    cont = 1;
    qDebug() << quantidadeDeComponentesHarm << "\n" << quantidadeDeLinhas << "\n";

    for(int i = 0 ; i < quantidadeDeComponentesHarm ; i++){
        for(int j = 0 ; j < quantidadeDeLinhas ; ){
            QString line = MainWindow::arquivoIsoln->readLine();
            if (line.trimmed().isEmpty()) { // verificar se é uma linha vazia
                break;
            }
            QStringList indice = line.split(",");
            numHarm = indice.at(0).trimmed().toInt();
            origem = indice.at(1).trimmed().toInt();
            destino = indice.at(2).trimmed().toInt();
            magHarm = indice.at(4).trimmed().toDouble();
            percentHarm = 100 * (magHarm / linhas[j].getCorrente());
            if (numHarm != 1 && origem < destino && origem !=0 && destino!=0) {
                linhas[j].setDti(numHarm, magHarm, percentHarm);
                qDebug() << "\nnum Harm: " << linhas[j].getDti().find(numHarm)->first << "\nOrigem: " << origem << "\nDestino: " << destino << "\nMagHarm: " << linhas[j].getDti().find(numHarm)->second.first << "percentHarm: " << linhas[j].getDti().find(numHarm)->second.second;
                j++;
            }
        }
    }


    MainWindow::arquivoIsoln->close();

    if(!MainWindow::arquivoLdat->open(QFile::ReadOnly|QFile::Text)){
        if(MainWindow::arquivoLdat->error() == QFile::OpenError){
            return linhas ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return linhas ;
    }

    for(int i = 0 ; i < 9 ; i++){
        MainWindow::arquivoLdat->readLine();
    }
    double resistencia;
    double perdas;
    double perdasEficaz;
    for(int i = 0 ; i < quantidadeDeLinhas ; i++){
        QString line = MainWindow::arquivoLdat->readLine();
        if (line.trimmed().isEmpty()) { // verificar se é uma linha vazia
            break;
        }
        QStringList indice = line.split(",");
        if(indice.at(0).trimmed().toInt() > indice.at(1).trimmed().toInt()){
            origem = indice.at(1).trimmed().toInt();
            destino = indice.at(0).trimmed().toInt();
        }else{
            origem = indice.at(0).trimmed().toInt();
            destino = indice.at(1).trimmed().toInt();
        }
        resistencia = indice.at(3).trimmed().toDouble();

        for(int j = 0 ; j < quantidadeDeLinhas ; j++){
            if(linhas[j].getOrigem() == origem && linhas[j].getDestino() == destino){
                linhas[j].setResistencia(resistencia);
                perdas = linhas[j].getCorrente()*resistencia;
                perdasEficaz = linhas[j].getCorrenteEficaz()*resistencia;
                linhas[j].setPerdas(perdas);
                linhas[j].setPerdasEficaz(perdasEficaz);
            }
        }

    }

    MainWindow::arquivoLdat->close();

    return linhas;
}
QStringList FrameBarras::linhasDoSistema(){
    int origem;
    int destino;
    QStringList linhas;
    if(!MainWindow::arquivoThdi->open(QFile::ReadOnly|QFile::Text)){
    if(MainWindow::arquivoThdi->error() == QFile::OpenError){
            return QStringList();
    }
    QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
    return QStringList();
    }

    for(int i = 0 ; i < 2 ; i++){
        MainWindow::arquivoThdi->readLine();
    }

    while(!MainWindow::arquivoThdi->atEnd()){
        QString line = MainWindow::arquivoThdi->readLine();
        QStringList indice = line.split(",");
        origem = indice.at(0).trimmed().toInt();
        destino = indice.at(2).trimmed().toInt();
        if(origem < destino){
            QString item = QString::number(origem) +" -> "+QString::number(destino);
            linhas.push_back(item);
        }
    }
    MainWindow::arquivoThdi->close();
    return linhas;


}
void FrameBarras::preencheTabela(QList<Barra> barras, int numeroDeBarras, int indiceharmonicoMax){
    for(int i = 0 ; i < numeroDeBarras ; i++){
        QTableWidgetItem* tensaoPu = new QTableWidgetItem(QString::number(barras[i].getTensaoPu(),'f',5));
        QTableWidgetItem* tensaoNominal = new QTableWidgetItem(QString::number(barras[i].getTensaoNominalKv(),'f',5));
        QTableWidgetItem* thdv = new QTableWidgetItem(QString::number(barras[i].getThdvPercent(),'f',5));
        ui->tableBarras->setItem(0,i, tensaoPu);
        ui->tableBarras->setItem(1,i,tensaoNominal);
        ui->tableBarras->setItem(2,i,thdv);
        int pos =3;
        for(int j = 3 ; j <= indiceharmonicoMax ; j+=2){
            QTableWidgetItem* dtiAbsolut = new QTableWidgetItem(QString::number(barras[i].getDti().find(j)->second.first.first,'g',5));
            ui->tableBarras->setItem(pos,i,dtiAbsolut);
            pos++;
        }
        for(int j = 3 ; j <= indiceharmonicoMax ; j+=2){
            QTableWidgetItem* dtiRelative = new QTableWidgetItem(QString::number(barras[i].getDti().find(j)->second.first.second,'g',5));
            ui->tableBarras->setItem(pos,i,dtiRelative);
            pos++;
        }
        QTableWidgetItem* tensaoEficaz = new QTableWidgetItem(QString::number(barras[i].getTensaoEficaz(),'f',5));
        ui->tableBarras->setItem(pos,i,tensaoEficaz);
    }

}
void FrameBarras::insereQssFrameBarras(int numeroDeBarras , int quantidadeDeComponentesHarm){
    insereQssBtnAvancar();
    insereQssBtnVoltar();
    insereQssTabWidget();
    insereQssTableBarras(numeroDeBarras,quantidadeDeComponentesHarm);
}
void FrameBarras::insereQssBtnAvancar(){
    Style style;
    ui->btnAvancar->setStyleSheet(style.cssBtn);
    ui->btnAvancar->setIcon(QIcon(":/icons/imgs/icons/proximo.png")); //insere um icon ao botão
    ui->btnAvancar->setLayoutDirection(Qt::RightToLeft); //define que o icon será colocado após o texto
}
void FrameBarras::insereQssBtnVoltar(){
    Style style;
    ui->btnVoltar->setStyleSheet(style.cssBtn);
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png"));
}
void FrameBarras::insereQssTabWidget(){
    Style style;
    ui->tabLinhas->setStyleSheet(style.cssTabWidget);
}
void FrameBarras::insereQssTableBarras(int numeroDeBarras , int quantidadeDeComponentesHarm){
    Style style;
    //Inserindo cabeçalho vertical na priemira coluna
    ui->tableBarras->setRowCount(3 + 2*quantidadeDeComponentesHarm + 1);
    ui->tableBarras->setColumnCount(numeroDeBarras);
    ui->tableBarras->setVerticalHeaderLabels(cabecalhoBarras(quantidadeDeComponentesHarm));
    ui->tableBarras->setStyleSheet(style.cssTabelaBarras); //insere QSS na tabela
    ui->tableBarras->verticalHeader()->setStyleSheet(style.cssHeaderTabela);
    ui->tableBarras->verticalHeader()->setLineWidth(1);
    //insere um numero de linhas à tabela correspondente ao numero de Barras
    ui->tableBarras->horizontalHeader()->setVisible(true);
    ui->tableBarras->setAlternatingRowColors(true); //aplica anternacia de cores na tabela
    ui->tableBarras->verticalHeader()->setDefaultSectionSize(30);
    for(int i = 0 ; i < (3 + 2*quantidadeDeComponentesHarm + 1) ; i++){
        ui->tableBarras->setRowHeight(i, 31);
    }
    ui->tableBarras->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}
void FrameBarras::insereQssTableLinhas(int numeroDeLinhas,int quantidadeDeComponentesHarm){
    Style style;
    ui->tableLinhas->setRowCount(2 + 2*quantidadeDeComponentesHarm + 4);
    ui->tableLinhas->setColumnCount(numeroDeLinhas);
    ui->tableLinhas->setVerticalHeaderLabels(cabecalhoLinhas(quantidadeDeComponentesHarm));
    ui->tableLinhas->setStyleSheet(style.cssTabelaBarras); //insere QSS na tabela
    ui->tableLinhas->verticalHeader()->setStyleSheet(style.cssHeaderTabela);
    ui->tableLinhas->verticalHeader()->setLineWidth(1);
    ui->tableLinhas->horizontalHeader()->setVisible(true);
    ui->tableLinhas->setAlternatingRowColors(true); //aplica anternacia de cores na tabela
    ui->tableLinhas->verticalHeader()->setDefaultSectionSize(30);
    for(int i = 0 ; i < (2 + 2*quantidadeDeComponentesHarm + 4) ; i++){
        ui->tableLinhas->setRowHeight(i, 31);
    }
    ui->tableBarras->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}
QList<Linha> FrameBarras::inicializaLinha(QList<Linha>linhas, int numeroDeLinhas){
    for(int i = 0 ; i < numeroDeLinhas ; i++){
        Linha linha;
        linhas.push_back(linha);
    }
    return linhas;
}
QList<Barra> FrameBarras::inicializaBarra(QList<Barra>barras,int numeroDeBarras){
    for(int i = 0 ; i < numeroDeBarras ; i++){
        Barra barra;
        barras.push_back(barra);
    }
    return barras;
}
QList<Barra> FrameBarras::preencheBarra(QList<Barra> barras, int numeroDeBarras, int quantidadeDeComponentesHarm){

    //O arquivo thdv possui uma linha de informa~ção para cada barra -- por isso foi selecionado
    //realiza o procedimento de abertura do arquivo e alerta caso aconteça algum erro -- Conforme explicado no mainwindow.cpp
    if(!MainWindow::arquivoThdv->open(QFile::ReadOnly|QFile::Text)){
        if(MainWindow::arquivoThdv->error() == QFile::OpenError){
            return barras ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return barras ;
    }

    for(int i = 0 ; i < 2 ; i++){
        MainWindow::arquivoThdv->readLine();
    }

    for(int i = 0 ; i < numeroDeBarras ; i++){
        QString line = MainWindow::arquivoThdv->readLine();
        QStringList indice = line.split(",");
        bool ok = false; // inicializa com 'false' indicando que a conversão falhou
        double tensaoPu = indice.at(2).trimmed().toDouble(&ok);
        if(ok){
            barras[i].setTensaoPu(tensaoPu);
        }
        ok=false;
        double thdv = indice.at(3).trimmed().toDouble(&ok);
        if(ok){
            barras[i].setThdvPercent(thdv);
        }
        double tensaoNominal = FrameTensoes::tensoesNominais[i];
            barras[i].setTensaoNominalKv(tensaoNominal);

        if(tensaoNominal <= 1){
            barras[i].setClasseTensaoThdv(1);
        }else if(tensaoNominal > 1 && tensaoNominal < 69){
            barras[i].setClasseTensaoThdv(2);
        }else{
            barras[i].setClasseTensaoThdv(3);
        }
        //verifica se o thdv está acima do limite
        switch(barras[i].getClasseTensaoThdv()){
            case 1: if(barras[i].getThdvPercent() > 10){
                    barras[i].setbarraInfectadaThdv(true);
                }else{
                    barras[i].setbarraInfectadaThdv(false);
                }
                break;
            case 2: if(barras[i].getThdvPercent() > 8){
                    barras[i].setbarraInfectadaThdv(true);
                }else{
                    barras[i].setbarraInfectadaThdv(false);
                }
                break;
            case 3:
                if(barras[i].getThdvPercent() > 5){
                    barras[i].setbarraInfectadaThdv(true);
                }else{
                    barras[i].setbarraInfectadaThdv(false);
                }
                break;
        }

        double tensaoEficaz = tensaoPu*sqrt(1+ potencia((thdv/100),2));
            barras[i].setTensaoEficaz(tensaoEficaz);
    }
    MainWindow::arquivoThdv->close();

    if(!MainWindow::arquivoVsoln->open(QFile::ReadOnly|QFile::Text)){
            if(MainWindow::arquivoVsoln->error() == QFile::OpenError){
            return barras ;
            }
            QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
            return barras ;
    }

    for(int i = 0 ; i < 4 ; i++){
            MainWindow::arquivoVsoln->readLine();
    }

    int numBarra;
    int numHarm;
    double magHarm;
    double percentHarm;
    int classeTensaoThdi;
    std::setlocale(LC_ALL,"");
    for(int i = 0 ; i < numeroDeBarras*(quantidadeDeComponentesHarm+1) ; i++){
        QString line = MainWindow::arquivoVsoln->readLine();
        QStringList indice = line.split(",");

        numBarra = indice.at(1).trimmed().toInt()-1;
        numHarm = indice.at(0).trimmed().toInt();
        magHarm = indice.at(2).trimmed().toDouble();
        percentHarm = 100*magHarm/(barras[numBarra].getTensaoPu());

        if(barras[numBarra].getTensaoNominalKv() <= 1 ){
            classeTensaoThdi = 1;
        }else if(barras[numBarra].getTensaoNominalKv() > 1 && barras[numBarra].getTensaoNominalKv() <= 13.8){
            classeTensaoThdi = 2;
        }else if(barras[numBarra].getTensaoNominalKv() > 13.8 && barras[numBarra].getTensaoNominalKv() <= 69){
            classeTensaoThdi = 3;
        }else{
            classeTensaoThdi = 4;
        }


        if(indice.at(0).trimmed().toInt()!=1){

            if(numHarm > 25 && numHarm%3==0){
                    if(percentHarm > limitesDti[classeTensaoThdi][997]){
                        barras[numBarra].somatorioHarmonico(numHarm,magHarm,percentHarm,classeTensaoThdi,true);
                    }else{
                        barras[numBarra].somatorioHarmonico(numHarm,magHarm,percentHarm,classeTensaoThdi,false);
                    }
            }else if(numHarm > 25 && numHarm%3!=0){
                    if(percentHarm > limitesDti[classeTensaoThdi][998]){
                        barras[numBarra].somatorioHarmonico(numHarm,magHarm,percentHarm,classeTensaoThdi,true);
                    }else{
                        barras[numBarra].somatorioHarmonico(numHarm,magHarm,percentHarm,classeTensaoThdi,false);
                    }
            }else{
                if(percentHarm > limitesDti[classeTensaoThdi][numHarm]){
                        barras[numBarra].somatorioHarmonico(numHarm,magHarm,percentHarm,classeTensaoThdi,true);
                    }else{
                        barras[numBarra].somatorioHarmonico(numHarm,magHarm,percentHarm,classeTensaoThdi,false);
                    }
            }
        }
    }

    MainWindow::arquivoVsoln->close();
    return barras;
}
inline double FrameBarras::potencia(double base , int expoente){
    return (expoente==0) ? 1 : (expoente == 1) ? base : base*potencia(base,expoente-1);
}
int FrameBarras::buscaIndiceHarmMax(){
    int indiceHarm = 0 ;
    if(!MainWindow::arquivoVsoln->open(QFile::ReadOnly|QFile::Text)){
        //O arquivo vsoln possui o os indices harmonicos, lá pode-se identificar qual foi o maior indice que o usuario escolheu -- por isso foi selecionado
        //realiza o procedimento de abertura do arquivo e alerta caso aconteça algum erro -- Conforme explicado no mainwindow.cpp
        if(MainWindow::arquivoVsoln->error() == QFile::OpenError){
            return 0;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return 0;
    }
    while(!MainWindow::arquivoVsoln->atEnd()){
        QString line = MainWindow::arquivoVsoln->readLine();
        QStringList indice = line.split(",");
        bool ok = false; // inicializa com 'false' indicando que a conversão falhou
        int valorInt = indice.at(0).trimmed().toInt(&ok, 10);
        if(ok && valorInt > indiceHarm){
            indiceHarm = valorInt;
        }
    }
    MainWindow::arquivoVsoln->close();
    return indiceHarm;
}
inline int FrameBarras::buscaQtdHarm(int indiceHarmMax){
    return (indiceHarmMax/2) > 1 ? indiceHarmMax/2 : 0;
}
QStringList FrameBarras::cabecalhoBarras(int quantidadeDeComponentesHarm){
    QStringList cabecalhos={"Tensão na Barra[pu]","Tensão Nominal[Kv]","TDHV[%]"};
    for(int i = 0 , j = 3; i < quantidadeDeComponentesHarm ; i++ , j+=2){
        QString item = "DIT"+QString::number(j);
        cabecalhos.push_back(item);
    }
    for(int i = 0 , j = 3; i < quantidadeDeComponentesHarm ; i++ , j+=2){
        QString item = "DIT"+QString::number(j)+"[%]";
        cabecalhos.push_back(item);
    }
    cabecalhos.push_back("Tensão Eficaz[pu]");

    return cabecalhos;
}
//Método responsável por contar a quantidade de Barras
int FrameBarras::quantidadeDeBarras(){
    QFile *arq1 = MainWindow::arquivoThdv; //cria um ponteiro para realizar a leitura de um arquivo
    //O arquivo thdv possui uma linha de informa~ção para cada barra -- por isso foi selecionado
    //realiza o procedimento de abertura do arquivo e alerta caso aconteça algum erro -- Conforme explicado no mainwindow.cpp
    if(!arq1->open(QFile::ReadOnly|QFile::Text)){
        if(arq1->error() == QFile::OpenError){
            return 0 ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return 0 ;
    }
    int contador=0; // declara e inicia um contador
    QTextStream entrada(arq1); //declara um
    while(!arq1->atEnd()){
        arq1->readLine(); // faz a leitura de cada linha
        contador++; // realiza a contagem da quantidade de linhas do arquivo
    }
    arq1->close(); //fecha o arquivo
    return (contador-3); // o numero de barras é igual ao numero de linhas menos 3 linhas de texto sobre o software e uma vazia


}
void FrameBarras::preencheLimites(){
    limitesDti[1][3] = 6.5;
    limitesDti[1][5] = 7.5;
    limitesDti[1][7] = 6.5;
    limitesDti[1][9] = 2;
    limitesDti[1][11] = 4.5;
    limitesDti[1][13] = 4;
    limitesDti[1][15] = 1;
    limitesDti[1][17] = 2.5;
    limitesDti[1][19] = 2;
    limitesDti[1][21] = 1;
    limitesDti[1][23] = 2;
    limitesDti[1][25] = 2;
    limitesDti[1][997] = 1.5; // impar nao multplica de 3
    limitesDti[1][998] = 1; // impar multipla de 3

    limitesDti[2][3] = 5;
    limitesDti[2][5] = 6;
    limitesDti[2][7] = 5;
    limitesDti[2][9] = 1.5;
    limitesDti[2][11] = 3.5;
    limitesDti[2][13] = 3;
    limitesDti[2][15] = 0.5;
    limitesDti[2][17] = 2;
    limitesDti[2][19] = 1.5;
    limitesDti[2][21] = 0.5;
    limitesDti[2][23] = 1.5;
    limitesDti[2][25] = 2;
    limitesDti[1][997] = 1.5; // impar nao multplica de 3 maior q 25
    limitesDti[1][998] = 1; // impar multipla de 3 maior q 21


    limitesDti[3][3] = 1;
    limitesDti[3][5] = 4.5;
    limitesDti[3][7] = 4;
    limitesDti[3][9] = 1.5;
    limitesDti[3][11] = 3;
    limitesDti[3][13] = 2.5;
    limitesDti[3][15] = 0.5;
    limitesDti[3][17] = 1.5;
    limitesDti[3][19] = 1.5;
    limitesDti[3][21] = 0.5;
    limitesDti[3][23] = 1.5;
    limitesDti[3][25] = 1.5;
    limitesDti[3][997] = 1.5; // impar nao multplica de 3 maior q 25
    limitesDti[3][998] = 0.5; // impar multipla de 3 maior q 21

    limitesDti[4][3] = 0.5;
    limitesDti[4][5] = 2.5;
    limitesDti[4][7] = 2;
    limitesDti[4][9] = 1;
    limitesDti[4][11] = 1.5;
    limitesDti[4][13] = 1.5;
    limitesDti[4][15] = 0.5;
    limitesDti[4][17] = 1;
    limitesDti[4][19] = 1;
    limitesDti[4][21] = 0.5;
    limitesDti[4][23] = 1;
    limitesDti[4][25] = 1;
    limitesDti[4][997] = 0.5; // impar nao multplica de 3 maior q 25
    limitesDti[4][998] = 0.5; // impar multipla de 3 maior q 21
}
void FrameBarras::insereBackgroundNasPoluidoras(int numeroDeBarras, int indiceharmonicoMax , QList<Barra> barras){
    for(int i = 0 ; i < numeroDeBarras ; i++){
        if(barras[i].getBarraInfectadaThdv()){
            ui->tableBarras->item(2,i)->setBackground( QColor(255, 128, 128));
        }
        int pos =3;
        for(int j = 3 ; j <= indiceharmonicoMax ; j+=2){
            if(barras[i].getDti().find(j)->second.second.second){
                    ui->tableBarras->item(pos,i)->setBackground( QColor(255, 128, 128));
            }
            pos++;
        }
        for(int j = 3 ; j <= indiceharmonicoMax ; j+=2){
            if(barras[i].getDti().find(j)->second.second.second){
                    ui->tableBarras->item(pos,i)->setBackground( QColor(255, 128, 128));
            }
            pos++;
        }
    }

}
