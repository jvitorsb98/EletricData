/**
 * @class MainWindow
 * @brief Janela Principal do Programa
 * @author João Vitor N. Ramos
 * @reentrant Essa janela foi construida com 2 frames,
 * um com o intuito de funcionar como uma barra de status do andamento da aplicação(tendo 4 labels como sinalizadores)
 *  e o outro possui componentes reponsáveis por receber endereço de arquivos que serão utilizados nos proximos frames para trataemnto de dados.
*/
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
#include <QtCore/QCoreApplication>

/**
 * @variable MainWindow::frameAtual
 * @brief //Inicializando a variável estática que identifica em que frame a aplicação está rodando.
 *  Seu valor inicial é 0.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int MainWindow::frameAtual=0;

/**
 * @variable MainWindow::arquivoVsoln
 * @variable MainWindow::arquivoIsoln
 * @variable MainWindow::arquivoThdi
 * @variable MainWindow::arquivoThdv
 * @variable MainWindow::arquivoLdat
 * @brief Inicializando as variáveis estáticas responsáveis por apontar para os arquivos que serão inseridos.
 *   A classificação de armazenamento dessas váriaveis foi definida como static pela necessidade dessa variável ser acessada em outros frames para abertura dos arquivos
 */
QFile* MainWindow::arquivoVsoln = new QFile();
QFile* MainWindow::arquivoIsoln = new QFile();
QFile* MainWindow::arquivoThdi  = new QFile();
QFile* MainWindow::arquivoThdv  = new QFile();
QFile* MainWindow::arquivoLdat  = new QFile();

/**
 * @name MainWindow::MainWindow
 * @brief Construtor da classe MainWindow
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCoreApplication::addLibraryPath("C:/Qt/6.5.0/mingw_64/plugins");
    inicializaFrame();

}

/**
 * @name MainWindow::~MainWindow
 * @brief Destrutor da classe MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @name MainWindow::inicializaFrame
 * @brief Primeiro método a ser chamada no construtor, responsável por chamar os métodos subsequêntes que modelam a Interface do frame
 * @return void
 */
void MainWindow::inicializaFrame(){
    insereCssMainWindow();
}

/**
 * @name MainWindow::insereCssMainWindow()
 * @brief Método responsável por chamar métodos que irão inserir Qss na interface do frame
 * @return void
 */
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

/**
 * @name MainWindow::insereIcon
 * @brief Método responsável por inserir o Icon do programa, diretamente do arquivo de recursos, além de inserir o nome do programa
 * @return void
 */
void MainWindow::insereIcon(){
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));
    setWindowTitle("EletricData 1.0");
}

/**
 * @name MainWindow::insereQssBarraDeStatus
 * @brief Método responsável por inserir Qss no frame da barra de status e seus labels, que correspondem em que frame a aplicação está rodando.
 * @return void
 */
void MainWindow::insereQssBarraDeStatus(){
    Style style; // Definição da Classe Style para ser utilizada na função

    ui->txtCarregarArquivos->setStyleSheet(style.cssTxtSelected); //Insere Qss Selecionado no item da barra de Status ( 1. Carregar Arquivos)
    ui->txtTensoesNasBarras->setStyleSheet(style.cssTxt); //Insere Qss no item da barra de Status ( 2. Tensões nas Barras)
    ui->txtPrepararSaida->setStyleSheet(style.cssTxt); //Insere Qss no item da barra de Status ( 3. Preparar Saida)
    ui->txtExportar->setStyleSheet(style.cssTxt); //Insere Qss  no item da barra de Status ( 4. Exportar)
    ui->statusFrame->setStyleSheet(style.cssStatusFrame); // Insere Qss no Frame da Barra de Status
}

/**
 * @name MainWindow::insereQssTitulosLineEdit
 * @brief Método responsável por inserir Qss no frame que recebe endereço dos arquivos e seus labels, que correspondem ao titulo de cada arquivo.
 * @return void
 */
