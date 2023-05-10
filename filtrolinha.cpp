#include "filtrolinha.h"
#include "ui_filtrolinha.h"
#include "style.h"

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


FiltroLinha::FiltroLinha(QWidget *parent,  Ui::FrameBarras *fb) :
    QDialog(parent),
    ui(new Ui::FiltroLinha)
{
    ui->setupUi(this);
    Style style;
    setParent(parent);

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

}

