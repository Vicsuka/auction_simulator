#include <string>
#include <iostream>
#include <cstdlib>

#ifndef EMBER_H
#define EMBER_H


class Ember {
    std::string nev;
public:
    Ember(std::string n): nev(n){}
    virtual void adatok(){std::cout <<"Nev: "<< nev <<std::endl;}
    std::string getNev() {return nev;}
    void writeNev(){std::cout << nev;}
    virtual ~Ember(){}
    virtual int getEgyenleg(){}
    virtual int getKp(){}
    virtual double getRisk(){}
    virtual double getGreed(){return 1+(rand()%50)*0.01;}
    virtual void setDb(int d){}
    virtual int vasarol(int t,int ar){}
    virtual void setEgyenlegminusz(int n){}
    virtual void setKpplussz(int n){}
    virtual std::string getSzerep() const{}
};



//--------------------------------------------------------------------------
class Vevo: public Ember {
    static const std::string szerep;
    int egyenleg;
    double riskfakt;
public:
    Vevo(std::string n,int e,double f): Ember(n),egyenleg(e),riskfakt(f){}
    int getEgyenleg(){return egyenleg;}
    double getRisk(){return riskfakt;}
    void adatok();
    void setEgyenlegminusz(int n){egyenleg = egyenleg-n;}
    int vasarol(int t,int ar);
    ~Vevo(){}
    std::string getSzerep() const{return szerep;}
};



//--------------------------------------------------------------------------
class Elado: public Ember {
    static const std::string szerep;
    int kp;
    int birtokoltdb;
    double greed;
public:
    Elado(std::string n,int m,double g): Ember(n),kp(m),greed(g){birtokoltdb= 0;}
    int getKp() {return kp;}
    void setKp(int k) {kp=k;}
    void setKpplussz(int n) {kp=kp+n;}
    int getBirtokoltdb(){return birtokoltdb;}
    double getGreed(){return greed;}
    void adatok();
    void setDb(int d){birtokoltdb=d;}
    int vasarol(int t,int ar){return 0;}
    ~Elado(){}
    std::string getSzerep() const{return szerep;}
};
#endif