void MainWindow::insereQssTitulosLineEdit(){
    Style style; // Definição da Classe Style para ser utilizada na função

    ui->txtVsoln->setStyleSheet(style.cssTxtArquivos); // Insere Qss No titulo acima do LineEdit Vsoln
    ui->txtThdv->setStyleSheet(style.cssTxtArquivos); // Insere Qss No titulo acima do LineEdit Thdv
    ui->txtThdi->setStyleSheet(style.cssTxtArquivos); // Insere Qss No titulo acima do LineEdit Thdi
    ui->txtIsoln->setStyleSheet(style.cssTxtArquivos); // Insere Qss No titulo acima do LineEdit Isoln
    ui->txtLdat->setStyleSheet(style.cssTxtArquivos); // Insere Qss No titulo acima do LineEdit Ldat
    ui->frameArquivos->setStyleSheet(style.cssFrameArq); // Insere Qss no Frame da Barra Arquivos
}

/**
 * @name MainWindow::insereQssLineEdit
 * @brief Método responsável por inserir Qss nos LineEdits do frame que recebe endereço dos arquivos
 * @return void
 */
void MainWindow::insereQssLineEdit(){
    Style style; // Definição da Classe Style para ser utilizada na função

    ui->lineEditVsoln->setStyleSheet(style.cssLineEdit); //Insere Qss No LineEdit Vsoln
    ui->lineEditThdv->setStyleSheet(style.cssLineEdit); //Insere Qss No LineEdit Thdv
    ui->lineEditThdi->setStyleSheet(style.cssLineEdit); //Insere Qss No LineEdit Thdi
    ui->lineEditIsoln->setStyleSheet(style.cssLineEdit); //Insere Qss No LineEdit Isoln
    ui->lineEditLdat->setStyleSheet(style.cssLineEdit); //Insere Qss No LineEdit Ldat
    ui->lineEditVsoln->setEnabled(false);   //Desativa alteração no lineEditVsoln para que só possa ser alterado pela inserção de texto no botão buscar
    ui->lineEditThdv->setEnabled(false);    //Desativa alteração no lineEditThdv para que só possa ser alterado pela inserção de texto no botão buscar
    ui->lineEditThdi->setEnabled(false);    //Desativa alteração no lineEditThdi para que só possa ser alterado pela inserção de texto no botão buscar
    ui->lineEditIsoln->setEnabled(false);   //Desativa alteração no lineEditIsoln para que só possa ser alterado pela inserção de texto no botão buscar
    ui->lineEditLdat->setEnabled(false);    //Desativa alteração no lineEditLdat para que só possa ser alterado pela inserção de texto no botão buscar
}

/**
 * @name MainWindow::insereQssPlaceHolderLineEdit
 * @brief Método responsável por inserir PlaceHolder nos LineEdits do frame que recebe endereço dos arquivos
 * @return void
 */
void MainWindow::insereQssPlaceHolderLineEdit(){
    Style style; // Definição da Classe Style para ser utilizada na função

    ui->lineEditVsoln->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo"); //Insere Place Holder no LineEdit do Vsoln
    ui->lineEditThdv->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo"); //Insere Place Holder no LineEdit do Thdv
    ui->lineEditThdi->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo"); //Insere Place Holder no LineEdit do Thdi
    ui->lineEditIsoln->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo"); //Insere Place Holder no LineEdit do Isoln
    ui->lineEditLdat->setPlaceholderText("Clique em buscar para inserir o caminho do arquivo"); //Insere Place Holder no LineEdit do Ldat
}

/**
 * @name MainWindow::insereQssBtnArquivos
 * @brief Método responsável por inserir Qss nos botões de buscar endereço dos arquivos
 * @return void
 */
