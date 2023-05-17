/**
 * @class FrameTensoes
 * @brief Janela responsável pela aquisição dos dados de tensão nominal do sistema elétrico
 * @reentrant Essa janela foi construida com 1 frame que se posiciona no mesmo local do frame responsável por receber os arquivos no MainWindow,
 * nele há um QTableWidget para inserção dos valores das tensões, seja por inserção manual ou para importar um arquivo com esses dados. Além de botões de salva, avançar e voltar.
 * @author João Vitor N. Ramos
*/

#include "frametensoes.h"
#include "framebarras.h"
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QScrollBar>
#include<QDebug>
#include<QTextStream>
#include "style.h"


/**
 * @variable QFile* MainWindow::arquivoTensoes
 * @brief Variável estática responsável por apontar para o arquivo que armazenará
 *  os valores das tensões nominais das barras do sistema elétrico
 */
QFile* MainWindow::arquivoTensoes  = new QFile();

/**
 * @variable QList<double> FrameTensoes::tensoesNominais
 * @brief Variável responsável por armazenar os valores das tensões nominais das barras
 *  para utilizar esses dados posteriormente no decorrer da aplicação
 */
QList<double> FrameTensoes::tensoesNominais;

/**
 * @variable Ui::MainWindow *frameMain
 * @brief Variavel que permite acessar o 'Ui' do MainWindow. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::MainWindow *frameMain;

/**
 * @variable int FrameTensoes::numeroDeBarras
 * @brief Variavel que armazenará o numero de barras do sistema, apartir da leitura dos arquivos inseridos no frame MainWindow
 */
int FrameTensoes::numeroDeBarras;

/**
 * @name FrameTensoes::FrameTensoes
 * @brief Construtor da classe FrameTensoes
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 * @param mw (Parãmetro do tipo Ui::MainWindow para permitir acesso aos componentes da interface do frame MainWindow)
 */
FrameTensoes::FrameTensoes(QWidget *parent,Ui::MainWindow *mw) :
    QFrame(parent),

    ui(new Ui::FrameTensoes)
{
    ui->setupUi(this);

    frameMain = mw; // atribui a váriavel global o endereço que memória responsável por apontar para o Ui::MainWindow

    inicializaFrame();

    // Conecta o sinal itemChanged da tabela tableTensoes ao slot verificarPreenchimentoTabela
    connect(ui->tableTensoes, &QTableWidget::itemChanged, this, &FrameTensoes::verificarPreenchimentoTabela);
    // Isso permite que o slot verificarPreenchimentoTabela seja chamado sempre que um item da tabela for alterado
}

/**
 * @name FrameTensoes::~FrameTensoes
 * @brief Destrutor da classe FrameTensoes
 */
FrameTensoes::~FrameTensoes()
{
    delete ui;
}

/**
 * @name FrameTensoes::inicializaFrame
 * @brief Primeiro método a ser chamada no construtor, responsável por chamar os métodos subsequêntes que modelam a Interface do frame. Além de chamar o método que irá inicializar a váriavel numeroDeBarras
 * @return void
 */
void FrameTensoes::inicializaFrame(){
    numeroDeBarras=quantidadeDeBarras();
    insereQssFrameTensoes();
}

/**
 * @name FrameTensoes::insereQssFrameTensoes
 * @brief Método responsável por chamar métodos que irão inserir Qss na interface do frame
 * @return void
 */
void FrameTensoes::insereQssFrameTensoes(){
    insereQssBotaoAvancar();
    insereQssImportar();
    insereQssBtnVoltar();
    insereQssBtnLixeira();
    insereQssBtnSalvar();
    insereQssFrame();
    insereTableTensoes();
}

/**
 * @name FrameTensoes::insereQssBotaoAvancar
 * @brief Método responsável por inserir Qss no botão de Avançar.
 * Insere Qss no botão para iniciar com aspecto de bloqueado.
 * Insere um icone dentro do botão demonstrando tendencia de seguir em frente, esse icon fica á direita do texto do botão
 * Botão inicia bloqueado, já que só será liberado com a inserção de todos os arquivos nos LineEdits
 * @return void
 */
void FrameTensoes::insereQssBotaoAvancar(){
    Style style;
    ui->btnAvancar->setStyleSheet(style.cssBtnTransition); // Inserindo Qss no botão avançar
    ui->btnAvancar->setIcon(QIcon(":/icons/imgs/icons/proximo.png")); //Inserção do icon diretamente do arquivo de recursos
    ui->btnAvancar->setLayoutDirection(Qt::RightToLeft); // Icone é inserido a direita do texto
    ui->btnAvancar->setEnabled(false); // Botão inicia desabilitado , para só ser ativado após o preenchimento dos valores de tensão
}

/**
 * @name FrameTensoes::insereQssImportar
 * @brief Método responsável por inserir Qss no Botão importar e no seu lineEdit correspondente
 * @return void
 */
