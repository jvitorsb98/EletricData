/**
 * @class FiltroLinha
 * @brief Janela responsável pela inserção dos filtros do TableLinhas do FrameBarras
 * @author João Vitor N. Ramos
*/

#include "filtrolinha.h"
#include "ui_filtrolinha.h"
#include "style.h"
#include "framebarras.h"
#include <QMessageBox>

/**
 * @variable bool FiltroLinha::correntePu
 * @brief Variável estática que identifica se o checkBox da corrente na linha dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::correntePu = true;

/**
 * @variable bool FiltroLinha::dht
 * @brief Variável estática que identifica se o checkBox do dht dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::dht = true;

/**
 * @variable bool FiltroLinha::dit
 * @brief Variável estática que identifica se o checkBox do dit dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::dit = true;

/**
 * @variable bool FiltroLinha::ditPercent
 * @brief Variável estática que identifica se o checkBox do dit percentual dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::ditPercent = true;

/**
 * @variable bool FiltroLinha::correnteEficaz
 * @brief Variável estática que identifica se o checkBox da corrente eficaz dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::correnteEficaz = true;

/**
 * @variable bool FiltroLinha::resistencia
 * @brief Variável estática que identifica se o checkBox da resistência dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::resistencia = true;

/**
 * @variable bool FiltroLinha::perdas
 * @brief Variável estática que identifica se o checkBox das perdas dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::perdas = true;

/**
 * @variable bool FiltroLinha::perdasEficaz
 * @brief Variável estática que identifica se o checkBox das perdas eficaz dos filtros da linha está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltroLinha::perdasEficaz = true;

/**
 * @variable int  FiltroLinha::indexComboBoxOrigem
 * @brief Variável estática que identifica qual checkbox está selecionado para a origem das linhas ( 0 para todas as linhas , 1 para selecionar as origens)
 *  Seu valor inicial é 0.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int  FiltroLinha::indexComboBoxOrigem = 0;

/**
 * @variable int  FiltroLinha::indexComboBoxDestino
 * @brief Variável estática que identifica qual checkbox está selecionado para a destino das linhas ( 0 para todas as linhas , 1 para selecionar os destinos)
 *  Seu valor inicial é 0.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int FiltroLinha::indexComboBoxDestino = 0;

/**
 * @variable int  FiltroLinha::indexComboBoxOrigemEnvio
 * @brief Variável estática que identifica qual tipo de filtragem das linhas para a origem foi a ultima a ser selecionada e concluida
 *  Seu valor inicial é 0.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int FiltroLinha::indexComboBoxOrigemEnvio=0;

/**
 * @variable int  FiltroLinha::indexComboBoxDestinoEnvio
 * @brief Variável estática que identifica qual tipo de filtragem das linhas para o destino foi a ultima a ser selecionada e concluida
 *  Seu valor inicial é 0.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int FiltroLinha::indexComboBoxDestinoEnvio=0;

/**
 * @variable Ui::FrameBarras *frameBarras2
 * @brief Variavel que permite acessar o 'Ui' do FrameBarras. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::FrameBarras *frameBarras2;

/**
 * @variable
 * @brief Variável estática responsável por armazenar o indice das origens escolhidas em um QStringList.
 * Caso seja escolhido o metodo de selecionar as linhas de forma individual, as origens sao separadas por virgula.
 */
QStringList FiltroLinha::indiceOrigensEscolhidas;

/**
 * @variable
 * @brief Variável estática responsável por armazenar o indice dos destinos escolhidas em um QStringList.
 * Caso seja escolhido o metodo de selecionar as linhas de forma individual, os destinos sao separados por virgula.
 */
QStringList FiltroLinha::indiceDestinosEscolhidos;

/**
 * @name FiltroLinha::FiltroLinha
 * @brief Construtor da classe FiltroLinha
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 * @param fb (Parãmetro do tipo Ui::FrameBarras para permitir acesso aos componentes da interface do frame FrameBarras)
 */
FiltroLinha::FiltroLinha(QWidget *parent,  Ui::FrameBarras *fb) :
    QDialog(parent),
    ui(new Ui::FiltroLinha)
{
    ui->setupUi(this);
    Style style;
    setParent(parent);
    frameBarras2 = fb;

    inicializandoFrame();

}

/**
 * @name FiltrosBarra::~FiltroLinha
 * @brief Destrutor da classe FiltroLinha
 */
FiltroLinha::~FiltroLinha()
{
    delete ui;
}

/**
 * @name FiltroLinha::inicializandoFrame
 * @brief Primeiro método a ser chamada no construtor, responsável por chamar os métodos subsequêntes que modelam a Interface do frame.
 * @return void
 */
void FiltroLinha::inicializandoFrame(){
    inserindoQssFiltrosLinha();
}

