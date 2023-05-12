#include "filtrosbarra.h"
#include "ui_filtrosbarra.h"
#include "style.h"
#include "framebarras.h"

bool FiltrosBarra::tensaoPu = true;
bool FiltrosBarra::tensaoNominal = true;
bool FiltrosBarra::thdv = true;
bool FiltrosBarra::dit = true;
bool FiltrosBarra::ditPercent = true;
bool FiltrosBarra::tensaoEficaz = true;
int  FiltrosBarra::indexComboBox = 0;
Ui::FrameBarras *frameBarras;

QStringList FiltrosBarra::indiceBarrasEscolhidas;

FiltrosBarra::FiltrosBarra(QWidget *parent ,  Ui::FrameBarras *fb) :
    QDialog(parent),
    ui(new Ui::FiltrosBarra)
{
    ui->setupUi(this);
    setParent(parent);
    frameBarras = fb;

    inicializandoFrame();


}

FiltrosBarra::~FiltrosBarra()
{
    delete ui;
}

void FiltrosBarra::inicializandoFrame(){
    inserindoQssFiltrosBarra();
}
void FiltrosBarra::inserindoQssFiltrosBarra(){
    inserindoQssCheckBox();
    inserindoQssLineEdit();
    inserindoQssBtnAplicar();
    inserindoQssComboBox();
    inserindoQssGroupBox();
    inserindoQssJanela();
}
void FiltrosBarra::inserindoQssJanela(){

    setWindowTitle("Filtros");
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));

}
void FiltrosBarra::inserindoQssBtnAplicar(){
    Style style;
    ui->btnAplicar->setStyleSheet(style.cssBtn);
}
void FiltrosBarra::inserindoQssComboBox(){
    Style style;
    ui->comboBoxFBarra->setCurrentIndex(indexComboBox);
    ui->comboBoxFBarra->setStyleSheet(style.cssComboBox);

}
void FiltrosBarra::inserindoQssLineEdit(){
    Style style;
    ui->lineEditFBarra->setPlaceholderText("1-"+QString::number(FrameTensoes::numeroDeBarras));
    ui->lineEditFBarra->setStyleSheet(style.cssLineEdit);
}
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
void FiltrosBarra::inserindoQssGroupBox(){
    Style style;
    ui->groupBoxBarras->setStyleSheet(style.cssGroupBox);
    ui->groupBoxAtributos->setStyleSheet(style.cssGroupBox);
}
void FiltrosBarra::on_comboBoxFBarra_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lineEditFBarra->setPlaceholderText("1-5");
        ui->lineEditFBarra->setEnabled(true);
    }else if (index==1){
        ui->lineEditFBarra->setPlaceholderText("1,2,3,4,5");
        ui->lineEditFBarra->setEnabled(true);
    }else{
        ui->lineEditFBarra->setPlaceholderText("Todas as Barras Poluidoras");
        ui->lineEditFBarra->setEnabled(false);
    }

    indexComboBox = index;
}
void FiltrosBarra::on_btnAplicar_clicked()
{
    //atualiza as variaveis estáticas
    tensaoPu = ui->checkBoxTensaoBarra->isChecked();
    tensaoNominal = ui->checkBoxTensaoNominal->isChecked();
    thdv = ui->checkBoxThdv->isChecked();
    dit = ui->checkBoxDit->isChecked();
    ditPercent = ui->checkBoxDitPercent->isChecked();
    tensaoEficaz = ui->checkBoxTensaoEficaz->isChecked();


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
    if(indexComboBox==1){
        QStringList indices = ui->lineEditFBarra->text().split(",");
        QList<bool> barrasEscolhidas(FrameTensoes::numeroDeBarras, false);

        for (auto it = indices.begin(); it != indices.end(); it++) {
            int index = it->toInt() - 1;
            if (index >= 0 && index < FrameTensoes::numeroDeBarras) {
                barrasEscolhidas[index] = true;
            }
        }

        for (int i = 0;  i < FrameTensoes::numeroDeBarras; i++) {
            if(!barrasEscolhidas[i]){
                frameBarras->tableBarras->setColumnHidden(i,true);
            }else{
                frameBarras->tableBarras->setColumnHidden(i,false);
            }
        }
        indiceBarrasEscolhidas = indices;

    }
    else if(indexComboBox ==0){
        QStringList  indices = ui->lineEditFBarra->text().split("-");
        int inicio = indices.at(0).toInt()-1;
        int fim = indices.at(1).toInt()-1;
        for( int i = 0 ; i < FrameTensoes::numeroDeBarras ; i++){
            if(i >= inicio && i <= fim){
                frameBarras->tableBarras->setColumnHidden(i,false);
            }else{
                frameBarras->tableBarras->setColumnHidden(i,true);
            }
        }
        indiceBarrasEscolhidas = indices;

    }else{
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

    close();

}

