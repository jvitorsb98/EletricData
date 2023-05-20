/**
 * @class FiltrosBarra
 * @brief Janela responsável pela inserção dos filtros do TableBarras do FrameBarras
 * @author João Vitor N. Ramos
*/

#include "filtrosbarra.h"
#include "ui_filtrosbarra.h"
#include "frametensoes.h"
#include "style.h"
#include "framebarras.h"
#include <QMessageBox>

/**
 * @variable bool FiltrosBarra::tensaoPu
 * @brief Variável estática que identifica se o checkBox da tensão na Barra pu dos filtros da barra está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltrosBarra::tensaoPu = true;

/**
 * @variable bool FiltrosBarra::tensaoNominal
 * @brief Variável estática que identifica se o checkBox da tensão nominal dos filtros da barra está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltrosBarra::tensaoNominal = true;

/**
 * @variable bool FiltrosBarra::thdv
 * @brief Variável estática que identifica se o checkBox do thdv dos filtros da barra está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltrosBarra::thdv = true;

/**
 * @variable bool FiltrosBarra::dit
 * @brief Variável estática que identifica se o checkBox do dit dos filtros da barra está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltrosBarra::dit = true;

/**
 * @variable bool FiltrosBarra::ditPercent
 * @brief Variável estática que identifica se o checkBox do dit[%] dos filtros da barra está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltrosBarra::ditPercent = true;

/**
 * @variable bool FiltrosBarra::tensaoEficaz
 * @brief Variável estática que identifica se o checkBox da tensão eficaz dos filtros da barra está selecionado
 *  Seu valor inicial é true, para caso o usúario nao filtrar nada, os dados sejam mostrados.
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
bool FiltrosBarra::tensaoEficaz = true;

/**
 * @variable bool FiltrosBarra::indexComboBox
 * @brief Variável estática que identifica qual tipo de filtragem das barras está selecionada
 *  Seu valor inicial é 0. 0 significa que o metodo de filtragem é para intervalo de numero de barras , 1 para escolha das barras de forma individual e 2 para escolher só as poluidoras
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int  FiltrosBarra::indexComboBox = 0;

/**
 * @variable bool FiltrosBarra::indexComboBoxEnvio
 * @brief Variável estática que identifica qual tipo de filtragem das barras foi a ultima a ser selecionada e concluida
 *  Seu valor inicial é 0. 0 significa que o metodo de filtragem é para intervalo de numero de barras , 1 para escolha das barras de forma individual e 2 para escolher só as poluidoras
 *   Sua classificação de armazenamento foi definida como static pela necessidade dessa variável ser acessada e seu valor modificado ao longo de outros frames.
 */
int  FiltrosBarra::indexComboBoxEnvio = 0;

/**
 * @variable Ui::FrameBarras *frameBarras
 * @brief Variavel que permite acessar o 'Ui' do FrameBarras. Foi declarada como várival global para ser utilizada em qualquer parte da classe.
 */
Ui::FrameBarras *frameBarras;

/**
 * @variable
 * @brief Variável estática responsável por armazenar o indice das barras escolhidas em um QStringList.
 * Caso seja escolhido o metodo de intervalo serão 2 valores separados por traço e caso sejam as individuais, separados por virgula.
 */
QStringList FiltrosBarra::indiceBarrasEscolhidas ;


/**
 * @name FiltrosBarra::FiltrosBarra
 * @brief Construtor da classe FiltrosBarra
 * @param parent (Parâmetro do tipo QWidget que indica a interface pai da classe atual)
 * @param fb (Parãmetro do tipo Ui::FrameBarras para permitir acesso aos componentes da interface do frame FrameBarras)
 */
FiltrosBarra::FiltrosBarra(QWidget *parent ,  Ui::FrameBarras *fb) :
    QDialog(parent),
    ui(new Ui::FiltrosBarra)
{
    ui->setupUi(this);
    setParent(parent);
    frameBarras = fb;

    inicializandoFrame();

}

