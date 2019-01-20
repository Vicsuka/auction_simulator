#include <string>
#include <iostream>

#ifndef TARGY_H
#define TARGY_H

#include "ember.h"

class Targy {
    std::string nev;
    int ertek;
    Ember* tulaj;
public:
    Targy(std::string n,int e,Ember* t):nev(n),ertek(e),tulaj(t){}
    virtual void elad(int ar){}
    virtual void kiir(){
        std::cout << std::endl;
        std::cout << "Targy neve: "<< nev << "\nErteke: "<< ertek << "\nGazdaja: ";
        if (tulaj!=NULL)
            tulaj->writeNev();
        else std::cout << "NINCS TULAJDONOS\n";
        std::cout << std::endl << "Egyeb tulajdonsagok: " << std::endl;
    }
    void setTulaj(Ember* e);
    Ember* getTulaj() {return tulaj;}
    void setErtek(int e){ertek = e;}
    int getErtek(){return ertek;}
    void getNev(){std::cout << nev;}
    virtual ~Targy(){}
    virtual std::string getTipus() const{}
};



class Kep:public Targy{
    static const std::string tipus;
    std::string festo;
    int evszam;
public:
    Kep(std::string n,int e,Ember* t,std::string f,int ev):Targy(n,e,t),festo(f),evszam(ev) {}
    int getEvszam(){return evszam;}
    void kiir();
    void elad(int ar){};
    virtual std::string getTipus() const{return tipus;}
};

class Bor:public Targy{
    static const std::string tipus;
    int evjarat;
public:
    Bor(std::string n,int e,Ember *t,int ev):Targy(n,e,t),evjarat(ev) {}
    int getEvjarat(){return evjarat;}
    void kiir();
    virtual std::string getTipus() const{return tipus;}
};


class Ekszer:public Targy{
    static const std::string tipus;
    std::string anyag;
    double szorzo;
public:
    Ekszer(std::string n,int e,Ember*t,std::string m):Targy(n,e,t),anyag(m){
        if (m=="arany")szorzo = 1.5;
        if (m=="ezust")szorzo = 1.25;
        if (m=="bronz")szorzo = 1.1;
        if (m!="bronz" && m!="ezust" && m!="arany" ) szorzo=1;
        setErtek(szorzo*getErtek());
        }
    void kiir();
    virtual std::string getTipus() const{return tipus;}
};
#endif
