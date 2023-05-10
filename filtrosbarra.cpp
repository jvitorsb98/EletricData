#include "filtrosbarra.h"
#include "ui_filtrosbarra.h"
#include "style.h"

bool FiltrosBarra::tensaoPu = true;
bool FiltrosBarra::tensaoNominal = true;
bool FiltrosBarra::thdv = true;
bool FiltrosBarra::dit = true;
bool FiltrosBarra::ditPercent = true;
bool FiltrosBarra::tensaoEficaz = true;
int  FiltrosBarra::indexComboBox = 0;
Ui::FrameBarras *frameBarras;
int harmMax;
int quantidadeDeBarras;


FiltrosBarra::FiltrosBarra(QWidget *parent ,  Ui::FrameBarras *fb,int indiceharmonicoMax , int numeroDeBarras) :
    QDialog(parent),
    ui(new Ui::FiltrosBarra)
{
    ui->setupUi(this);
    Style style;
    setParent(parent);

    frameBarras = fb;
    harmMax = indiceharmonicoMax;
    quantidadeDeBarras = numeroDeBarras;


    ui->checkBoxTensaoBarra->setChecked(tensaoPu);
    ui->checkBoxTensaoNominal->setChecked(tensaoNominal);
    ui->checkBoxThdv->setChecked(thdv);
    ui->checkBoxDit->setChecked(dit);
    ui->checkBoxDitPercent->setChecked(ditPercent);
    ui->checkBoxTensaoEficaz->setChecked(tensaoEficaz);
    ui->lineEditFBarra->setPlaceholderText("1-5");
    ui->comboBoxFBarra->setCurrentIndex(0);

    ui->lineEditFBarra->setStyleSheet(style.cssLineEdit);
    ui->btnAplicar->setStyleSheet(style.cssBtn);


    ui->checkBoxTensaoBarra->setStyleSheet(style.cssCheckbox);
    ui->checkBoxTensaoNominal->setStyleSheet(style.cssCheckbox);
    ui->checkBoxThdv->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDit->setStyleSheet(style.cssCheckbox);
    ui->checkBoxDitPercent->setStyleSheet(style.cssCheckbox);
    ui->checkBoxTensaoEficaz->setStyleSheet(style.cssCheckbox);
    ui->comboBoxFBarra->setStyleSheet(style.cssComboBox);
    ui->groupBoxBarras->setStyleSheet(style.cssGroupBox);
    ui->groupBoxAtributos->setStyleSheet(style.cssGroupBox);
    setWindowTitle("Filtros");
    setWindowIcon(QIcon(":/icons/imgs/icons/engrenagem.png"));


}

FiltrosBarra::~FiltrosBarra()
{
    delete ui;
}




void FiltrosBarra::on_comboBoxFBarra_currentIndexChanged(int index)
{
    if(index == 0){
        ui->lineEditFBarra->setPlaceholderText("1-5");
    }else{
        ui->lineEditFBarra->setPlaceholderText("1,2,3,4,5");
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
    for(int j = 3 ; j <= harmMax ; j+=2){
        if(!dit){
            frameBarras->tableBarras->setRowHidden(pos,true);
            pos++;
        }else{
            frameBarras->tableBarras->setRowHidden(pos,false);
            pos++;
        }
    }
    for(int j = 3 ; j <= harmMax ; j+=2){
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
        QList<bool> barrasEscolhidas(quantidadeDeBarras, false);

        for (auto it = indices.begin(); it != indices.end(); it++) {
            int index = it->toInt() - 1;
            if (index >= 0 && index < quantidadeDeBarras) {
                barrasEscolhidas[index] = true;
            }
        }

        for (int i = 0;  i < quantidadeDeBarras; i++) {
            if(!barrasEscolhidas[i]){
                frameBarras->tableBarras->setColumnHidden(i,true);
            }else{
                frameBarras->tableBarras->setColumnHidden(i,false);
            }
        }
    }
    else{
        QStringList  indices = ui->lineEditFBarra->text().split("-");
        int inicio = indices.at(0).toInt()-1;
        int fim = indices.at(1).toInt()-1;
        for( int i = 0 ; i < quantidadeDeBarras ; i++){
            if(i >= inicio && i <= fim){
                frameBarras->tableBarras->setColumnHidden(i,false);
            }else{
                frameBarras->tableBarras->setColumnHidden(i,true);
            }
        }
    }

    close();

}