void MainWindow::insereQssBtnArquivos(){
    Style style; // Definição da Classe Style para ser utilizada na função

    ui->btnVsoln->setStyleSheet(style.cssBtn); //Insere Qss no Botão de busca do arquivo Vsoln
    ui->btnThdv->setStyleSheet(style.cssBtn); //Insere Qss no Botão de busca do arquivo Thdv
    ui->btnThdi->setStyleSheet(style.cssBtn); //Insere Qss no Botão de busca do arquivo Thdi
    ui->btnIsoln->setStyleSheet(style.cssBtn); //Insere Qss no Botão de busca do arquivo Isoln
    ui->btnLdat->setStyleSheet(style.cssBtn); //Insere Qss no Botão de busca do arquivo Ldat
}

/**
 * @name MainWindow::insereQssBtnAvancar
 * @brief Método responsável pro inserir Qss no botão de Avançar.
 * Insere Qss no botão para iniciar com aspecto de bloqueado.
 * Insere um icone dentro do botão demonstrando tendencia de seguir em frente, esse icon fica á direita do texto do botão
 * Botão inicia bloqueado, já que só será liberado com a inserção de todos os arquivos nos LineEdits
 * @return void
 */
void MainWindow::insereQssBtnAvancar(){
    Style style; // Definição da Classe Style para ser utilizada na função

    ui->btnAvancar->setStyleSheet(style.cssBtnTransition); // Inserindo Qss no botão avançar
    ui->btnAvancar->setIcon(QIcon(":/icons/imgs/icons/proximo.png")); //Inserção do icon diretamente do arquivo de recursos
    ui->btnAvancar->setLayoutDirection(Qt::RightToLeft); // Icone é inserido a direita do texto
    ui->btnAvancar->setEnabled(false); // Botão inicia desabilitado
}

/**
 * @name MainWindow::insereQssBtnLixeira
 * @brief Método responsável por inserir Qss no botão de apagar dados já inseridos no LineEdit.
 * Nesse botão há a inserção de um icone de lixeira, além do Qss para que seu fundo seja vermelho, indicando uma remoção.
 * O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit
 * @return void
 */
void MainWindow::insereQssBtnLixeira(){
    Style style; // Definição da Classe Style para ser utilizada na função

    //Botões de Checked e lixeira para cada arquivo
    ui->btnLixeiraVsoln->setIcon(QIcon(":/icons/imgs/icons/lixeira.png")); //Inserção do icon diretamente do arquivo de recursos
    ui->btnLixeiraVsoln->setStyleSheet(style.cssBtnLixeira); // Inserindo Qss no botão
    ui->btnLixeiraVsoln->hide();//O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit

    ui->btnLixeiraThdv->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraThdv->setStyleSheet(style.cssBtnLixeira); // Inserindo Qss no botão
    ui->btnLixeiraThdv->hide();//O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit

    ui->btnLixeiraThdi->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraThdi->setStyleSheet(style.cssBtnLixeira); // Inserindo Qss no botão
    ui->btnLixeiraThdi->hide();//O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit

    ui->btnLixeiraIsoln->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraIsoln->setStyleSheet(style.cssBtnLixeira); // Inserindo Qss no botão
    ui->btnLixeiraIsoln->hide();//O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit

    ui->btnLixeiraLdat->setIcon(QIcon(":/icons/imgs/icons/lixeira.png"));
    ui->btnLixeiraLdat->setStyleSheet(style.cssBtnLixeira); // Inserindo Qss no botão
    ui->btnLixeiraLdat->hide();//O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit
}

/**
 * @name MainWindow::insereQssLblVerifica
 * @brief Método responsável por garantir, que os labels responsáveis por indicar que as etapas do Frame de status foram cumpridas, iniciem ocultos.
 * @return void
 */
void MainWindow::insereQssLblVerifica(){
    //os labels de Checked iniciam escondidos já que nada foi realizado ainda
    ui->lblVerifica1->hide();
    ui->lblVerifica2->hide();
    ui->lblVerifica3->hide();
    ui->lblVerifica4->hide();
}

/**
 * @name MainWindow::setaFileNameNosArq
 * @brief seta o FileName dos ponteiros dos arquivos com o que estiver escrito no lineEdit correpondente de cada um.
 * @return void
 */
