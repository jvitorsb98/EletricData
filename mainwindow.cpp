#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include<QPropertyAnimation>
#include <QApplication>
#include "frametensoes.h"
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QFile>
#include<QDebug>

int MainWindow::frameAtual=0; //Inicializando a variavel estática que identifica cada frame está ( O primeiro é 0 )

//Inicializando as variaveis estáticas dos arquivos
QFile* MainWindow::arquivoVsoln = new QFile();
QFile* MainWindow::arquivoIsoln = new QFile();
QFile* MainWindow::arquivoThdi  = new QFile();
QFile* MainWindow::arquivoThdv  = new QFile();
QFile* MainWindow::arquivoLdat  = new QFile();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    insereCssMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::insereCssMainWindow(){

    insereIcon();
    insereQssBarraDeStatus();
    insereQssTitulosLineEdit();
    insereQssLineEdit();
    insereQssPlaceHolderLineEdit();
    insereQssBtnArquivos();
    insereQssBtnAvancar();
    insereQssBtnLixeira();
    insereQssLblVerifica();

}
void MainWindow::insereIcon(){
    //Propriedades da Janela( inserindo icone e titulo)
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));
    setWindowTitle("EletricData 1.0");
}
void MainWindow::insereQssBarraDeStatus(){
    Style style;

    //Componentes da Barra Lateral de status
    ui->txtCarregarArquivos->setStyleSheet(style.cssTxtSelected);
    ui->txtTensoesNasBarras->setStyleSheet(style.cssTxt);
    ui->txtPrepararSaida->setStyleSheet(style.cssTxt);
    ui->txtExportar->setStyleSheet(style.cssTxt);
    ui->statusFrame->setStyleSheet(style.cssStatusFrame); // Frame da barra lateral
}
void MainWindow::insereQssTitulosLineEdit(){
    Style style;
    //titulos acima dos lineEdits do FrameArquivos
    ui->txtVsoln->setStyleSheet(style.cssTxtArquivos);
    ui->txtThdv->setStyleSheet(style.cssTxtArquivos);
    ui->txtThdi->setStyleSheet(style.cssTxtArquivos);
    ui->txtIsoln->setStyleSheet(style.cssTxtArquivos);
    ui->txtLdat->setStyleSheet(style.cssTxtArquivos);
    ui->frameArquivos->setStyleSheet(style.cssFrameArq); // Frame Arquivos
}
void MainWindow::insereQssLineEdit(){
    Style style;
    //LineEdits do FrameArquivos
    ui->lineEditVsoln->setStyleSheet(style.cssLineEdit);
    ui->lineEditIsoln->setStyleSheet(style.cssLineEdit);
    ui->lineEditLdat->setStyleSheet(style.cssLineEdit);
    ui->lineEditThdi->setStyleSheet(style.cssLineEdit);
    ui->lineEditThdv->setStyleSheet(style.cssLineEdit);
}
void MainWindow::insereQssPlaceHolderLineEdit(){
    Style style;

    //Inserindo placeHolder nos LineEdits
    ui->lineEditVsoln->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo");
    ui->lineEditIsoln->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo");
    ui->lineEditLdat->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo");
    ui->lineEditThdi->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo");
    ui->lineEditThdv->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo");
}
void MainWindow::insereQssBtnArquivos(){
    Style style;
    //Botões do FrameArquivos
    ui->btnVsoln->setStyleSheet(style.cssBtn);
    ui->btnThdv->setStyleSheet(style.cssBtn);
    ui->btnIsoln->setStyleSheet(style.cssBtn);
    ui->btnLdat->setStyleSheet(style.cssBtn);
    ui->btnThdi->setStyleSheet(style.cssBtn);
}
void MainWindow::insereQssBtnAvancar(){
    Style style;
    ui->btnAvancar->setStyleSheet(style.cssBtnTransition);
    ui->btnAvancar->setIcon(QIcon(":/icons/imgs/icons/proximo.png"));
    ui->btnAvancar->setLayoutDirection(Qt::RightToLeft);
    ui->btnAvancar->setEnabled(false); // Esse botão inicia desabilitado
}
void MainWindow::insereQssBtnLixeira(){

    Style style;

    //Botões de Checked e lixeira para cada arquivo
    ui->btnLixeiraVsoln->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraVsoln->setStyleSheet(style.cssBtnLixeira);
    ui->btnLixeiraVsoln->hide();//inicia hide

    ui->btnLixeiraIsoln->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraIsoln->setStyleSheet(style.cssBtnLixeira);
    ui->btnLixeiraIsoln->hide();

    ui->btnLixeiraThdv->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraThdv->setStyleSheet(style.cssBtnLixeira);
    ui->btnLixeiraThdv->hide();

    ui->btnLixeiraThdi->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraThdi->setStyleSheet(style.cssBtnLixeira);
    ui->btnLixeiraThdi->hide();

    ui->btnLixeiraLdat->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraLdat->setStyleSheet(style.cssBtnLixeira);
    ui->btnLixeiraLdat->hide();
}
void MainWindow::insereQssLblVerifica(){
    //os labels de Checked iniciam escondidos já que nada foi realizado ainda
    ui->lblVerifica1->hide();
    ui->lblVerifica2->hide();
    ui->lblVerifica3->hide();
    ui->lblVerifica4->hide();
}
//verificar se os arquivos estão inseridos para permitir avanço
void MainWindow::verificarAvanco(){

    for (int i= 0; i < 5; i++) {
        if(!this->getStatusDePreenchimento(i)){
            return;
        }
    }
    ui->btnAvancar->setEnabled(true);
}
//Função Responsável pelo evento do botão Avançar
void MainWindow::on_btnAvancar_clicked()
{
    //abre uma QMessageBox confirmando se os dados estão certos para poder avançar
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Inserir Arquivos","Os arquivos inseridos estão corretos?",QMessageBox::Yes|QMessageBox::No);
     if(escolha==QMessageBox::Yes){
        //seta nas variaveis estáticas o endereço de cada arquivo selecionado
        setaFileNameNosArq();
        //Declara e instancia o frame da nova janela
        FrameTensoes *frame = new FrameTensoes(this,ui);
        ui->frameArquivos->hide(); // esconde a janela anterior
        //configura a atual janela
        frame->setParent(this);
        frame->setGeometry(224,0,800,720);
        frameAtual++; // atualiza o indice de status
        MainWindow::atualizarStatus(ui); // atualiza a barra de status
        frame->show(); // mostra a nova janela
    }
     else{
        return;
     }

}
void MainWindow::setaFileNameNosArq(){
     arquivoIsoln->setFileName(ui->lineEditIsoln->text());
     arquivoVsoln->setFileName(ui->lineEditVsoln->text());
     arquivoThdi->setFileName(ui->lineEditThdi->text());
     arquivoThdv->setFileName(ui->lineEditThdv->text());
     arquivoLdat->setFileName(ui->lineEditLdat->text());
}
//Permite a busca e inserção do arquivo Vsoln
void MainWindow::on_btnVsoln_clicked()
{
    //Configura-se um filtro para pesquisa do arquivo
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro); //inicia a procura do arquivo C::
    arquivoVsoln->setFileName(abrirArquivo); //busca grava o endereço para abertura
    //realiza abertura do arquivo
    if(!arquivoVsoln->open(QFile::ReadOnly|QFile::Text)){ //caso não seja realizada a abertura
        if(arquivoVsoln->error() == QFile::OpenError){ //verifica se o usuario nao selecionou nenhuma
            return;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir é enviado uma messagem de erro
        return;
    }
    //Pós-Abertura
    ui->lineEditVsoln->setText(arquivoVsoln->fileName()); // mostra o endereço no lineEdit
    ui->lineEditVsoln->setEnabled(false); //bloqueia o line edit
    ui->btnVsoln->hide(); //Esconde o botao de procura
    ui->btnLixeiraVsoln->show(); //mostra o botao de lixeira
    this->setStatusDePreenchimento(0,true); //guarda a informação de que destá parte do form foi inserida
    verificarAvanco(); //verifica se o form está completo para habilitar o botão de avançar
    arquivoVsoln->close(); //fecha o arquivo
}
//Permite a busca e inserção do arquivo Thdv -- Os comentarios sao os mesmos do MainWindow::on_btnVsoln_clicked()
void MainWindow::on_btnThdv_clicked()
{
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro);
    arquivoThdv->setFileName(abrirArquivo);
    if(!arquivoThdv->open(QFile::ReadOnly|QFile::Text)){
        if(arquivoThdv->error() == QFile::OpenError){
            return;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return;
    }
    ui->lineEditThdv->setText(arquivoThdv->fileName());
    ui->lineEditThdv->setEnabled(false);
    ui->btnThdv->hide();
    ui->btnLixeiraThdv->show();
    this->setStatusDePreenchimento(1,true);
    verificarAvanco();
    arquivoThdv->close();

}
//Permite a busca e inserção do arquivo Thdi -- Os comentarios sao os mesmos do MainWindow::on_btnVsoln_clicked()
void MainWindow::on_btnThdi_clicked()
{
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro);
    arquivoThdi->setFileName(abrirArquivo);
    if(!arquivoThdi->open(QFile::ReadOnly|QFile::Text)){
        if(arquivoThdi->error() == QFile::OpenError){
            return;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return;
    }
    ui->lineEditThdi->setText(arquivoThdi->fileName());
    ui->lineEditThdi->setEnabled(false);
    ui->btnThdi->hide();
    ui->btnLixeiraThdi->show();
    this->setStatusDePreenchimento(2,true);
    verificarAvanco();
    arquivoThdi->close();


}
//Permite a busca e inserção do arquivo Isoln -- Os comentarios sao os mesmos do MainWindow::on_btnVsoln_clicked()
void MainWindow::on_btnIsoln_clicked()
{
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro);
    arquivoIsoln->setFileName(abrirArquivo);
    if(!arquivoIsoln->open(QFile::ReadOnly|QFile::Text)){
        if(arquivoIsoln->error() == QFile::OpenError){
            return;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return;
    }
    ui->lineEditIsoln->setText(arquivoIsoln->fileName());
    ui->lineEditIsoln->setEnabled(false);
    ui->btnIsoln->hide();
    ui->btnLixeiraIsoln->show();
    this->setStatusDePreenchimento(3,true);
    verificarAvanco();
    arquivoIsoln->close();


}
//Permite a busca e inserção do arquivo Ldat -- Os comentarios sao os mesmos do MainWindow::on_btnVsoln_clicked()
void MainWindow::on_btnLdat_clicked()
{
    QString filtro="Todos Arquivos (*.*) ;; Arquivos separados por virgula (*.csv)";
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro);
    arquivoLdat->setFileName(abrirArquivo);
    if(!arquivoLdat->open(QFile::ReadOnly|QFile::Text)){
        if(arquivoLdat->error() == QFile::OpenError){
            return;
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo");
        return;
    }
    ui->lineEditLdat->setText(arquivoLdat->fileName());
    ui->lineEditLdat->setEnabled(false);
    ui->btnLdat->hide();
    ui->btnLixeiraLdat->show();
    this->setStatusDePreenchimento(4,true);
    verificarAvanco();
    arquivoLdat->close();

}
//Exclui o lineEdit do Vsoln
void MainWindow::on_btnLixeiraVsoln_clicked()
{
    //abre uma QMessageBox confirmando se o usuario realmente quer remover o endereço selecionado
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira
    if(escolha==QMessageBox::Yes){
        ui->lineEditVsoln->clear(); //Exclui o conteudo do lineEdit
        ui->btnLixeiraVsoln->hide();  //Esconde o botão de lixeira
        ui->lineEditVsoln->setEnabled(true); //habilita o lineEdit
        ui->btnVsoln->show(); //mostra o botão de pesquisar o arquivo
        this->setStatusDePreenchimento(0,false); //guarda a informação de que destá parte do form não foi inserida
        ui->btnAvancar->setEnabled(false); //desabilita o botão avançar;

    }
    else{
        return;
    }
}
//Exclui o lineEdit do Thdv -- Os comentarios sao os mesmos do MainWindow::on_btnLixeiraVsoln_clicked()
void MainWindow::on_btnLixeiraThdv_clicked()
{
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
     if(escolha==QMessageBox::Yes){
         ui->lineEditThdv->clear();
         ui->btnLixeiraThdv->hide();
         ui->lineEditThdv->setEnabled(true);
         ui->btnThdv->show();
         this->setStatusDePreenchimento(1,false);
         ui->btnAvancar->setEnabled(false);

     }
     else{
         return;
     }
}
//Exclui o lineEdit do Thdi -- Os comentarios sao os mesmos do MainWindow::on_btnLixeiraVsoln_clicked()
void MainWindow::on_btnLixeiraThdi_clicked()
{
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
     if(escolha==QMessageBox::Yes){
         ui->lineEditThdi->clear();
         ui->btnLixeiraThdi->hide();
         ui->lineEditThdi->setEnabled(true);
         ui->btnThdi->show();
         this->setStatusDePreenchimento(2,false);
         ui->btnAvancar->setEnabled(false);

     }
     else{
         return;
     }
}
//Exclui o lineEdit do Isoln -- Os comentarios sao os mesmos do MainWindow::on_btnLixeiraVsoln_clicked()
void MainWindow::on_btnLixeiraIsoln_clicked()
{
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
     if(escolha==QMessageBox::Yes){
         ui->lineEditIsoln->clear();
         ui->btnLixeiraIsoln->hide();
         ui->lineEditIsoln->setEnabled(true);
         ui->btnIsoln->show();
         this->setStatusDePreenchimento(3,false);
         ui->btnAvancar->setEnabled(false);

     }
     else{
         return;
     }
}
//Exclui o lineEdit do Ldat -- Os comentarios sao os mesmos do MainWindow::on_btnLixeiraVsoln_clicked()
void MainWindow::on_btnLixeiraLdat_clicked()
{
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
     if(escolha==QMessageBox::Yes){
         ui->lineEditLdat->clear();
         ui->btnLixeiraLdat->hide();
         ui->lineEditLdat->setEnabled(true);
         ui->btnLdat->show();
         this->setStatusDePreenchimento(4,false);
         ui->btnAvancar->setEnabled(false);

     }
     else{
         return;
     }
}
