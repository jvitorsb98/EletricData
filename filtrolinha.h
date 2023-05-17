#ifndef FILTROLINHA_H
#define FILTROLINHA_H

#include <QDialog>
#include "ui_filtrolinha.h"
#include "ui_framebarras.h"
#include "mainwindow.h"
namespace Ui {
class FiltroLinha;
}

class FiltroLinha : public QDialog
{
    Q_OBJECT

public:
    explicit FiltroLinha(QWidget *parent = nullptr, Ui::FrameBarras *fb=nullptr);
    ~FiltroLinha();
    static bool correntePu;
    static bool dht;
    static bool dit;
    static bool ditPercent;
    static bool correnteEficaz;
    static bool resistencia;
    static bool perdas;
    static bool perdasEficaz;
    static int indexComboBoxOrigem;
    static int indexComboBoxDestino;
    static int indexComboBoxOrigemEnvio;
    static int indexComboBoxDestinoEnvio;

    void inserindoQssFiltrosLinha();
    void inserindoQssCheckBox();
    void inserindoQssLineEdit();
    void inserindoQssBtnAplicar();
    void inserindoQssComboBox();
    void inserindoQssGroupBox();
    void inserindoQssJanela();
    void inicializandoFrame();
    static QStringList indiceOrigensEscolhidas;
    static QStringList indiceDestinosEscolhidos;

    void atualizaVariaveis();
    void filtrarLinhasTabela();
    void filtrarColunasTabela();
    void filtrarColTod1Tod2();
    void filtrarColTod1Ind2();
    void filtrarColInd1Tod2();
    void filtrarColInd1Ind2();



private slots:

    void on_comboBoxOrigem_currentIndexChanged(int index);

    void on_comboBoxDestino_currentIndexChanged(int index);

    void on_btnAplicar_clicked();

private:
    Ui::FiltroLinha *ui;
};

#endif // FILTROLINHA_H
