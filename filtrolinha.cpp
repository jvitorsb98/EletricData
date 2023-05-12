#include "filtrolinha.h"
#include "ui_filtrolinha.h"
#include "style.h"
#include "framebarras.h"

bool FiltroLinha::correntePu = true;
bool FiltroLinha::dht = true;
bool FiltroLinha::dit = true;
bool FiltroLinha::ditPercent = true;
bool FiltroLinha::correnteEficaz = true;
bool FiltroLinha::resistencia = true;
bool FiltroLinha::perdas = true;
bool FiltroLinha::perdasEficaz = true;
int  FiltroLinha::indexComboBoxOrigem = 0;
int FiltroLinha::indexComboBoxDestino = 0;
int quantidadeDeLinhas;
Ui::FrameBarras *frameBarras2;


FiltroLinha::FiltroLinha(QWidget *parent,  Ui::FrameBarras *fb, int numeroDeLinhas, int harmMax) :
    QDialog(parent),
    ui(new Ui::FiltroLinha)
{
    ui->setupUi(this);
    Style style;
    setParent(parent);
    quantidadeDeLinhas = numeroDeLinhas;
    frameBarras2 = fb;
    FrameBarras::indiceHarmMax = harmMax;
    ui->comboBoxOrigem->setCurrentIndex(indexComboBoxOrigem);
    ui->comboBoxDestino->setCurrentIndex(indexComboBoxDestino);


    ui->checkBoxCorrente->setChecked(correntePu);
    ui->checkBoxDht->setChecked(dht);
    ui->checkboxDit->setChecked(dit);
    ui->checkBoxDitPercent->setChecked(ditPercent);
    ui->checkBoxCorrenteEficaz->setChecked(correnteEficaz);
    ui->checkBoxResistencia->setChecked(resistencia);
    ui->checkBoxPerdas->setChecked(perdas);
    ui->checkBoxPerdasEficaz->setChecked(perdasEficaz);
    ui->lineEditFLinha->setPlaceholderText("Todas");
    ui->lineEditFLinha2->setPlaceholderText("Todas");


    ui->lineEditFLinha->setStyleSheet(style.cssLineEdit);
    ui->lineEditFLinha2->setStyleSheet(style.cssLineEdit);
    ui->btnAplicar->setStyleSheet(style.cssBtn);
    ui->groupBoxAtributos->setStyleSheet(style.cssGroupBox);
    ui->groupBoxLinhas->setStyleSheet(style.cssGroupBox);

    ui->checkBoxCorrente->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDht->setStyleSheet(style.cssCheckbox);
    ui->checkboxDit->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDitPercent->setStyleSheet(style.cssCheckbox);
    ui->checkBoxCorrenteEficaz->setStyleSheet(style.cssCheckbox);
    ui->checkBoxResistencia->setStyleSheet(style.cssCheckbox);
    ui->checkBoxPerdas->setStyleSheet(style.cssCheckbox);
    ui->checkBoxPerdasEficaz->setStyleSheet(style.cssCheckbox);


    ui->lineEditFLinha->setEnabled(false);
    ui->lineEditFLinha2->setEnabled(false);

    setWindowTitle("Filtros");
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));
}


FiltroLinha::~FiltroLinha()
{
    delete ui;
}

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


void FiltroLinha::on_btnAplicar_clicked()
{

    correntePu = ui->checkBoxCorrente->isChecked();
    dht = ui->checkBoxDht->isChecked();
    dit = ui->checkboxDit->isChecked();
    ditPercent = ui->checkBoxDitPercent->isChecked();
    correnteEficaz = ui->checkBoxCorrenteEficaz->isChecked();
    resistencia = ui->checkBoxResistencia->isChecked();
    perdas = ui->checkBoxPerdas->isChecked();
    perdasEficaz = ui->checkBoxPerdasEficaz->isChecked();

    //filtra as linhas da tabela

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

    //filtra as colunas da tabela
    if(indexComboBoxOrigem==0 && indexComboBoxDestino==0){
        for(int i = 0 ; i < quantidadeDeLinhas ; i++){
            frameBarras2->tableLinhas->setColumnHidden(i,false);
        }
    }else if(indexComboBoxOrigem==0 && indexComboBoxDestino==1){
        for(int i = 0 ; i < quantidadeDeLinhas ; i++){
            frameBarras2->tableLinhas->setColumnHidden(i,false);
        }
        for( int i = 0 ; i < quantidadeDeLinhas ; i++){
            int barraDeDestino = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(1).toInt();
            QStringList Selecionadas = ui->lineEditFLinha2->text().split(",");
            for( int j = 0 ; j < Selecionadas.size() ; j++){
                if(Selecionadas.at(j).toInt() == barraDeDestino){
                    break;
                }else{
                    if(j == Selecionadas.size()-1){
                        frameBarras2->tableLinhas->setColumnHidden(i,true);
                    }
                }
            }
        }
    }else if(indexComboBoxOrigem==1 && indexComboBoxDestino==0){
        for(int i = 0 ; i < quantidadeDeLinhas ; i++){
            frameBarras2->tableLinhas->setColumnHidden(i,false);
        }
        for( int i = 0 ; i < quantidadeDeLinhas ; i++){
            int barraDeOrigem = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(0).toInt();
            QStringList Selecionadas = ui->lineEditFLinha->text().split(",");
            for( int j = 0 ; j < Selecionadas.size() ; j++){
                if(Selecionadas.at(j).toInt() == barraDeOrigem){
                    break;
                }else{
                    if(j == Selecionadas.size()-1){
                        frameBarras2->tableLinhas->setColumnHidden(i,true);
                    }
                }
            }
        }
    }else{
        for(int i = 0 ; i < quantidadeDeLinhas ; i++){
            frameBarras2->tableLinhas->setColumnHidden(i,false);
        }
        for( int i = 0 ; i < quantidadeDeLinhas ; i++){
            int barraDeDestino = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(1).toInt();
            int barraDeOrigem = frameBarras2->tableLinhas->horizontalHeaderItem(i)->text().split("->").at(0).toInt();
            QStringList SelecionadasOrigem = ui->lineEditFLinha->text().split(",");
            QStringList SelecionadasDestino = ui->lineEditFLinha2->text().split(",");
            for( int j = 0 ; j < SelecionadasOrigem.size() ; j++){
                if(SelecionadasOrigem.at(j).toInt() == barraDeOrigem){
                    break;
                }else{
                    if(j == SelecionadasOrigem.size()-1){
                        frameBarras2->tableLinhas->setColumnHidden(i,true);
                    }
                }
            }
            for( int j = 0 ; j < SelecionadasDestino.size() ; j++){
                if(SelecionadasDestino.at(j).toInt() == barraDeDestino){
                    break;
                }else{
                    if(j == SelecionadasDestino.size()-1){
                        frameBarras2->tableLinhas->setColumnHidden(i,true);
                    }
                }
            }
        }
    }

    close();

}