void FrameTensoes::insereQssImportar(){
    Style style;
    ui->btnImportar->setStyleSheet(style.cssBtn); // Inserindo Qss no botão
    ui->lineEditImportar->setStyleSheet(style.cssLineEdit); // Inserindo Qss no LineEdit
}

/**
 * @name FrameTensoes::insereQssBtnVoltar
 * @brief Método responsável por inserir Qss no Botão voltar.
 * Insere  Qss padrão de botão nele e um icone dentro do botão indicando uma tendência de retornar,esse icon fica á esquerda do texto do botão
 * @return void
 */
void FrameTensoes::insereQssBtnVoltar(){
    Style style;
    ui->btnVoltar->setStyleSheet(style.cssBtn); // Inserindo Qss no botão
    ui->btnVoltar->setIcon(QIcon(":/icons/imgs/icons/anterior.png")); //Inserção do icon diretamente do arquivo de recursos
}

/**
 * @name FrameTensoes::insereQssBtnLixeira
 * @brief Método responsável por inserir Qss no botão de apagar dados já inseridos no LineEdit.
 * Nesse botão há a inserção de um icone de lixeira, além do Qss para que seu fundo seja vermelho, indicando uma remoção.
 * O botão inicia escondido, para só ser mostrado após ter algo inserido no LineEdit
 * @return void
 */
void FrameTensoes::insereQssBtnLixeira(){
    Style style;
    ui->btnLixeira->hide(); //O botão inicia escondido, para só ser mostrado após ter algo inserido pelo botão importar
    ui->btnLixeira->setStyleSheet(style.cssBtnLixeira); // Inserindo Qss no botão
    ui->btnLixeira->setIcon(QIcon(":/icons/imgs/icons/lixeira.png")); //Inserção do icon diretamente do arquivo de recursos
}

/**
 * @name FrameTensoes::insereQssBtnSalvar
 * @brief Método responsável por inserir Qss no Botão salvar.
 * Insere  Qss padrão de botão nele e um icone dentro do botão indicando uma tendência de salvar
 * @return void
 */
void FrameTensoes::insereQssBtnSalvar(){
    Style style;
    ui->btnSalvarTabela->setStyleSheet(style.cssBtn); // Inserindo Qss no botão
    ui->btnSalvarTabela->setIcon(QIcon(":/icons/imgs/icons/salve-.png")); //Inserção do icon diretamente do arquivo de recursos
}

/**
 * @name FrameTensoes::insereQssFrame
 * @brief Método responsável por inserir Qss no frame atual
 * @return void
 */
inline void FrameTensoes::insereQssFrame(){
    Style style;
    this->setStyleSheet(style.cssFrameArq);
};

/**
 * @name  FrameTensoes::insereTableTensoes
 * @brief  Insere e configura uma tabela de tensões na interface do usuário.
 * @return void
 */
void FrameTensoes::insereTableTensoes()
{
    Style style;

    // Configuração da tabela de tensões
    ui->tableTensoes->setColumnCount(2); // Duas colunas por ser uma para o indice e a outra para o nível de tensão
    ui->tableTensoes->setRowCount(numeroDeBarras); // A tabela tem como numero de linhas , o número de barras do sistema
    ui->tableTensoes->setHorizontalHeaderLabels({"Barra", "Tensão [Kv]"}); // headers para as duas colunas
    ui->tableTensoes->setColumnWidth(0, 100); // Define a largura da coluna na posição 0
    ui->tableTensoes->setColumnWidth(1, (numeroDeBarras <= 17) ? 358 : 346); // define a largura da coluna na posição 1 (segunda coluna) da tabela tableTensoes, dependendo do valor da variável numeroDeBarras. Isso foi inserido para evitar que o scroolBar vertical seja ativado quando desnecessário.
    ui->tableTensoes->verticalScrollBar()->setVisible(true); // garante um scroolBar vertical sempre visivel
    ui->tableTensoes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // garante um scroolBar horizontal não visivel
    ui->tableTensoes->setStyleSheet(style.csstabelaTensoes); //insere Qss na TabelaTensões
    ui->tableTensoes->horizontalHeader()->setStyleSheet(style.cssHeaderTabela); //insere Qss no Header vertical
    ui->tableTensoes->setAlternatingRowColors(true); //insere alternancia de cores entre as linhas da tabela
    ui->tableTensoes->verticalHeader()->setVisible(false);
    // Preenchimento das linhas da tabela com o índice das barras
    for (int i = 0; i < numeroDeBarras; i++) {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(i+1));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        ui->tableTensoes->setItem(i, 0, item);
    }
}

/**
 * @name  FrameTensoes::on_btnVoltar_clicked
 * @brief  Método responsável pelo evento do botão voltar
 * @return void
 */
void FrameTensoes::on_btnVoltar_clicked(){
    MainWindow::frameAtual--;
    MainWindow::atualizarStatus(frameMain);

    frameMain->frameArquivos->show();
    this->close();

}

/**
 * @name FrameTensoes::quantidadeDeBarras
 * @brief Método responsável por cálcular o número de barras do sistema
 * @return valor inteiro do numero de barras do sistema
 */
