#ifndef FILTROSBARRA_H
#define FILTROSBARRA_H

#include <QDialog>
#include "ui_filtrosbarra.h"
#include "ui_framebarras.h"
#include "mainwindow.h"

namespace Ui {
class FiltrosBarra;
}

class FiltrosBarra : public QDialog
{
    Q_OBJECT

public:
    explicit FiltrosBarra(QWidget *parent = nullptr , Ui::FrameBarras *fb=nullptr);
    ~FiltrosBarra();
    Ui::FiltrosBarra* getUi(){
        return ui;
    }
    static bool tensaoPu;
    static bool tensaoNominal;
    static bool thdv;
    static bool dit;
    static bool ditPercent;
    static bool tensaoEficaz;
    static int indexComboBox;
    static QStringList indiceBarrasEscolhidas;
    void inserindoQssFiltrosBarra();
    void inserindoQssCheckBox();
    void inserindoQssLineEdit();
    void inserindoQssBtnAplicar();
    void inserindoQssComboBox();
    void inserindoQssGroupBox();
    void inserindoQssJanela();
    void inicializandoFrame();

    void atualizaVariaveis();
    void filtrarLinhasTabela();
    void filtrarColunasTabela();
    void filtrarColunasPorIndices();
    void filtrarColunasPorFaixa();
    void filtrarColunasPorMarcadores();

private slots:
    void on_comboBoxFBarra_currentIndexChanged(int index);

    void on_btnAplicar_clicked();

private:
    Ui::FiltrosBarra *ui;
};

#endif // FILTROSBARRA_H