/**
 * @name FiltroLinha::inserindoQssFiltrosLinha
 * @brief Método responsável por chamar métodos que inserem Qss nos componentes do frame
 * @return void
 */
void FiltroLinha::inserindoQssFiltrosLinha(){
    inserindoQssCheckBox();
    inserindoQssLineEdit();
    inserindoQssBtnAplicar();
    inserindoQssComboBox();
    inserindoQssGroupBox();
    inserindoQssJanela();
}


/**
 * @name FiltroLinha::inserindoQssCheckBox
 * @brief Método responsável por inserir Qss nos Checkbox's do frame
 * @return void
 */
void FiltroLinha::inserindoQssCheckBox(){
    Style style;
    ui->checkBoxCorrente->setChecked(correntePu);
    ui->checkBoxDht->setChecked(dht);
    ui->checkboxDit->setChecked(dit);
    ui->checkBoxDitPercent->setChecked(ditPercent);
    ui->checkBoxCorrenteEficaz->setChecked(correnteEficaz);
    ui->checkBoxResistencia->setChecked(resistencia);
    ui->checkBoxPerdas->setChecked(perdas);
    ui->checkBoxPerdasEficaz->setChecked(perdasEficaz);

    ui->checkBoxCorrente->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDht->setStyleSheet(style.cssCheckbox);
    ui->checkboxDit->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDitPercent->setStyleSheet(style.cssCheckbox);
    ui->checkBoxCorrenteEficaz->setStyleSheet(style.cssCheckbox);
    ui->checkBoxResistencia->setStyleSheet(style.cssCheckbox);
    ui->checkBoxPerdas->setStyleSheet(style.cssCheckbox);
    ui->checkBoxPerdasEficaz->setStyleSheet(style.cssCheckbox);
}

/**
 * @name FiltroLinha::inserindoQssLineEdit
 * @brief Método responsável por inserir Qss no LineEdit
 * @return void
 */
void FiltroLinha::inserindoQssLineEdit(){
    Style style;
    ui->lineEditFLinha->setPlaceholderText("Todas");
    ui->lineEditFLinha2->setPlaceholderText("Todas");


    ui->lineEditFLinha->setStyleSheet(style.cssLineEdit);
    ui->lineEditFLinha2->setStyleSheet(style.cssLineEdit);

    ui->lineEditFLinha->setEnabled(false);
    ui->lineEditFLinha2->setEnabled(false);
}

/**
 * @name FiltroLinha::inserindoQssBtnAplicar
 * @brief Método responsável por inserir Qss no botão Aplicar
 * @return void
 */
void FiltroLinha::inserindoQssBtnAplicar(){
    Style style;
    ui->btnAplicar->setStyleSheet(style.cssBtn);

}

/**
 * @name FiltroLinha::inserindoQssComboBox
 * @brief Método responsável por inserir Qss no ComboBox
 * @return void
 */
void FiltroLinha::inserindoQssComboBox(){
    Style style;
    ui->comboBoxOrigem->setCurrentIndex(indexComboBoxOrigem);
    ui->comboBoxDestino->setCurrentIndex(indexComboBoxDestino);

}

/**
 * @name FiltroLinha::inserindoQssGroupBox
 * @brief Método responsável por inserir Qss nos GroupBox's
 * @return void
 */
void FiltroLinha::inserindoQssGroupBox(){
    Style style;
    ui->groupBoxAtributos->setStyleSheet(style.cssGroupBox);
    ui->groupBoxLinhas->setStyleSheet(style.cssGroupBox);
}

/**
 * @name FiltroLinha::inserindoQssJanela
 * @brief Método responsável por inserir icon e title na janela
 * @return void
 */
void FiltroLinha::inserindoQssJanela(){
    setWindowTitle("Filtros");
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));
}

/**
 * @name FiltroLinha::on_comboBoxOrigem_currentIndexChanged
 * @brief Método responsável por trocar o place holder e controlar a possibilidade de alterar o valor que estará no LineEdit ao trocar o ComboBoxOrigem
 * @param index
 * @return void
 */
void FiltroLinha::on_comboBoxOrigem_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lineEditFLinha->setPlaceholderText("Todas");
        ui->lineEditFLinha->setEnabled(false);
    }else{
        ui->lineEditFLinha->setPlaceholderText("1,2,3,4");
        ui->lineEditFLinha->setEnabled(true);
    }

    indexComboBoxOrigem = index;
}

/**
 * @name FiltroLinha::on_comboBoxDestino_currentIndexChanged
 * @brief Método responsável por trocar o place holder e controlar a possibilidade de alterar o valor que estará no LineEdit ao trocar o ComboBoxDestino
 * @param index
 * @return void
 */
