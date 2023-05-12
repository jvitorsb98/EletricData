#ifndef BARRA_H
#define BARRA_H

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
    double tensaoPu;
    double tensaoNominalKv;
    double thdvPercent;
    double tensaoEficaz;
    std::map<int, std::pair<std::pair<double, double>, std::pair<int, bool>>> dti;
    int classeTensaoThdv;
    bool barraInfectadaThdv;


};

#endif // BARRA_H
