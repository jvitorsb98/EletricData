#include "frametensoes.h"
#include "framebarras.h"
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QScrollBar>
#include<QDebug>
#include<QTextStream>
#include "style.h"


QFile* MainWindow::arquivoTensoes  = new QFile();
QList<double> FrameTensoes::tensoesNominais;
Ui::MainWindow *frameMain;
int FrameTensoes::numeroDeBarras;

FrameTensoes::FrameTensoes(QWidget *parent,Ui::MainWindow *mw) :
    QFrame(parent),

    ui(new Ui::FrameTensoes)
{
    ui->setupUi(this);
    Style style;
    numeroDeBarras=quantidadeDeBarras();
    frameMain = mw; // define um ponteiro que aponte para onde ficam as informações do frame anterior
    insereQssFrameTensoes();
}

FrameTensoes::~FrameTensoes()
{
    delete ui;
}
//Função mãe de inserir QSS neste frame
void FrameTensoes::insereQssFrameTensoes(){
    insereQssBotaoAvancar();
    insereQssImportar();
    insereQssBtnVoltar();
    insereQssBtnLixeira();
    insereQssBtnSalvar();
    insereQssFrame();
    insereTableTensoes();

}
//Funções auxiliares de inserir QSS
void FrameTensoes::insereQssBotaoAvancar(){
    Style style;
    ui->btnAvancar->setStyleSheet(style.cssBtn);
    ui->btnAvancar->setIcon(QIcon(":/icons/imgs/icons/proximo.png")); //insere um icon ao botão
    ui->btnAvancar->setLayoutDirection(Qt::RightToLeft); //define que o icon será colocado após o texto
}
void FrameTensoes::insereQssImportar(){
    Style style;
    ui->btnImportar->setStyleSheet(style.cssBtn);
    ui->lineEditImportar->setStyleSheet(style.cssLineEdit);

}
void FrameTensoes::insereQssBtnVoltar(){
    Style style;
    //Botão Voltar
    ui->btnVoltar->setStyleSheet(style.cssBtn);
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png"));
}
void FrameTensoes::insereQssBtnLixeira(){
    //botão Lixeira(apagar)
    Style style;
    ui->btnLixeira->hide();
    ui->btnLixeira->setStyleSheet(style.cssBtnLixeira);
    ui->btnLixeira->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
}
void FrameTensoes::insereQssBtnSalvar(){
    Style style;
    //Botão Salvar Tabela
    ui->btnSalvarTabela->setStyleSheet(style.cssBtn);
    ui->btnSalvarTabela->setIcon(QIcon(":/icons/imgs/icons/salve-.png"));
}
inline void FrameTensoes::insereQssFrame(){
    Style style;
    this->setStyleSheet(style.cssFrameArq); //Nova frame
};
//função que monta o table Tensões
void FrameTensoes::insereTableTensoes(){
    Style style;
    //Tabela de tensões
    ui->tableTensoes->setColumnCount(2);
    ui->tableTensoes->setRowCount(numeroDeBarras);
    QStringList cabecalhos={"Barra","Tensão [Kv]"}; //insere cabeçalho à tabe
    ui->tableTensoes->setHorizontalHeaderLabels(cabecalhos);
    ui->tableTensoes->setColumnWidth(0,100);
    //configura o width da segunda coluna para um determinado numero de barras, devido ao espaço disponibilizado apara oa scrool bar
    (numeroDeBarras <=17 ) ?  ui->tableTensoes->setColumnWidth(1,358) : ui->tableTensoes->setColumnWidth(1,346);

    ui->tableTensoes->verticalHeader()->setVisible(false);
    ui->tableTensoes->verticalScrollBar()->setVisible(true);//torna visivel a scrool bar, mesmo que possa ficar pequena com poucas barras devido ao QSS
    ui->tableTensoes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableTensoes->setStyleSheet(style.csstabelaTensoes); //insere QSS na tabela
    ui->tableTensoes->horizontalHeader()->setStyleSheet(style.cssHeaderTabela); //insere QSS no header da tabela
    ui->tableTensoes->setAlternatingRowColors(true); //aplica anternacia de cores na tabela

    //insere um numero de linhas à tabela correspondente ao numero de Barras
    for (int i = 0; i < numeroDeBarras; i++) {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(i+1));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        ui->tableTensoes->setItem(i, 0, item); //é inserido na primeira linha da Tabela o indice de cada barra
    }
}
//Botão responsável por retornar a janela anterior
void FrameTensoes::on_btnVoltar_clicked(){
    MainWindow::frameAtual--; //subtrai de 1 a variavel que conta em qua frame o usuario está
    MainWindow::atualizarStatus(frameMain); //atualiza a Barra de Status

    frameMain->frameArquivos->show(); // mostra o Frame Anterior
    this->close(); //Fecha o frame atual

}
//Método responsável por contar a quantidade de Barras
int FrameTensoes::quantidadeDeBarras(){
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
//Botão responsável por importar um arquivo com as informações da tabela
void FrameTensoes::on_btnImportar_clicked()
{
    //Configura-se um filtro para pesquisa do arquivo
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro);  //inicia a procura do arquivo C::
    MainWindow::arquivoTensoes->setFileName(abrirArquivo); //busca grava o endereço para abertura na variavel estática
    //realiza abertura do arquivo
    if(!MainWindow::arquivoTensoes->open(QFile::ReadOnly|QFile::Text)){  //caso não seja realizada a abertura
        if(MainWindow::arquivoTensoes->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return;
    }
    ui->lineEditImportar->setText(MainWindow::arquivoTensoes->fileName()); // mostra o endereço no lineEdit
    ui->lineEditImportar->setEnabled(false); //desabilita o botão importar
    ui->btnImportar->hide(); //esconde o botão importar
    ui->btnLixeira->show(); //mostra o botão de lixeira

    int numeroDeBarras = quantidadeDeBarras();  // solicita a quantidade de barras para a proxima ação
    // realiza o preenchimento de de todos os campos informados pelo import do arquivo
    for (int i = 0; i < numeroDeBarras; i++) {
        QString line = MainWindow::arquivoTensoes->readLine();
        QStringList infos = line.split(",");
        QTableWidgetItem* item = new QTableWidgetItem(infos.at(1).trimmed());
        ui->tableTensoes->setItem(i,1,item);
    }

}
//Botão responsável por apagar os dados inseridos pelo botão importar e o endereço selecionado
void FrameTensoes::on_btnLixeira_clicked()
{
    //solicita que o usuario confirme sua escolha
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //caso escolha sim
     if(escolha==QMessageBox::Yes){
         ui->lineEditImportar->clear(); // limpa o lineEdit do import
         ui->btnLixeira->hide(); //esconde o botão lixeira
         ui->lineEditImportar->setEnabled(true); //habilita o LineEdit de importar
         ui->btnImportar->show(); // mostra o botão importar na tela
         int numeroDeBarras = quantidadeDeBarras(); // solicita a quantidade de barras para a proxima ação
         // realiza a limpeza de de todos os campos preenchidos pelo import do arquivo
         for (int i = 0; i < numeroDeBarras ; i++) {
            ui->tableTensoes->setItem(i,1,nullptr);
         }
     }
     else{
         return;
     }
}
//Botão para salvar a tabela em um arquivo externo
void FrameTensoes::on_btnSalvarTabela_clicked()
{
     //Configura-se um filtro para pesquisa do diretorio
     QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
     QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
     MainWindow::arquivoTensoes->setFileName(localSalvamento);
     if(!MainWindow::arquivoTensoes->open(QFile::WriteOnly | QFile::Text)){
         if(MainWindow::arquivoTensoes->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
            return;
         }
         QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
         return;
     }

     QTextStream saida(MainWindow::arquivoTensoes);
     int numeroDeBarras = quantidadeDeBarras();
     for(int i=0 ; i< numeroDeBarras ; i++){
         saida << ui->tableTensoes->item(i,0)->text()+","+ ((ui->tableTensoes->item(i,1))==nullptr ? " " : ui->tableTensoes->item(i,1)->text()) << Qt::endl;
     }
     MainWindow::arquivoTensoes->flush();
     MainWindow::arquivoTensoes->close();

}
//Botão responsável por avançar para o proximo frame
void FrameTensoes::on_btnAvancar_clicked()
{
     if(verificaAvanco()){
         if(MainWindow::arquivoTensoes->fileName()==nullptr){
            QMessageBox::StandardButton escolha;
            escolha = QMessageBox::question(this,"Salvar Arquivo","Deseja salvar o arquivo de tensões?",QMessageBox::Yes|QMessageBox::No);
            if(escolha==QMessageBox::Yes){
                QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
                QString localSalvamento =QFileDialog::getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),filtro);
                MainWindow::arquivoTensoes->setFileName(localSalvamento);
                if(!MainWindow::arquivoTensoes->open(QFile::WriteOnly | QFile::Text)){
                    if(MainWindow::arquivoTensoes->error() == QFile::OpenError){  //verifica se o usuario nao selecionou nenhuma
                        return;
                    }
                    QMessageBox::warning(this,"Erro","Arquivo não pôde ser savo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
                    return;
                }
                QTextStream saida(MainWindow::arquivoTensoes);
                for(int i=0 ; i< numeroDeBarras ; i++){
                    saida << ui->tableTensoes->item(i,0)->text()+","+ ((ui->tableTensoes->item(i,1))==nullptr ? " " : ui->tableTensoes->item(i,1)->text()) << Qt::endl;
                }
                MainWindow::arquivoTensoes->flush();
                MainWindow::arquivoTensoes->close();
            }
         }
         int qtd = quantidadeDeBarras();
         for(int i = 0 ; i < qtd ; i++){
            tensoesNominais.push_back(ui->tableTensoes->item(i,1)->text().toDouble());
         }

         MainWindow::frameAtual++;
         MainWindow::atualizarStatus(frameMain);
         this->hide();


         //Declara e instancia o frame da nova janela
         FrameBarras *frameBarras = new FrameBarras(this,frameMain,ui);
         frameBarras->setParent(this->parentWidget());
         frameBarras->setGeometry(224,0,800,720);
         frameBarras->show();
     }
     else{
         QMessageBox::warning(this,"Erro ao Avançar","Verifique o preenchimento de todos os campos de tensões");
     }
}
//função que verifica um possivel avanço
bool FrameTensoes::verificaAvanco(){
    int numeroDeBarras = quantidadeDeBarras();
    for(int i = 0 ; i < numeroDeBarras ; i++){
         if(ui->tableTensoes->item(i,1)==nullptr){
            return false;
         }
    }
    return true;

}