/**
 * @name FiltrosBarra::~FiltrosBarra
 * @brief Destrutor da classe FiltrosBarra
 */
FiltrosBarra::~FiltrosBarra()
{
    delete ui;
}

/**
 * @name FiltrosBarra::inicializaFrame
 * @brief Primeiro método a ser chamada no construtor, responsável por chamar os métodos subsequêntes que modelam a Interface do frame.
 * @return void
 */
void FiltrosBarra::inicializandoFrame(){
    inserindoQssFiltrosBarra();
}

/**
 * @name FiltrosBarra::inserindoQssFiltrosBarra
 * @brief Método responsável por chamar métodos que inserem Qss nos componentes do frame
 * @return void
 */
void FiltrosBarra::inserindoQssFiltrosBarra(){
    inserindoQssCheckBox();
    inserindoQssLineEdit();
    inserindoQssBtnAplicar();
    inserindoQssComboBox();
    inserindoQssGroupBox();
    inserindoQssJanela();
}

/**
 * @name FiltrosBarra::inserindoQssCheckBox
 * @brief Método responsável por inserir Qss nos Checkbox's do frame
 * @return void
 */
void FiltrosBarra::inserindoQssCheckBox(){
    Style style;
    ui->checkBoxTensaoBarra->setChecked(tensaoPu);
    ui->checkBoxTensaoNominal->setChecked(tensaoNominal);
    ui->checkBoxThdv->setChecked(thdv);
    ui->checkBoxDit->setChecked(dit);
    ui->checkBoxDitPercent->setChecked(ditPercent);
    ui->checkBoxTensaoEficaz->setChecked(tensaoEficaz);

    ui->checkBoxTensaoBarra->setStyleSheet(style.cssCheckbox);
    ui->checkBoxTensaoNominal->setStyleSheet(style.cssCheckbox);
    ui->checkBoxThdv->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDit->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDitPercent->setStyleSheet(style.cssCheckbox);
    ui->checkBoxTensaoEficaz->setStyleSheet(style.cssCheckbox);
}

/**
 * @name FiltrosBarra::inserindoQssLineEdit
 * @brief Método responsável por inserir Qss no LineEdit
 * @return void
 */
void FiltrosBarra::inserindoQssLineEdit(){
    Style style;
    ui->lineEditFBarra->setStyleSheet(style.cssLineEdit);
    ui->lineEditFBarra->setPlaceholderText("1-"+QString::number(FrameTensoes::numeroDeBarras));

}

/**
 * @name FiltrosBarra::inserindoQssBtnAplicar
 * @brief Método responsável por inserir Qss no botão Aplicar
 * @return void
 */
void FiltrosBarra::inserindoQssBtnAplicar(){
    Style style;
    ui->btnAplicar->setStyleSheet(style.cssBtn);
}

/**
 * @name FiltrosBarra::inserindoQssComboBox
 * @brief Método responsável por inserir Qss no ComboBox
 * @return void
 */
void FiltrosBarra::inserindoQssComboBox(){
    Style style;
    ui->comboBoxFBarra->setCurrentIndex(indexComboBox);
    ui->comboBoxFBarra->setStyleSheet(style.cssComboBox);
}

/**
 * @name FiltrosBarra::inserindoQssGroupBox
 * @brief Método responsável por inserir Qss nos GroupBox's
 * @return void
 */
void FiltrosBarra::inserindoQssGroupBox(){
    Style style;
    ui->groupBoxBarras->setStyleSheet(style.cssGroupBox);
    ui->groupBoxAtributos->setStyleSheet(style.cssGroupBox);
}

/**
 * @name FiltrosBarra::inserindoQssJanela
 * @brief Método responsável por inserir icon e title na janela
 * @return void
 */
void FiltrosBarra::inserindoQssJanela(){

    setWindowTitle("Filtros");
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));
}


/**
 * @name FiltrosBarra::on_comboBoxFBarra_currentIndexChanged
 * @brief Método responsável por trocar o place holder e controlar a possibilidade de alterar o valor que estará no LineEdit ao trocar o ComboBox
 * @param index
 * @return void
 */