void FiltroLinha::on_comboBoxDestino_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lineEditFLinha2->setPlaceholderText("Todas");
        ui->lineEditFLinha2->setEnabled(false);
    }else{
        ui->lineEditFLinha2->setPlaceholderText("1,2,3,4");
        ui->lineEditFLinha2->setEnabled(true);
    }

    indexComboBoxDestino = index;
}


/**
 * @name FiltroLinha::on_btnAplicar_clicked
 * @brief Método responsável por implementar o evento do botão aplicar.
 * Atualiza as variaveis estáticas, filtras as linhas da tabela e seleciona quais linhas serão mostradas na tabela
 * @return void
 */
void FiltroLinha::on_btnAplicar_clicked()
{

    atualizaVariaveis();
    filtrarLinhasTabela();
    filtrarColunasTabela();
    close();
}

/**
 * @name FiltroLinha::atualizaVariaveis
 * @brief Método responsável por atualizar variaveis estáticas
 * @return void
 */
void FiltroLinha::atualizaVariaveis(){
    correntePu = ui->checkBoxCorrente->isChecked();
    dht = ui->checkBoxDht->isChecked();
    dit = ui->checkboxDit->isChecked();
    ditPercent = ui->checkBoxDitPercent->isChecked();
    correnteEficaz = ui->checkBoxCorrenteEficaz->isChecked();
    resistencia = ui->checkBoxResistencia->isChecked();
    perdas = ui->checkBoxPerdas->isChecked();
    perdasEficaz = ui->checkBoxPerdasEficaz->isChecked();
}

/**
 * @name FiltroLinha::filtrarLinhasTabela
 * @brief Método responsável por filtrar as linhas da tabela Linhas
 * @return void
 */
void FiltroLinha::filtrarLinhasTabela(){
    if(!correntePu){
        frameBarras2->tableLinhas->setRowHidden(0,true);
    }else{
        frameBarras2->tableLinhas->setRowHidden(0,false);
    }
    if(!dht){
        frameBarras2->tableLinhas->setRowHidden(1,true);
    }else{
        frameBarras2->tableLinhas->setRowHidden(1,false);
    }
    int pos =2;
    for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
        if(!dit){
            frameBarras2->tableLinhas->setRowHidden(pos,true);
            pos++;
        }else{
            frameBarras2->tableLinhas->setRowHidden(pos,false);
            pos++;
        }
    }
    for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
        if(!ditPercent){
            frameBarras2->tableLinhas->setRowHidden(pos,true);
            pos++;
        }else{
            frameBarras2->tableLinhas->setRowHidden(pos,false);
            pos++;
        }
    }
    if(!correnteEficaz){
        frameBarras2->tableLinhas->setRowHidden(pos,true);
        pos++;
    }else{
        frameBarras2->tableLinhas->setRowHidden(pos,false);
        pos++;
    }

    if(!resistencia){
        frameBarras2->tableLinhas->setRowHidden(pos,true);
        pos++;
    }else{
        frameBarras2->tableLinhas->setRowHidden(pos,false);
        pos++;
    }

    if(!perdas){
        frameBarras2->tableLinhas->setRowHidden(pos,true);
        pos++;
    }else{
        frameBarras2->tableLinhas->setRowHidden(pos,false);
        pos++;
    }

    if(!perdasEficaz){
        frameBarras2->tableLinhas->setRowHidden(pos,true);
        pos++;
    }else{
        frameBarras2->tableLinhas->setRowHidden(pos,false);
        pos++;
    }
}

/**
 * @name FiltroLinha::filtrarColunasTabela
 * @brief Método responsável por chamar metodos que filtram as colunas à depender da escolha do usúario
 * @return void
 */
void FiltroLinha::filtrarColunasTabela(){
    //filtra as colunas da tabela
    if(indexComboBoxOrigem==0 && indexComboBoxDestino==0){
        filtrarColTod1Tod2();
    }else if (indexComboBoxOrigem == 0 && indexComboBoxDestino == 1) {
        filtrarColTod1Ind2();
    }
    else if (indexComboBoxOrigem == 1 && indexComboBoxDestino == 0) {
        filtrarColInd1Tod2();
    }else{
        filtrarColInd1Ind2();
    }
}

/**
 * @name FiltroLinha::filtrarColTod1Tod2
 * @brief Método responsável por filtrar as colunas - Aparecerão todas as linhas
 * @return void
 */
void FiltroLinha::filtrarColTod1Tod2(){
    for(int i = 0 ; i < FrameBarras::numeroDeLinhas ; i++){
        frameBarras2->tableLinhas->setColumnHidden(i,false);
    }
}

/**
 * @name FiltroLinha::filtrarColTod1Ind2
 * @brief Método responsável por filtrar as colunas - Aparecerão todas que correponderem aos destinos escolhidos
 * @return void
 */