void MainWindow::setaFileNameNosArq(){
    arquivoVsoln->setFileName(ui->lineEditVsoln->text());   //seta FileName no arquivoVsoln
    arquivoThdi->setFileName(ui->lineEditThdi->text());     //seta FileName no arquivoThdi
    arquivoThdv->setFileName(ui->lineEditThdv->text());     //seta FileName no arquivoThdv
    arquivoIsoln->setFileName(ui->lineEditIsoln->text());   //seta FileName no arquivoIsoln
    arquivoLdat->setFileName(ui->lineEditLdat->text());     //seta FileName no arquivoLdat
}

/**
 * @sa MainWindow::on_btnVsoln_clicked
 * @brief Método que implementa a busca pelo arquivo Vsoln.
 * @return void
 */
void MainWindow::on_btnVsoln_clicked()
{
    Style style;
    QString filtro="Arquivos separados por virgula (*.csv)";     //Configura-se um filtro para pesquisa do arquivo
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro); //inicia a procura, a partir do diretório C::
    arquivoVsoln->setFileName(abrirArquivo); //ao arquivo ser encontrado, grava o endereço no ponteiro arquivoVsoln
    //Tenta realizar a abertura do arquivo
    if(!arquivoVsoln->open(QFile::ReadOnly|QFile::Text)){ //caso não seja realizada a abertura
        if(arquivoVsoln->error() == QFile::OpenError){ //verifica se o usuario não cancelou a busca
            return; // caso tenha cancelado, nada acontece
        }else{
            QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir, é enviado uma messagem de erro
            return;
        }
    }
    //Pós-Abertura com sucesso
    ui->lineEditVsoln->setText(arquivoVsoln->fileName()); // mostra o endereço no lineEdit
    ui->lineEditVsoln->setStyleSheet(style.cssLineEditDisabled); // muda o Qss do lineEdit para disabled
    ui->btnVsoln->hide(); //Esconde o botao de procura
    ui->btnLixeiraVsoln->show(); //mostra o botão de lixeira
    this->setStatusDePreenchimento(0,true); //guarda a informação de que esta parte do form foi inserida
    verificarAvanco(); //verifica se o form está completo para habilitar o botão de avançar
    arquivoVsoln->close(); //realiza fechamento do arquivo
}

/**
 * @sa MainWindow::on_btnThdv_clicked
 * @brief Método que implementa a busca pelo arquivo Thdv.
 * @return void
 */
void MainWindow::on_btnThdv_clicked()
{
    Style style;
    QString filtro="Arquivos separados por virgula (*.csv)"; //Configura-se um filtro para pesquisa do arquivo
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro); //inicia a procura, a partir do diretório C::
    arquivoThdv->setFileName(abrirArquivo); //ao arquivo ser encontrado, grava o endereço no ponteiro arquivoThdv
    //Tenta realizar a abertura do arquivo
    if(!arquivoThdv->open(QFile::ReadOnly|QFile::Text)){ //caso não seja realizada a abertura
        if(arquivoThdv->error() == QFile::OpenError){ //verifica se o usuario não cancelou a busca
            return; // caso tenha cancelado, nada acontece
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir, é enviado uma messagem de erro
        return;
    }
    //Pós-Abertura com sucesso
    ui->lineEditThdv->setText(arquivoThdv->fileName()); // mostra o endereço no lineEdit
    ui->lineEditThdv->setStyleSheet(style.cssLineEditDisabled); // muda o Qss do lineEdit para disabled
    ui->btnThdv->hide(); //Esconde o botao de procura
    ui->btnLixeiraThdv->show(); //mostra o botão de lixeira
    this->setStatusDePreenchimento(1,true); //guarda a informação de que esta parte do form foi inserida
    verificarAvanco(); //verifica se o form está completo para habilitar o botão de avançar
    arquivoThdv->close(); //realiza fechamento do arquivo

}