int FrameTensoes::quantidadeDeBarras()
{
    QFile *arq1 = MainWindow::arquivoThdv;

    if (!arq1->open(QFile::ReadOnly | QFile::Text)) {
        if (arq1->error() == QFile::OpenError) {
            return 0;
        }
        QMessageBox::warning(this, "Erro", "Erro ao abrir arquivo");
        return 0;
    }

    int contador = 0;
    QTextStream entrada(arq1);

    while (!arq1->atEnd()) {
        arq1->readLine();
        contador++;
    }

    arq1->close();
    return contador - 3;
}

/**
 * @sa FrameTensoes::on_btnImportar_clicked
 * @brief Método responsável por importar valores de tensões de um arquivo externo e inseri-los na tabela, caso estejam no formato correto.
 * @return void
 */
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
    ui->lineEditImportar->setText(MainWindow::arquivoTensoes->fileName());
    ui->lineEditImportar->setEnabled(false);
    ui->btnImportar->hide();
    ui->btnLixeira->show();

    int linhaAtual = 0;

    try {
        for (int i = 0; i < numeroDeBarras; i++) {
            QString line = MainWindow::arquivoTensoes->readLine();
            if (line.isNull()) {
                throw std::runtime_error("O arquivo possui menos linhas do que o esperado.");
            }

            QStringList infos = line.split(",");
            if (infos.size() != 2) {
                throw std::runtime_error("O arquivo está no formato incorreto.");
            }

            bool ok;
            if (!infos.at(0).toInt(&ok)) {
                throw std::runtime_error("O arquivo contém um valor inválido para o índice da barra.");
            }

            double tensao = infos.at(1).toDouble(&ok);
            if (!ok) {
                throw std::runtime_error("O arquivo contém um valor inválido para o nível de tensão.");
            }

            QTableWidgetItem* item = new QTableWidgetItem(QString::number(tensao));
            ui->tableTensoes->setItem(i, 1, item);

            linhaAtual++;
        }

        // Verifica se existem mais linhas no arquivo além da quantidade de barras esperada
        QString extraLine = MainWindow::arquivoTensoes->readLine();
        if (!extraLine.isNull()) {
            throw std::runtime_error("O arquivo possui mais linhas do que o esperado.");
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Erro", e.what());
        // Limpa as células da tabela que foram preenchidas antes do erro
        for (int i = 0; i < linhaAtual; i++) {
            ui->tableTensoes->setItem(i, 1, nullptr);
        }
    }
}

/**
 * @sa FrameTensoes::on_btnLixeira_clicked
 * @brief Método responsável por implementar a ação ao clicar o botão lixeira.
 * @return void
 */
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

/**
 * @sa FrameTensoes::on_btnSalvarTabela_clicked
 * @brief Método responsável por implementar a ação ao clicar o botão Salvar
 * @return void.
 */
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

/**
 * @sa FrameTensoes::on_btnAvancar_clicked
 * @brief Método responsável por implementar a ação ao clicar o botão Avançar
 * @return void.
 */
void FrameTensoes::on_btnAvancar_clicked()
{
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

    for(int i = 0 ; i < numeroDeBarras ; i++){
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

/**
 * @name FrameTensoes::tabelaTensoesPreenchida
 * @brief Método responsável por verificar se toda a tabela está preenchida
 * @return Retorna verdadeiro se a tabela estiver completamente preenchida e falso, caso o contrario;
 */
bool FrameTensoes::tabelaTensoesPreenchida()
{
    // Percorre todas as linhas e colunas da tabela
    for (int row = 0; row < ui->tableTensoes->rowCount(); row++) {
        for (int column = 0; column < ui->tableTensoes->columnCount(); column++) {
            QTableWidgetItem* item = ui->tableTensoes->item(row, column);
            // Obtém o item da célula da tabela

            if (item == nullptr || item->text().isEmpty()) {
                // Verifica se o item é nulo ou se o texto está vazio
                return false;
                // Retorna falso se a tabela não estiver completamente preenchida
            }
        }
    }

    return true;
    // Retorna verdadeiro se a tabela estiver completamente preenchida
}

/**
 * @name FrameTensoes::verificarPreenchimentoTabela
 * @brief Verifica se todas as células da tabela estão preenchidas e habilita/desabilita o botão "Avançar" de acordo com o resultado.
 * @param item Ponteiro para o item alterado na tabela (não utilizado no código).
 * @return void
 */
void FrameTensoes::verificarPreenchimentoTabela(QTableWidgetItem* item)
{
    Q_UNUSED(item);
    // Ignora o argumento, se não for usado no slot

    if (tabelaTensoesPreenchida()) {
        // Verifica se a tabela está completamente preenchida
        ui->btnAvancar->setEnabled(true);
        // Habilita o botão "Avançar"
    } else {
        ui->btnAvancar->setEnabled(false);
        // Desabilita o botão "Avançar"
    }
    // Realiza as ações necessárias com o resultado obtido
}



