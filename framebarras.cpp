/**
 * @class FrameBarras
 * @brief Janela responsável pelo armazenamento dos dados em nos atributos da classes Barra e Linha. Além de etregar ao usúario uma TabWidget amigável, para que possa filtrar os dados que quiser para realizar sua análise.
 * @reentrant Essa janela foi construida com 1 tabWidget e dois TableWidget entro dela, um para as Barras e outro para as linhas, além de botões para filtragem, avanço e voltar.
 * @author João Vitor N. Ramos
*/

#include "framebarras.h"
#include "ui_framebarras.h"
#include "style.h"
#include<QMessageBox>
#include<QDebug>
#include<QCoreApplication>
#include<QtMath>
#include "frameexportar.h"
#include "frametensoes.h"
#include "Barra.h"
#include "mainwindow.h"

/**
 * @variable int FrameBarras::indexTab
 * @brief Variável estática que identifica em qual index do TabWidget o usúario está. 0 para barras e 1 para linhas.
 *  Seu valor inicial é 0.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int FrameBarras::indexTab = 0 ;

/**
 * @variable int FrameBarras::numeroDeLinhas
 * @brief Variável estática responsável por armazenar o número de linhas do sistema.
 */
int FrameBarras::numeroDeLinhas;

/**
 * @variable int FrameBarras::indiceHarmMax
 * @brief Váriavel estática responsável por armazenar o índice harmônico máximo a ser análisado.
 */
int FrameBarras::indiceHarmMax;

/**
 * @variable int FrameBarras::quantidadeDeComponentesHarm
 * @brief Váriavel estática responsável por armazenar a quantidade de componentes harmônicas a serem análisadas.
 */
int FrameBarras::quantidadeDeComponentesHarm;

/**
 * @variable QList<Barra> FrameBarras::barras
 * @brief QList estático do tipo 'Barra', responsável por armazenar todas as barras do sistema,seus atributos e métodos.
 */
QList<Barra> FrameBarras::barras = QList<Barra>();


/**
 * @variable QList<Linha> FrameBarras::linhas
 * @brief QList estático do tipo 'Linha', responsável por armazenar todas as linhas do sistema,seus atributos e métodos.
 */
QList<Linha> FrameBarras::linhas =  QList<Linha>();

/**
 * @variable std::map<int , std::map<int , double >> FrameBarras::limitesDti
 * @brief map estático responsável por armazenar < Chave que relaciona o nível de tensão da Barra , < índice da harmônica , limite percentual de harmônica nesse nível de tensão para esse índice de harmônica > .
 */
std::map<int , std::map<int , double >> FrameBarras::limitesDti = std::map<int , std::map<int , double >>() ;

/**
 * @variable Ui::FrameTensoes *frameT
 * @brief Variavel que permite acessar o 'Ui' do FrameTensoes. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::FrameTensoes *frameT;

/**
 * @variable Ui::MainWindow *frameM
 * @brief Variavel que permite acessar o 'Ui' do MainWindow. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::MainWindow *frameM;

/**
 * @variable QWidget *p;
 * @brief Variavel que permite acessar seu parent. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
QWidget *p;

/**
 * @name FrameBarras::FrameBarras
 * @brief Construtor da classe FrameBarras
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 * @param mw (Parãmetro do tipo Ui::MainWindow para permitir acesso aos componentes da interface do frame MainWindow)
 * @param ft (Parãmetro do tipo Ui::FrameTensoes para permitir acesso aos componentes da interface do frame FrameTensoes)
 */
FrameBarras::FrameBarras(QWidget *parent,Ui::MainWindow *mw,Ui::FrameTensoes *ft) :
    QFrame(parent),
    ui(new Ui::FrameBarras)
{
    ui->setupUi(this);

    inicializaFrame();
    frameT = ft;
    frameM = mw;
    p = parent;
}

/**
 * @name FrameBarras::~FrameBarras
 * @brief Destrutor da classe FrameBarras
 */
FrameBarras::~FrameBarras()
{
    delete ui;
}

/**
 * @name FrameBarras::inicializaFrame
 * @brief Primeiro método a ser chamada no construtor, responsável por chamar os métodos subsequêntes que modelam a Interface do frame.
 * @return void
 */
void FrameBarras::inicializaFrame(){
    inicializaVariaveisStatic();
    preencheLimites();
    preencheFrameBarras();
}