/**
 * @sa MainWindow::on_btnThdi_clicked
 * @brief Método que implementa a busca pelo arquivo Thdi.
 * @return void
 */
void MainWindow::on_btnThdi_clicked()
{
    Style style;
    QString filtro="Arquivos separados por virgula (*.csv)"; //Configura-se um filtro para pesquisa do arquivo
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro); //inicia a procura, a partir do diretório C::
    arquivoThdi->setFileName(abrirArquivo); //ao arquivo ser encontrado, grava o endereço no ponteiro arquivoThdi
    //Tenta realizar a abertura do arquivo
    if(!arquivoThdi->open(QFile::ReadOnly|QFile::Text)){ //caso não seja realizada a abertura
        if(arquivoThdi->error() == QFile::OpenError){ //verifica se o usuario não cancelou a busca
            return; // caso tenha cancelado, nada acontece
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir, é enviado uma messagem de erro
        return;
    }
    //Pós-Abertura com sucesso
    ui->lineEditThdi->setText(arquivoThdi->fileName()); // mostra o endereço no lineEdit
    ui->lineEditThdi->setStyleSheet(style.cssLineEditDisabled); // muda o Qss do lineEdit para disabled
    ui->btnThdi->hide(); //Esconde o botao de procura
    ui->btnLixeiraThdi->show(); //mostra o botão de lixeira
    this->setStatusDePreenchimento(2,true); //guarda a informação de que esta parte do form foi inserida
    verificarAvanco();  //verifica se o form está completo para habilitar o botão de avançar
    arquivoThdi->close(); //realiza fechamento do arquivo

}
/**
 * @sa MainWindow::on_btnIsoln_clicked
 * @brief Método que implementa a busca pelo arquivo Isoln.
 * @return void
 */
void MainWindow::on_btnIsoln_clicked()
{
    Style style;
    QString filtro="Arquivos separados por virgula (*.csv)"; //Configura-se um filtro para pesquisa do arquivo
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro); //inicia a procura, a partir do diretório C::
    arquivoIsoln->setFileName(abrirArquivo); //ao arquivo ser encontrado, grava o endereço no ponteiro arquivoIsoln
    if(!arquivoIsoln->open(QFile::ReadOnly|QFile::Text)){ //caso não seja realizada a abertura
        if(arquivoIsoln->error() == QFile::OpenError){ //verifica se o usuario não cancelou a busca
            return; // caso tenha cancelado, nada acontece
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir, é enviado uma messagem de erro
        return;
    }
    ui->lineEditIsoln->setText(arquivoIsoln->fileName()); // mostra o endereço no lineEdit
    ui->lineEditIsoln->setStyleSheet(style.cssLineEditDisabled); // muda o Qss do lineEdit para disabled
    ui->btnIsoln->hide(); //Esconde o botao de procura
    ui->btnLixeiraIsoln->show(); //mostra o botão de lixeira
    this->setStatusDePreenchimento(3,true); //guarda a informação de que esta parte do form foi inserida
    verificarAvanco(); //verifica se o form está completo para habilitar o botão de avançar
    arquivoIsoln->close(); //realiza fechamento do arquivo

}

/**
 * @sa MainWindow::on_btnLdat_clicked
 * @brief Método que implementa a busca pelo arquivo Ldat.
 * @return void
 */
