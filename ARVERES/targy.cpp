#include "targy.h"

const std::string Kep::tipus="kep";
const std::string Bor::tipus="bor";
const std::string Ekszer::tipus="ekszer";

void Targy::setTulaj(Ember* e) {
    tulaj = e;
}

void elad(int ar) {

}

void Kep::kiir(){
    Targy::kiir();
    std::cout << "  Tipus: festmeny" << "\n  Festette: "<< festo << " " << evszam <<"-ban/-ben"<<std::endl;
    }

void Bor::kiir(){
    Targy::kiir();
    std::cout << "  Tipus: bor" << "\n  Evjarat: "<< evjarat <<std::endl;
    }

void Ekszer::kiir(){
    Targy::kiir();
    std::cout << "  Tipus: ekszer" << "\n  Anyaga: "<< anyag <<std::endl;
    }