/**
 * @name FrameBarras::inicializaVariaveisStatic
 * @brief Método responsável por iniciar as variaveis estáticas : indiceHarmMax,quantidadeDeComponentesHarm e numeroDeLinhas.
 * @return void
 */
void FrameBarras::inicializaVariaveisStatic(){
    indiceHarmMax = buscaIndiceHarmMax() ;
    quantidadeDeComponentesHarm = buscaQtdHarm(indiceHarmMax);
    numeroDeLinhas = linhasDoSistema().size();
}

/**
 * @name FrameBarras::buscaIndiceHarmMax
 * @brief Método responsável por buscar o indice harmônico maximo a ser estudado no sistema e devolver esse valor a uma váriavel
 * @return um inteiro que representa o indice harmonico maximo
 */
int FrameBarras::buscaIndiceHarmMax() {
    int indiceHarm = 0;

    if (!MainWindow::arquivoVsoln->open(QFile::ReadOnly | QFile::Text)) {
        if (MainWindow::arquivoVsoln->error() == QFile::OpenError) {
            return 0;
        }
        QMessageBox::warning(this, "Erro", "Erro ao abrir arquivo");
        return 0;
    }

    while (!MainWindow::arquivoVsoln->atEnd()) {
        QString line = MainWindow::arquivoVsoln->readLine();
        QStringList indice = line.split(",");
        bool ok = false;
        int valorInt = indice.at(0).trimmed().toInt(&ok, 10);
        if (ok && valorInt > indiceHarm) {
            indiceHarm = valorInt;
        }
    }

    MainWindow::arquivoVsoln->close();
    return indiceHarm;
}

/**
 * @name FrameBarras::buscaQtdHarm
 * @brief Método responsável por cálcular a quantidade de componentes harmônicas escolhidas para serem análisadas
 * @param indiceHarmMax
 * @return um inteiro que representa a quantidade de componentes harmônicas as serem análisadas
 */
inline int FrameBarras::buscaQtdHarm(int indiceHarmMax){
    return (indiceHarmMax/2) > 1 ? indiceHarmMax/2 : 0;
}

/**
 * @name FrameBarras::linhasDoSistema
 * @brief  Preenche um QStringList com as linhas do sistema no no padrão (... , origem -> destino, ...)
 * @return QStringList gerado na função
 */
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

/**
 * @name FrameBarras::preencheLimites
 * @brief Método responsável por preencher o map estático com os limites para cada nível de tensão e níveis harmônicos
 * @return void
 */