void FiltrosBarra::on_comboBoxFBarra_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lineEditFBarra->clear();
        ui->lineEditFBarra->setPlaceholderText("1-5");
        ui->lineEditFBarra->setEnabled(true);
    }else if (index==1){
        ui->lineEditFBarra->clear();
        ui->lineEditFBarra->setPlaceholderText("1,2,3,4,5");
        ui->lineEditFBarra->setEnabled(true);
    }else{
        ui->lineEditFBarra->clear();
        ui->lineEditFBarra->setPlaceholderText("Todas as Barras Poluidoras");
        ui->lineEditFBarra->setEnabled(false);
    }

    indexComboBox = index;
}



/**
 * @name FiltrosBarra::on_btnAplicar_clicked
 * @brief Método responsável por implementar o evento do botão aplicar.
 * Atualiza as variaveis estáticas, filtras as linhas da tabela e seleciona quais barras serão mostradas na tabela
 * @return void
 */
void FiltrosBarra::on_btnAplicar_clicked()
{

    atualizaVariaveis();
    filtrarLinhasTabela();
    filtrarColunasTabela();
    close();

}

/**
 * @name FiltrosBarra::atualizaVariaveis
 * @brief Método responsável por atualizar variaveis estáticas
 * @return void
 */
void FiltrosBarra::atualizaVariaveis(){
    //atualiza as variaveis estáticas
    tensaoPu = ui->checkBoxTensaoBarra->isChecked();
    tensaoNominal = ui->checkBoxTensaoNominal->isChecked();
    thdv = ui->checkBoxThdv->isChecked();
    dit = ui->checkBoxDit->isChecked();
    ditPercent = ui->checkBoxDitPercent->isChecked();
    tensaoEficaz = ui->checkBoxTensaoEficaz->isChecked();
}

/**
 * @name FiltrosBarra::filtrarLinhasTabela
 * @brief Método responsável por filtrar as linhas da tabela Barras
 * @return void
 */
void FiltrosBarra::filtrarLinhasTabela(){
    //filtra as linhas da tabela

    if(!tensaoPu){
        frameBarras->tableBarras->setRowHidden(0,true);
    }else{
        frameBarras->tableBarras->setRowHidden(0,false);
    }
    if(!tensaoNominal){
        frameBarras->tableBarras->setRowHidden(1,true);
    }else{
        frameBarras->tableBarras->setRowHidden(1,false);
    }
    if(!thdv){
        frameBarras->tableBarras->setRowHidden(2,true);
    }else{
        frameBarras->tableBarras->setRowHidden(2,false);
    }
    int pos =3;
    for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
        if(!dit){
            frameBarras->tableBarras->setRowHidden(pos,true);
            pos++;
        }else{
            frameBarras->tableBarras->setRowHidden(pos,false);
            pos++;
        }
    }
    for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
        if(!ditPercent){
            frameBarras->tableBarras->setRowHidden(pos,true);
            pos++;
        }else{
            frameBarras->tableBarras->setRowHidden(pos,false);
            pos++;
        }
    }
    if(!tensaoEficaz){
        frameBarras->tableBarras->setRowHidden(pos,true);
    }else{
        frameBarras->tableBarras->setRowHidden(pos,false);
    }
}


/**
 * @name FiltrosBarra::filtrarColunasTabela
 * @brief Método responsável por chamar metodos que filtram as colunas à depender da escolha do usúario
 * @return void
 */
void FiltrosBarra::filtrarColunasTabela(){
    if (indexComboBox == 1) {
        filtrarColunasPorIndices();
    }
    else if (indexComboBox == 0) {
        filtrarColunasPorFaixa();
    }
    else{
        filtrarColunasPorMarcadores();
    }
}

/**
 * @name FiltrosBarra::filtrarColunasPorIndices
 * @brief Método responsável por filtrar as colunas da tabela barras por indices
 * @return void
 */
