#ifndef AUKCIOSHAZ_H
#define AUKCIOSHAZ_H

#include "ember.h"
#include "targy.h"
#include <string>
#include <iostream>
#include <stdexcept>


class Aukcioshaz {
    int embercapac;
    int emberdb;
    Ember**  resztvevok;
    int targydb;
    int targycapac;
    Targy**  targyak;
public:
    Aukcioshaz(int ec,int tc):resztvevok(new Ember*[ec]),targyak(new Targy*[tc]), emberdb(0),targydb(0),embercapac(ec),targycapac(tc){}
    void emberAdd(Ember* e);
    void targyAdd(Targy* t);
    ~Aukcioshaz();
    void kiir();
    void showTargy(int n);
    void showEmber(int n);
    void setTargytulaj(int n,int m);
    void vagyonKerdezes(int a);
    int getEmber(){return emberdb;}
    int getTargy(){return targydb;}
    Ember* getResztvevo(int a){return resztvevok[a];}
    Targy* getTargy(int a){return targyak[a];}
    void targyElad(int n);
    void betolt();
    void ment();

};
#endif


