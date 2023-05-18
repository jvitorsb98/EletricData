#ifndef BARRA_H
#define BARRA_H

/**
 * @class Barra
 * @brief Classe responsável por armazenar os dados das barras
 * @author João Vitor N. Ramos
*/

#include <QObject>
#include <utility>

class Barra {
public:
    double getTensaoPu()  {
        return tensaoPu;
    }

    void setTensaoPu(double value) {
        tensaoPu = value;
    }

    double getTensaoNominalKv()  {
        return tensaoNominalKv;
    }

    void setTensaoNominalKv(double value) {
        tensaoNominalKv = value;
    }

    double getThdvPercent()  {
        return thdvPercent;
    }

    void setThdvPercent(double value) {
        thdvPercent = value;
    }

    std::map<int, std::pair<std::pair<double, double>, std::pair<int, bool>>> getDti(){
        return dti;
    }

    void somatorioHarmonico(int key1, double dAbsolut ,  double dPercent,int classeTensaoThdi ,bool poluida ) {
        this->dti.insert({key1,{{dAbsolut,dPercent},{classeTensaoThdi,poluida}}});
    }

    double getTensaoEficaz() {
        return tensaoEficaz;
    }

    void setTensaoEficaz(double value) {
        tensaoEficaz = value;
    }

    int getClasseTensaoThdv(){
        return classeTensaoThdv;
    }

    void setClasseTensaoThdv(int value){
        classeTensaoThdv= value;
    }

    bool getBarraInfectadaThdv(){
        return barraInfectadaThdv;
    }

    void setbarraInfectadaThdv(bool value){
        barraInfectadaThdv = value;
    }



private:
    /**
     * @variable double tensaoPu
     * @brief Variavel privada responsável por armazenar a tensão em uma barra, em pu
     */
    double tensaoPu;
    /**
     * @variable double tensaoNominalKv
     * @brief Variavel privada responsável por armazenar a tensão Nominal de uma barra, em kV
     */
    double tensaoNominalKv;
    /**
     * @variable double thdvPercent
     * @brief Variavel privada responsável por armazenar a distorção harmônica total de tensão uma barra, em %
     */
    double thdvPercent;
    /**
     * @variable double tensaoEficaz
     * @brief Variavel privada responsável por armazenar a tensão eficaz em uma barra, em pu
     */
    double tensaoEficaz;
    /**
     * @variable std::map<int, std::pair<std::pair<double, double>, std::pair<int, bool>>> dti
     * @brief  Váriavel responsável por armazenar os indices de distorção harmônica individuais.
     * std::map<indice da harmônica, std::pair<std::pair<valor absoluto, valor em porcentagem>, std::pair<classe de nível de tensão, se o valor da distorção está acima do limite>>>
     * Na Classe FrameBarras há os limites para nada classe de nível de tensão
     */
    std::map<int, std::pair<std::pair<double, double>, std::pair<int, bool>>> dti;
    /**
     * @variable int classeTensaoThdv
     * @brief Variavel privada responsável por armazenar a classe do nível de tensão
     */
    int classeTensaoThdv;
    /**
     * @variable bool barraInfectadaThdv
     * @brief Variavel privada responsável por armazenar a informação se a thdv está acima do limite permitido
     */
    bool barraInfectadaThdv;


};

#endif // BARRA_H
