
#ifndef LINHA_H
#define LINHA_H
#include<utility>
#include<QObject>
#endif // LINHA_H

class Linha{
public:
    int getOrigem() {
        return origem;
    }

    void setOrigem(int origem) {
        this->origem = origem;
    }

    int getDestino() {
        return destino;
    }

    void setDestino(int destino) {
        this->destino = destino;
    }

    double getCorrente() {
        return corrente;
    }

    void setCorrente(double corrente) {
        this->corrente = corrente;
    }

    double getDhtPercent() {
        return dhtPercent;
    }

    void setDhtPercent(double dhtPercent) {
        this->dhtPercent = dhtPercent;
    }

    double getResistencia() {
        return resistencia;
    }

    void setResistencia(double resistencia) {
        this->resistencia = resistencia;
    }

    double getPerdas() {
        return perdas;
    }

    void setPerdas(double perdas) {
        this->perdas = perdas;
    }

    double getCorrenteEficaz() {
        return correnteEficaz;
    }

    void setCorrenteEficaz(double correnteEficaz) {
        this->correnteEficaz = correnteEficaz;
    }

    double getPerdasEficaz() {
        return perdasEficaz;
    }

    void setPerdasEficaz(double perdasEficaz) {
        this->perdasEficaz = perdasEficaz;
    }

    bool getLinhaInfectadaDht() {
        return linhaInfectadaDht;
    }

    void setLinhaInfectadaDht(bool infectada) {
        linhaInfectadaDht = infectada;
    }

    std::map<int, std::pair<double, double>> getDti(){
        return dti;
    }

    void setDti(int key1, double dAbsolut ,  double dPercent) {
        this->dti.insert({key1,{dAbsolut,dPercent}});
    }

private:
    int origem;
    int destino;
    double corrente;
    double dhtPercent;
    double resistencia;
    double perdas;
    double correnteEficaz;
    double perdasEficaz;
    bool linhaInfectadaDht;
    std::map<int, std::pair<double, double>> dti;

};