void MainWindow::on_btnLdat_clicked()
{
    Style style;
    QString filtro="Arquivos separados por virgula (*.csv)"; //Configura-se um filtro para pesquisa do arquivo
    QString abrirArquivo=QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:://",filtro); //inicia a procura, a partir do diretório C::
    arquivoLdat->setFileName(abrirArquivo); //ao arquivo ser encontrado, grava o endereço no ponteiro arquivoIsoln
    if(!arquivoLdat->open(QFile::ReadOnly|QFile::Text)){ //caso não seja realizada a abertura
        if(arquivoLdat->error() == QFile::OpenError){ //verifica se o usuario não cancelou a busca
            return; // caso tenha cancelado, nada acontece
        }
        QMessageBox::warning(this,"Erro","Erro ao abrir arquivo"); //caso tenha selecionado e não tenha conseguido abrir, é enviado uma messagem de erro
        return;
    }
    ui->lineEditLdat->setText(arquivoLdat->fileName()); // mostra o endereço no lineEdit
    ui->lineEditLdat->setStyleSheet(style.cssLineEditDisabled); // muda o Qss do lineEdit para disabled
    ui->btnLdat->hide();  //Esconde o botao de procura
    ui->btnLixeiraLdat->show(); //mostra o botão de lixeira
    this->setStatusDePreenchimento(4,true); //guarda a informação de que esta parte do form foi inserida
    verificarAvanco(); //verifica se o form está completo para habilitar o botão de avançar
    arquivoLdat->close(); //realiza fechamento do arquivo

}
/**
 * @sa MainWindow::on_btnLixeiraVsoln_clicked
 * @brief Método que implementa a exclusão do endereço para o arquivo Vsoln inserido pelo usuário.
 * @return void
 */
void MainWindow::on_btnLixeiraVsoln_clicked()
{
    Style style;
    //abre uma QMessageBox confirmando se o usuario realmente quer remover o endereço selecionado
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira
    if(escolha==QMessageBox::Yes){
        ui->lineEditVsoln->clear(); //Exclui o conteudo do lineEdit
        ui->lineEditVsoln->setStyleSheet(style.cssLineEdit); // Insere o Qss padrão do lineEdit
        ui->btnLixeiraVsoln->hide();  //Esconde o botão de lixeira
        ui->btnVsoln->show(); //mostra o botão de pesquisar o arquivo
        this->setStatusDePreenchimento(0,false); //guarda a informação de que destá parte do frame não foi inserida
        ui->btnAvancar->setEnabled(false); //desabilita o botão avançar;
    }else{
        return; // caso não queira
    }
}
/**
 * @sa MainWindow::on_btnLixeiraThdv_clicked
 * @brief Método que implementa a exclusão do endereço para o arquivo Thdv inserido pelo usuário.
 * @return void
 */
void MainWindow::on_btnLixeiraThdv_clicked()
{
    Style style;
    //abre uma QMessageBox confirmando se o usuario realmente quer remover o endereço selecionado
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira
    if(escolha==QMessageBox::Yes){
        ui->lineEditThdv->clear(); //Exclui o conteudo do lineEdit
        ui->lineEditThdv->setStyleSheet(style.cssLineEdit); // Insere o Qss padrão do lineEdit
        ui->btnLixeiraThdv->hide();  //Esconde o botão de lixeira
        ui->btnThdv->show(); //mostra o botão de pesquisar o arquivo
        this->setStatusDePreenchimento(1,false); //guarda a informação de que destá parte do frame não foi inserida
        ui->btnAvancar->setEnabled(false); //desabilita o botão avançar;
    }else{
        return; // caso não queira
    }
}
/**
 * @sa MainWindow::on_btnLixeiraThdi_clicked
 * @brief Método que implementa a exclusão do endereço para o arquivo Thdi inserido pelo usuário.
 * @return void
 */
void MainWindow::on_btnLixeiraThdi_clicked()
{
    Style style;
    //abre uma QMessageBox confirmando se o usuario realmente quer remover o endereço selecionado
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira
    if(escolha==QMessageBox::Yes){
        ui->lineEditThdi->clear(); //Exclui o conteudo do lineEdit
        ui->lineEditThdi->setStyleSheet(style.cssLineEdit); // Insere o Qss padrão do lineEdit
        ui->btnLixeiraThdi->hide();  //Esconde o botão de lixeira
        ui->btnThdi->show(); //mostra o botão de pesquisar o arquivo
        this->setStatusDePreenchimento(2,false); //guarda a informação de que destá parte do frame não foi inserida
        ui->btnAvancar->setEnabled(false);  //desabilita o botão avançar;
    }else{
        return;
    }
}
/**
 * @sa MainWindow::on_btnLixeiraIsoln_clicked
 * @brief Método que implementa a exclusão do endereço para o arquivo Isoln inserido pelo usuário.
 * @return void
 */