void FrameBarras::preencheLimites(){

    /*
     * 1 equivale a (Tensao Nominal <= 1kV)
     * 2 equivale a (Tensao Nominal > 1 kv && Tensao Nonimal <= 13.8 kV)
     * 3 equivale a (Tensao Nominal > 13.8 kV && Tensao Nominal <= 69kV)
     * 4 equivale a (Tensao Nominal > 69kV)
    */

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

/**
 * @name FrameBarras::preencheFrameBarras
 * @brief Método responsável por realizar a chamada de métodos que são responsáveis por inserir o Qss do frame e preencher as tabelas com as informações das barras e das linhas
 * @return void
 */
void FrameBarras::preencheFrameBarras(){
    insereQssFrameBarras();
    inicializaBarra();
    preencheBarra();
    preencheTabelaBarra();
    inicializaLinha();
    preencheLinha();
    preencheTabelaLinha();
    insereBackgroundNasPoluidoras();
}

/**
 * @name FrameBarras::insereQssFrameBarras
 * @brief Método responsável por chamar métodos que inserem Qss nos componentes do frame
 * @return void
 */
void FrameBarras::insereQssFrameBarras(){
    insereQssBtnAvancar();
    insereQssBtnVoltar();
    insereQSSBtnFiltrar();
    insereQssTabWidget();
    insereQssTableBarras();
    insereQssTableLinhas();
}

/**
 * @name FrameBarras::insereQssBtnAvancar
 * @brief Método responsável por inserir Qss no botão avançar
 * @return void
 */
void FrameBarras::insereQssBtnAvancar(){
    Style style;
    ui->btnAvancar->setStyleSheet(style.cssBtnTransition);
    ui->btnAvancar->setIcon(QIcon(":/icons/imgs/icons/proximo.png")); //insere um icon ao botão
    ui->btnAvancar->setLayoutDirection(Qt::RightToLeft); //define que o icon será colocado após o texto
}

/**
 * @name FrameBarras::insereQssBtnVoltar
 * @brief Método responsável por inserir Qss no botão voltar
 * @return void
 */
void FrameBarras::insereQssBtnVoltar(){
    Style style;
    ui->btnVoltar->setStyleSheet(style.cssBtn);
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png"));
}

/**
 * @name FrameBarras::insereQSSBtnFiltrar
 * @brief Método responsável por inserir Qss no botão filtrar
 * @return void
 */
void FrameBarras::insereQSSBtnFiltrar(){
    Style style;
    ui->btnFiltrar->setStyleSheet(style.cssBtn);
    ui->btnFiltrar->setIcon(QIcon(":/icons/imgs/icons/filtro.png"));
}

/**
 * @name FrameBarras::insereQssTabWidget
 * @brief Método responsável por inserir Qss no tabWidget
 * @return void
 */
void FrameBarras::insereQssTabWidget(){
    Style style;
    ui->tabLinhas->setStyleSheet(style.cssTabWidget);
}

/**
 * @name FrameBarras::insereQssTableBarras
 * @brief Método responsável por inserir Qss no TableBarras
 * @return void
 */
void FrameBarras::insereQssTableBarras(){
    Style style;
    //Inserindo cabeçalho vertical na priemira coluna
    ui->tableBarras->setRowCount(3 + 2*quantidadeDeComponentesHarm + 1);
    ui->tableBarras->setColumnCount(FrameTensoes::numeroDeBarras);
    ui->tableBarras->setVerticalHeaderLabels(cabecalhoBarras());
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

/**
 * @name FrameBarras::cabecalhoBarras
 * @brief Método responsável por criar um QStringList com o cabeçaho para as barras
 * @return QStringList do cabeçalho das linhas
 */
QStringList FrameBarras::cabecalhoBarras(){
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

/**
 * @name FrameBarras::insereQssTableLinhas
 * @brief Método responsável por inserir Qss no TableLinhas
 * @return void
 */
void FrameBarras::insereQssTableLinhas(){
    Style style;
    ui->tableLinhas->setRowCount(2 + 2*quantidadeDeComponentesHarm + 4);
    ui->tableLinhas->setColumnCount(numeroDeLinhas);
    ui->tableLinhas->setVerticalHeaderLabels(cabecalhoLinhas());
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
    ui->tableLinhas->setHorizontalHeaderLabels(linhasDoSistema());
}

/**
 * @name FrameBarras::cabecalhoLinhas
 * @brief Método responsável por criar um QStringList com o cabeçaho para as linhas
 * @return QStringList do cabeçalho das linhas
 */
QStringList FrameBarras::cabecalhoLinhas(){

    QStringList cabecalhos={"Corrente na Linha[pu]","DHT[%]"};
    for(int i = 0 , j = 3; i < quantidadeDeComponentesHarm ; i++ , j+=2){
        QString item = "DHI"+QString::number(j);
        cabecalhos.push_back(item);
    }
    for(int i = 0 , j = 3; i < quantidadeDeComponentesHarm ; i++ , j+=2){
        QString item = "DHI"+QString::number(j)+"[%]";
        cabecalhos.push_back(item);
    }
    cabecalhos.push_back("Corrente Eficaz[pu]");
    cabecalhos.push_back("Resistencia[ohm]");
    cabecalhos.push_back("Perdas[pu]");
    cabecalhos.push_back("Perdas eficaz[pu]");

    return cabecalhos;
}

/**
 * @name FrameBarras::inicializaBarra
 * @brief Método responsável por inicializar todo o QList<Barra> com o tamanho do numero de Barras
 * @return void
 */
void FrameBarras::inicializaBarra() {
    barras.resize(FrameTensoes::numeroDeBarras, Barra());
}

/**
 * @name FrameBarras::preencheBarra
 * @brief Método responsável por preencher o QList<Barra> com as informações de todas as barras do sistema
 * @return void
 */
void FrameBarras::preencheBarra(){

    //O arquivo thdv possui uma linha de informa~ção para cada barra -- por isso foi selecionado
    //realiza o procedimento de abertura do arquivo e alerta caso aconteça algum erro -- Conforme explicado no mainwindow.cpp
    if(!MainWindow::arquivoThdv->open(QFile::ReadOnly|QFile::Text)){
        if(MainWindow::arquivoThdv->error() == QFile::OpenError){
            return ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return ;
    }

    for (int i = 0; i < 2; i++) {
        MainWindow::arquivoThdv->readLine();
    }

    for (int i = 0; i < FrameTensoes::numeroDeBarras; i++) {
        QString line = MainWindow::arquivoThdv->readLine();
        QStringList indice = line.split(",");
        bool ok = false;
        double tensaoPu = indice.at(2).trimmed().toDouble(&ok);
        if (ok) {
            barras[i].setTensaoPu(tensaoPu);
        }
        ok = false;
        double thdv = indice.at(3).trimmed().toDouble(&ok);
        if (ok) {
            barras[i].setThdvPercent(thdv);
        }
        double tensaoNominal = FrameTensoes::tensoesNominais[i];
        barras[i].setTensaoNominalKv(tensaoNominal);

        int classeTensaoThdv;
        if (tensaoNominal <= 1) {
            classeTensaoThdv = 1;
        } else if (tensaoNominal < 69) {
            classeTensaoThdv = 2;
        } else {
            classeTensaoThdv = 3;
        }

        bool barraInfectadaThdv = false;
        switch (classeTensaoThdv) {
        case 1:
            barraInfectadaThdv = (barras[i].getThdvPercent() > 10);
            break;
        case 2:
            barraInfectadaThdv = (barras[i].getThdvPercent() > 8);
            break;
        case 3:
            barraInfectadaThdv = (barras[i].getThdvPercent() > 5);
            break;
        }
        barras[i].setbarraInfectadaThdv(barraInfectadaThdv);

        double tensaoEficaz = tensaoPu * sqrt(1 + pow((thdv / 100), 2));
        barras[i].setTensaoEficaz(tensaoEficaz);
    }
    MainWindow::arquivoThdv->close();

    if(!MainWindow::arquivoVsoln->open(QFile::ReadOnly|QFile::Text)){
        if(MainWindow::arquivoVsoln->error() == QFile::OpenError){
            return  ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return  ;
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
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras*(quantidadeDeComponentesHarm+1) ; i++){
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
}

/**
 * @name FrameBarras::preencheTabelaBarra
 * @brief Método responsável por preencher a tabela que mostra as informaçõs das barras
 * @return void
 */
void FrameBarras::preencheTabelaBarra() {
    for (int i = 0; i < FrameTensoes::numeroDeBarras; i++) {
        int pos = 0;

        ui->tableBarras->setItem(pos++, i, new QTableWidgetItem(QString::number(barras[i].getTensaoPu(), 'f', 5)));
        ui->tableBarras->setItem(pos++, i, new QTableWidgetItem(QString::number(barras[i].getTensaoNominalKv(), 'f', 5)));
        ui->tableBarras->setItem(pos++, i, new QTableWidgetItem(QString::number(barras[i].getThdvPercent(), 'f', 5)));

        for (int j = 3; j <= indiceHarmMax; j += 2) {
            QTableWidgetItem* dtiAbsolut = new QTableWidgetItem(QString::number(barras[i].getDti().find(j)->second.first.first, 'e', 5));
            ui->tableBarras->setItem(pos++, i, dtiAbsolut);
        }

        for (int j = 3; j <= indiceHarmMax; j += 2) {
            QTableWidgetItem* dtiRelative = new QTableWidgetItem(QString::number(barras[i].getDti().find(j)->second.first.second, 'f', 5));
            ui->tableBarras->setItem(pos++, i, dtiRelative);
        }

        ui->tableBarras->setItem(pos, i, new QTableWidgetItem(QString::number(barras[i].getTensaoEficaz(), 'f', 5)));
    }
}

/**
 * @name FrameBarras::inicializaLinha
 * @brief Método responsável por inicializar todo o QList<Linha> com o tamanho do numero de linhas
 * @return void
 */
void FrameBarras::inicializaLinha() {
    linhas.resize(numeroDeLinhas, Linha());
}

/**
 * @name FrameBarras::preencheLinha
 * @brief Método responsável por preencher o QList<Linha> com as informações de todas as linhas do sistema
 * @return void
 */
void FrameBarras::preencheLinha()
{
    if (!MainWindow::arquivoThdi->open(QFile::ReadOnly | QFile::Text)) {
        if (MainWindow::arquivoThdi->error() == QFile::OpenError) {
            return;
        }
        QMessageBox::warning(this, "Erro", "Erro ao abrir arquivo");
        return;
    }

    for (int i = 0; i < 2; i++) {
        MainWindow::arquivoThdi->readLine();
    }

    int origem, destino;
    double corrente, dht;
    int cont = 0;
    double correnteEficaz;

    while (!MainWindow::arquivoThdi->atEnd()) {
        QString line = MainWindow::arquivoThdi->readLine();
        QStringList indice = line.split(",");
        origem = indice.at(0).trimmed().toInt();
        destino = indice.at(2).trimmed().toInt();
        corrente = indice.at(5).trimmed().toDouble();
        dht = indice.at(6).trimmed().toDouble();
        correnteEficaz = corrente * sqrt(1 + pow((dht / 100), 2));

        if (origem < destino) {
            linhas[cont].setOrigem(origem);
            linhas[cont].setDestino(destino);
            linhas[cont].setCorrente(corrente);
            linhas[cont].setDhtPercent(dht);
            linhas[cont].setCorrenteEficaz(correnteEficaz);
            cont++;
        }
    }

    MainWindow::arquivoThdi->close();

    // ...

    if (!MainWindow::arquivoIsoln->open(QFile::ReadOnly | QFile::Text)) {
        if (MainWindow::arquivoIsoln->error() == QFile::OpenError) {
            return;
        }
        QMessageBox::warning(this, "Erro", "Erro ao abrir arquivo");
        return;
    }

    for (int i = 0; i < 4; i++) {
        MainWindow::arquivoIsoln->readLine();
    }

    int numHarm;
    double magHarm;
    double percentHarm;

    for (int i = 0; i < quantidadeDeComponentesHarm; i++) {
        for (int j = 0; j < numeroDeLinhas;) {
            QString line = MainWindow::arquivoIsoln->readLine();
            if (line.trimmed().isEmpty()) {
                break;
            }
            QStringList indice = line.split(",");
            numHarm = indice.at(0).trimmed().toInt();
            origem = indice.at(1).trimmed().toInt();
            destino = indice.at(2).trimmed().toInt();
            magHarm = indice.at(4).trimmed().toDouble();
            percentHarm = 100 * (magHarm / linhas[j].getCorrente());
            if (numHarm != 1 && origem < destino && origem != 0 && destino != 0) {
                linhas[j].setDti(numHarm, magHarm, percentHarm);
                j++;
            }
        }
    }

    MainWindow::arquivoIsoln->close();

    if(!MainWindow::arquivoLdat->open(QFile::ReadOnly|QFile::Text)){
        if(MainWindow::arquivoLdat->error() == QFile::OpenError){
            return  ;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return  ;
    }

    for(int i = 0 ; i < 9 ; i++){
        MainWindow::arquivoLdat->readLine();
    }
    double resistencia;
    double perdas;
    double perdasEficaz;
    for (int i = 0; i < numeroDeLinhas; i++) {
        QString line = MainWindow::arquivoLdat->readLine();
        if (line.trimmed().isEmpty()) { // verificar se é uma linha vazia
            break;
        }
        QStringList indice = line.split(",");
        origem = indice.at(0).trimmed().toInt();
        destino = indice.at(1).trimmed().toInt();
        if (origem < destino) {
            resistencia = indice.at(3).trimmed().toDouble();

            for (int j = 0; j < numeroDeLinhas; j++) {
                if (linhas[j].getOrigem() == origem && linhas[j].getDestino() == destino) {
                    linhas[j].setResistencia(resistencia);
                    perdas = linhas[j].getCorrente() * resistencia;
                    perdasEficaz = linhas[j].getCorrenteEficaz() * resistencia;
                    linhas[j].setPerdas(perdas);
                    linhas[j].setPerdasEficaz(perdasEficaz);
                }
            }
        }
    }

    MainWindow::arquivoLdat->close();
    return;
}

/**
 * @name FrameBarras::preencheTabelaLinha
 * @brief Método responsável por preencher a tabela que mostra as informaçõs das linhas
 * @return void
 */
void FrameBarras::preencheTabelaLinha(){
    for(int i = 0 ; i < numeroDeLinhas ; i++){
        QTableWidgetItem* correntePu = new QTableWidgetItem(QString::number(linhas[i].getCorrente(),'f',5));
        QTableWidgetItem* dht = new QTableWidgetItem(QString::number(linhas[i].getDhtPercent(),'f',5));
        ui->tableLinhas->setItem(0,i,correntePu);
        ui->tableLinhas->setItem(1,i,dht);
        int pos =2;
        for(int j = 3 ; j <= indiceHarmMax ; j+=2){
            QTableWidgetItem* dtiAbsolut = new QTableWidgetItem(QString::number(linhas[i].getDti().find(j)->second.first,'e',5));
            ui->tableLinhas->setItem(pos,i,dtiAbsolut);
            pos++;
        }
        for(int j = 3 ; j <= indiceHarmMax ; j+=2){
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

/**
 * @name FrameBarras::insereBackgroundNasPoluidoras
 * @brief Método responsável por inserir Background nos itens que possuem as barras poluidoras
 * @return void
 */
void FrameBarras::insereBackgroundNasPoluidoras(){
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        if(barras[i].getBarraInfectadaThdv()){
            ui->tableBarras->item(2,i)->setBackground( QColor(255, 128, 128));
        }
        int pos =3;
        for(int j = 3 ; j <= indiceHarmMax ; j+=2){
            if(barras[i].getDti().find(j)->second.second.second){
                ui->tableBarras->item(pos,i)->setBackground( QColor(255, 128, 128));
            }
            pos++;
        }
        for(int j = 3 ; j <= indiceHarmMax ; j+=2){
            if(barras[i].getDti().find(j)->second.second.second){
                ui->tableBarras->item(pos,i)->setBackground( QColor(255, 128, 128));
            }
            pos++;
        }
    }
}

/**
 * @name FrameBarras::potencia
 * @brief Método responsável por calcular potência matemática
 * @param base
 * @param expoente
 * @return um double representando o valor da potência calculada
 */
inline double FrameBarras::potencia(double base , int expoente){
    return (expoente==0) ? 1 : (expoente == 1) ? base : base*potencia(base,expoente-1);
}


/**
 * @sa FrameBarras::on_btnFiltrar_clicked
 * @brief Método responsável por implementar o evento ao botão filtrar ser acionado.
 * O método irá verificar qual index do TabWidget está selecionado e irá abrir uma janela de filtragem
 * @return void
 */
void FrameBarras::on_btnFiltrar_clicked()
{
    if(indexTab == 0){
        //Declara e instancia o frame da nova janela
        FiltrosBarra *filtrosBarra = new FiltrosBarra(this,ui);
        filtrosBarra->show();
    }else if( indexTab == 1){
        FiltroLinha *filtrosLinha = new FiltroLinha(this,ui);
        filtrosLinha->show();
    }

}

/**
 * @sa FrameBarras::on_tabLinhas_currentChanged
 * @brief Método responsável por atualizar a variável estática indexTab a cada alternancia do tabWidget
 * @param index
 */
void FrameBarras::on_tabLinhas_currentChanged(int index)
{
    indexTab = index;
}

/**
 * @sa FrameBarras::on_btnVoltar_clicked
 * @brief Método responsável por implementar o evento ao botão voltar ser acionado.
 * O método irá fechar a frame atual e exibir a anterior
 * @return void
 */
void FrameBarras::on_btnVoltar_clicked()
{
    MainWindow::frameAtual--; //subtrai de 1 a variavel que conta em qua frame o usuario está
    MainWindow::atualizarStatus(frameM); //atualiza a Barra de Status

    p->show(); // mostra o Frame Anterior
    this->close(); //Fecha o frame atual
}

/**
 * @sa FrameBarras::on_btnAvancar_clicked
 * @brief Método responsável por implementar o evento ao botão avançar ser acionado.
 * O método irá esconder o frame atual e abrir o frame de exportação
 * @return void
 */
void FrameBarras::on_btnAvancar_clicked()
{
    MainWindow::frameAtual++;
    MainWindow::atualizarStatus(frameM);
    this->hide();

    if(FiltrosBarra::indexComboBoxEnvio == 0 && FiltrosBarra::indiceBarrasEscolhidas.isEmpty()){

        FiltrosBarra::indiceBarrasEscolhidas.append(QString::number(1));
        FiltrosBarra::indiceBarrasEscolhidas.append(QString::number(FrameTensoes::numeroDeBarras));

    }

    FrameExportar *frameExportar = new FrameExportar(this,frameM,ui);
    frameExportar->setParent(this->parentWidget());
    frameExportar->setGeometry(224,0,800,720);
    frameExportar->show();

}