void FiltrosBarra::filtrarColunasPorIndices() {
    QString lineEditValue = ui->lineEditFBarra->text().trimmed();
    if (lineEditValue.isEmpty()) {
        QMessageBox::warning(this, "Erro", "O campo não pode ser vazio.");
        ui->lineEditFBarra->clear();
        indexComboBox = 0;
        return;
    }

    try {
        QStringList indices = lineEditValue.split(",");
        QList<bool> barrasEscolhidas(FrameTensoes::numeroDeBarras, false);

        for (auto it = indices.begin(); it != indices.end(); it++) {
            int index = it->toInt();
            if (index < 1 || index > FrameTensoes::numeroDeBarras) {
                throw std::runtime_error("Valores inválidos. Os números devem ser maiores ou iguais a 1 e menores ou iguais a " + QString::number(FrameTensoes::numeroDeBarras).toStdString() + ".");
            }
            barrasEscolhidas[index - 1] = true;
        }

        for (int i = 0; i < FrameTensoes::numeroDeBarras; i++) {
            frameBarras->tableBarras->setColumnHidden(i, !barrasEscolhidas[i]);
        }

        indiceBarrasEscolhidas = indices;
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Erro", e.what());
        ui->lineEditFBarra->clear();
        indexComboBox = 0;
        return;
    }

    indexComboBoxEnvio = indexComboBox;

}

/**
 * @name FiltrosBarra::filtrarColunasPorFaixa
 * @brief Método responsável por filtrar as colunas da tabela barras por faixa
 * @return void
 */
void FiltrosBarra::filtrarColunasPorFaixa(){
    QStringList indices;
    QString lineEditValue = ui->lineEditFBarra->text().trimmed();

    if (lineEditValue.isEmpty()) {
        indices.append(QString::number(1));
        indices.append(QString::number(FrameTensoes::numeroDeBarras));
    } else {
        try {
            QStringList values = lineEditValue.split("-");
            if (values.size() != 2) {
                throw std::runtime_error("Formato inválido. Digite dois números separados por um traço.");
            }

            int inicio = values.at(0).toInt();
            int fim = values.at(1).toInt();

            if (inicio < 1 || fim > FrameTensoes::numeroDeBarras || inicio >= fim) {
                throw std::runtime_error("Valores inválidos. O primeiro número deve ser maior ou igual a 1, o segundo número deve ser menor ou igual a " + QString::number(FrameTensoes::numeroDeBarras).toStdString() + ", e o primeiro número deve ser menor que o segundo número.");
            }

            indices.append(QString::number(inicio));
            indices.append(QString::number(fim));
        } catch (const std::exception& e) {
            QMessageBox::warning(this, "Erro", e.what());
            return;
        }
    }

    for (int i = 0; i < FrameTensoes::numeroDeBarras; i++) {
        if (i >= indices.at(0).toInt() - 1 && i <= indices.at(1).toInt() - 1) {
            frameBarras->tableBarras->setColumnHidden(i, false);
        } else {
            frameBarras->tableBarras->setColumnHidden(i, true);
        }
    }

    indiceBarrasEscolhidas = indices;
    indexComboBoxEnvio = indexComboBox;

}

/**
 * @name FiltrosBarra::filtrarColunasPorMarcadores
 * @brief Método responsável por filtrar as colunas da tabela barras por marcadores (apenas as poluidoras)
 * @return void
 */
void FiltrosBarra::filtrarColunasPorMarcadores(){
    for(int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
        if(frameBarras->tableBarras->item(2,i)->background() == QColor(255, 128, 128) ){
            frameBarras->tableBarras->setColumnHidden(i,false);
        }else{
            int pos =3;
            for(int j = 3 ; j <= FrameBarras::indiceHarmMax ; j+=2){
                if(frameBarras->tableBarras->item(pos,i)->background() == QColor(255, 128, 128) ){
                    frameBarras->tableBarras->setColumnHidden(i,false);
                    break;
                }else{
                    frameBarras->tableBarras->setColumnHidden(i,true);
                }
                pos++;
            }
        }
    }
}