void MainWindow::on_btnLixeiraIsoln_clicked()
{
    Style style;
    //abre uma QMessageBox confirmando se o usuario realmente quer remover o endereço selecionado
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira
    if(escolha==QMessageBox::Yes){
        ui->lineEditIsoln->clear(); //Exclui o conteudo do lineEdit
        ui->lineEditIsoln->setStyleSheet(style.cssLineEdit); // Insere o Qss padrão do lineEdit
        ui->btnLixeiraIsoln->hide();  //Esconde o botão de lixeira
        ui->btnIsoln->show();  //mostra o botão de pesquisar o arquivo
        this->setStatusDePreenchimento(3,false); //guarda a informação de que destá parte do frame não foi inserida
        ui->btnAvancar->setEnabled(false); //desabilita o botão avançar;
    }else{
        return;
    }
}
/**
 * @sa MainWindow::on_btnLixeiraLdat_clicked
 * @brief Método que implementa a exclusão do endereço para o arquivo Ldat inserido pelo usuário.
 * @return void
 */
void MainWindow::on_btnLixeiraLdat_clicked()
{
    Style style;
    //abre uma QMessageBox confirmando se o usuario realmente quer remover o endereço selecionado
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Remover Endereço","Remover o endereço selecionado?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira
    if(escolha==QMessageBox::Yes){
        ui->lineEditLdat->clear(); //Exclui o conteudo do lineEdit
        ui->lineEditIsoln->setStyleSheet(style.cssLineEdit); // Insere o Qss padrão do lineEdit
        ui->btnLixeiraLdat->hide(); //Esconde o botão de lixeira
        ui->btnLdat->show();  //mostra o botão de pesquisar o arquivo
        this->setStatusDePreenchimento(4,false);  //guarda a informação de que destá parte do frame não foi inserida
        ui->btnAvancar->setEnabled(false); //desabilita o botão avançar;
    }else{
        return;
    }
}
/**
 * @sa MainWindow::on_btnLixeiraLdat_clicked
 * @brief Método que implementa a transição do Frame MainWindow para o FrameTensoes atráves do botão avançar
 * @return void
 */
void MainWindow::on_btnAvancar_clicked()
{
    //abre uma QMessageBox confirmando se os dados estão certos para poder avançar
    QMessageBox::StandardButton escolha;
    escolha = QMessageBox::question(this,"Inserir Arquivos","Os arquivos inseridos estão corretos?",QMessageBox::Yes|QMessageBox::No);
    //Caso queira escolha sim
    if(escolha==QMessageBox::Yes){
        setaFileNameNosArq();
        //Declara e instancia o frame da nova janela
        FrameTensoes *frame = new FrameTensoes(this,ui);
        ui->frameArquivos->hide(); // esconde a janela anterior
        //configura a janela
        frame->setParent(this); //insere como parent, o MainWindow
        frame->setGeometry(224,0,800,720); //seta para ter o mesmo tamanho do Frame Arquivos
        frameAtual++; // atualiza o indice de status
        MainWindow::atualizarStatus(ui); // atualiza a barra de status
        frame->show(); // mostra a nova janela
    }
    else{
        return; // caso não ,apenas retorna a janela atual
    }
}
/**
 * @name MainWindow::verificarAvanco()
 * @brief Método responsável por habilitar o botão avançar caso todos os LineEdits estejam preenchdiso
 * @return void
 */
void MainWindow::verificarAvanco(){

     for (int i = 0 ; i < 5; i++ ) {
         if(!this->getStatusDePreenchimento(i)){
            return;
         }
     }
     ui->btnAvancar->setEnabled(true);
}