void FiltroLinha::filtrarColTod1Ind2(){
    try {
        QString Selecionadas = ui->lineEditFLinha2->text().trimmed();

        if (Selecionadas.isEmpty()) {
            throw std::runtime_error("O campo não pode ser vazio.");
        }

        for (int i = 0; i < FrameBarras::numeroDeLinhas; i++) {
            frameBarras2->tableLinhas->setColumnHidden(i, false);
        }

        QStringList indices = Selecionadas.split(",");
        for (int i = 0; i < FrameBarras::numeroDeLinhas; i++) {
            int barraDeDestino = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(1).toInt();
            bool encontrada = false;
            for (int j = 0; j < indices.size(); j++) {
                if (indices.at(j).toInt() == barraDeDestino) {
                    encontrada = true;
                    break;
                }
            }
            if (!encontrada) {
                frameBarras2->tableLinhas->setColumnHidden(i, true);
            }
        }

        indiceDestinosEscolhidos = indices;
        indexComboBoxDestinoEnvio = indexComboBoxDestino;
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Erro", e.what());
        return;
    }
}

/**
 * @name FiltroLinha::filtrarColInd1Tod2
 * @brief Método responsável por filtrar as colunas - Aparecerão todas que correponderem as origens  escolhidas
 * @return void
 */
void FiltroLinha::filtrarColInd1Tod2(){
    for (int i = 0; i < FrameBarras::numeroDeLinhas; i++) {
        frameBarras2->tableLinhas->setColumnHidden(i, false);
    }

    try {
        QString Selecionadas = ui->lineEditFLinha->text().trimmed();

        if (Selecionadas.isEmpty()) {
            throw std::runtime_error("O campo não pode ser vazio.");
        }

        QStringList selecionadas = Selecionadas.split(",");

        for (int i = 0; i < FrameBarras::numeroDeLinhas; i++) {
            int barraDeOrigem = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(0).toInt();
            bool selecionadaEncontrada = false;
            for (const QString& selecionada : selecionadas) {
                if (selecionada.toInt() == barraDeOrigem) {
                    selecionadaEncontrada = true;
                    break;
                }
            }
            if (!selecionadaEncontrada) {
                frameBarras2->tableLinhas->setColumnHidden(i, true);
            } else {
                frameBarras2->tableLinhas->setColumnHidden(i, false);
            }
        }

        indiceOrigensEscolhidas = selecionadas;
        indexComboBoxOrigemEnvio = indexComboBoxOrigem;
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Erro", e.what());
        return;
    }
}

/**
 * @name FiltroLinha::filtrarColInd1Ind2
 * @brief Método responsável por filtrar as colunas - Aparecerão todas que correponderem as origens e aos destinos escolhidos
 * @return void
 */
void FiltroLinha::filtrarColInd1Ind2(){
    for (int i = 0; i < FrameBarras::numeroDeLinhas; i++) {
        frameBarras2->tableLinhas->setColumnHidden(i, false);
    }

    QStringList SelecionadasOrigem;
    QStringList SelecionadasDestino;

    try {
        SelecionadasOrigem = ui->lineEditFLinha->text().split(",");
        if (SelecionadasOrigem.isEmpty()) {
            throw std::runtime_error("A lista de origens selecionadas está vazia.");
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Erro", e.what());
        return;
    }

    try {
        SelecionadasDestino = ui->lineEditFLinha2->text().split(",");
        if (SelecionadasDestino.isEmpty()) {
            throw std::runtime_error("A lista de destinos selecionados está vazia.");
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Erro", e.what());
        return;
    }

    for (int i = 0; i < FrameBarras::numeroDeLinhas; i++) {
        int barraDeDestino = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(1).toInt();
        int barraDeOrigem = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(0).toInt();

        bool origemEncontrada = false;
        bool destinoEncontrado = false;

        for (int j = 0; j < SelecionadasOrigem.size(); j++) {
            if (SelecionadasOrigem.at(j).toInt() == barraDeOrigem) {
                origemEncontrada = true;
                break;
            }
        }

        for (int j = 0; j < SelecionadasDestino.size(); j++) {
            if (SelecionadasDestino.at(j).toInt() == barraDeDestino) {
                destinoEncontrado = true;
                break;
            }
        }

        if (!origemEncontrada || !destinoEncontrado) {
            frameBarras2->tableLinhas->setColumnHidden(i, true);
        }
    }

    indiceOrigensEscolhidas = SelecionadasOrigem;
    indiceDestinosEscolhidos = SelecionadasDestino;
    indexComboBoxOrigemEnvio = indexComboBoxOrigem;
    indexComboBoxDestinoEnvio = indexComboBoxDestino;
}
