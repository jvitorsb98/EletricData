
#ifndef LINHA_H
#define LINHA_H

/**
 * @class Linha
 * @brief Classe responsável por armazenar os dados das Linhas
 * @author João Vitor N. Ramos
*/

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
    /**
     * @variable int origem
     * @brief Variavel privada responsável por armazenar o numero da barra de origem da ligação
     */
    int origem;
    /**
     * @variable int destino
     * @brief Variavel privada responsável por armazenar o numero da barra de destino da ligação
     */
    int destino;
    /**
     * @variable double corrente
     * @brief Variavel privada responsável por armazenar o valor da corrente elétrica que percorre a linha, em pu
     */
    double corrente;
    /**
     * @variable double dhtPercent
     * @brief Variavel privada responsável por armazenar o valor da distorção harmônica total da linha, em %
     */
    double dhtPercent;
    /**
     * @variable double resistencia
     * @brief Variavel privada responsável por armazenar o valor da resistencia elétrica da linha, em ohm
     */
    double resistencia;
    /**
     * @variable double correnteEficaz
     * @brief Variavel privada responsável por armazenar o valor da corrente eficaz elétrica que percorre a linha, em pu
     */
    double correnteEficaz;
    /**
     * @variable double perdas
     * @brief Variavel privada responsável por armazenar o valor das perdas elétricas na linha, pu
     */
    double perdas;
    /**
     * @variable double perdasEficaz
     * @brief Variavel privada responsável por armazenar o valor das perdas elétricas eficaz na linha, pu
     */
    double perdasEficaz;
    /**
     * @variable bool linhaInfectadaDht
     * @brief Variavel privada responsável por armazenar se uma linhas está ultrapassando o valor de dht
     */
    bool linhaInfectadaDht;
    /**
     * @variable std::map<int, std::pair<double, double>> dti
     * @brief  Váriavel responsável por armazenar os indices de distorção harmônica individuais.
     * std::map<indice da harmônica, std::pair<std::pair<valor absoluto, valor em porcentagem>>
     */
    std::map<int, std::pair<double, double>> dti;

};
