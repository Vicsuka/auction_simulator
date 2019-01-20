#include "aukcioshaz.h"
#include <fstream>
using namespace std;

    void Aukcioshaz::emberAdd(Ember* e) {
        if (emberdb >= embercapac) throw std::out_of_range ("Tele a haz");
            else resztvevok[emberdb++] = e;
    }
    void Aukcioshaz::targyAdd(Targy* t) {
        if (targydb >= targycapac) throw std::out_of_range ("Tele a raktar");
            else targyak[targydb++] = t;
    }
    Aukcioshaz::~Aukcioshaz() {
        for (int i=0;i<emberdb;i++) {
            delete resztvevok[i];
        }
        delete[] resztvevok;
        for (int i=0;i<targydb;i++) {
            delete targyak[i];
        }
        delete[] targyak;

    }
    void Aukcioshaz::kiir(){
        std::cout << "--------------------A teljes aukcioshaz resztvevoi--------------------\n";
        for (int i=0; i<emberdb; i++)
            resztvevok[i]->adatok();
        std::cout << "--------------------Osszes targy--------------------\n";
        for (int i=0; i<targydb; i++)
            targyak[i]->kiir();
        std::cout << "----------------------------------------"<<std::endl;
    }

    void Aukcioshaz::showTargy(int n) {
        targyak[n]->kiir();
    }
    void Aukcioshaz::showEmber(int n) {
        resztvevok[n]->adatok();
    }
    void Aukcioshaz::setTargytulaj(int n,int m) {
        targyak[n]->setTulaj(resztvevok[m]);
    }
    void Aukcioshaz::vagyonKerdezes(int a) {
        resztvevok[a]->writeNev();
        int db=0;
        std::cout << " altal birtokolt targyak(ertekkel): ";
        int ossz= resztvevok[a]->getKp();
        for (int i=0;i<targydb;i++) {
            if ( resztvevok[a]==(targyak[i]->getTulaj())){
                targyak[i]->getNev();
                std::cout<<","<<targyak[i]->getErtek()<<";";
                ossz+=targyak[i]->getErtek();
                db+=1;
            }
        }
        std::cout<< std::endl<< "Osszvagyon: "<<ossz<<std::endl;
        resztvevok[a]->setDb(db);
    }
    void Aukcioshaz::targyElad(int n) {
        double iranyar=0;
        double alapar;
        double b;
        b=targyak[n]->getTulaj()->getGreed();
        if (targyak[n]->getTulaj() != NULL) iranyar=targyak[n]->getErtek()*b;
            else iranyar= targyak[n]->getErtek();
        if (iranyar!=0) alapar = iranyar;
        std::cout<<"Targy eladasa: ";
        targyak[n]->kiir();
        std::cout<<"Iranyar: "<<iranyar<<std::endl;
        int licitszam=0;
        int licitalok;
        int vevo=-1;
        bool eladva = false;
        while(!eladva) {
            licitalok=0;
            for (int i=0;i<emberdb;i++) {
                if (resztvevok[i]->vasarol(alapar,iranyar)!=0) {
                        resztvevok[i]->writeNev();
                        std::cout << " licitalt! Aktualis ar: ";
                        iranyar += 50;
                        std::cout << iranyar;
                        std::cout << std::endl;
                        licitszam+=1;
                        licitalok+=1;
                        vevo=i;
                }
            }
            if (licitalok==1 || (licitalok==0 && licitszam!=0)) {
            eladva = true;
            std::cout << "Targy eladva: ";
            targyak[n]->kiir();
            std::cout << "Megvette: ";
            resztvevok[vevo]->writeNev();
            std::cout << std::endl;
            if (targyak[n]->getTulaj()!=NULL) {
                    std::cout << "Elado regi illetve uj egyenleg: "<< targyak[n]->getTulaj()->getKp()<< "volt ennyi lett ->";
                    targyak[n]->getTulaj()->setKpplussz(iranyar);
                    targyak[n]->setTulaj(resztvevok[vevo]);
                    resztvevok[vevo]->setEgyenlegminusz(iranyar);
                    std::cout <<targyak[n]->getTulaj()->getKp();
                    std::cout << std::endl;
                    }
            if (targyak[n]->getTulaj()==NULL){
                    targyak[n]->setTulaj(resztvevok[vevo]);
                    resztvevok[vevo]->setEgyenlegminusz(iranyar);
            }
            }
            if (licitszam==0 && licitalok==0) {
            eladva = true;
            std::cout << "Senki nem vette meg!\n";
            }
        }

    }

    void Aukcioshaz::betolt(){
    string a,b,n;
    int e;
    double r;
    ifstream vevok("vevok.txt");
    while (vevok >> n >> e >> r)
        {
            n;
            emberAdd(new Vevo(n,e,r));
        }
        vevok.close();
    ifstream eladok("eladok.txt");
    while (eladok >> n >> e >> r)
        {
            n;
            emberAdd(new Elado(n,e,r));
        }
        eladok.close();
    ifstream kep("kep.txt");
    ifstream ekszer("ekszer.txt");
    ifstream bor("bor.txt");
    string type;
    string c,d,o;
    int y;
    string t;
    while (kep >> type)
        {
            if (type=="kep") {
                (kep >> a >> b >> e >> t >> c >> d >> y);
                n=a+b;
                o=c+d;
                targyAdd(new Kep(n,e,NULL,o,y));
            }
        }

    while (bor >> type)
        {
            if (type=="bor") {
                (bor >> a >> b >> e >> t >> y);
                n=a+b;
                targyAdd(new Bor(n,e,NULL,y));
            }
        }
    while (ekszer >> type)
        {
            if (type=="ekszer") {
                (ekszer >> a >> e >> t >> b);
                targyAdd(new Ekszer(a,e,NULL,b));
            }
        }
        kep.close();
        bor.close();
        ekszer.close();

    }

    void Aukcioshaz::ment() {

        ofstream vevok("vevok.txt");
        ofstream eladok("eladok.txt");

        for (int i=0;i<emberdb;i++) {
            if (resztvevok[i]->getSzerep()=="vevo") {
                vevok << resztvevok[i]->getNev() <<" "<< resztvevok[i]->getEgyenleg()<<" "<<resztvevok[i]->getRisk()<<endl;
            }
            if (resztvevok[i]->getSzerep()=="elado") {
                eladok << resztvevok[i]->getNev() <<" "<< resztvevok[i]->getKp()<<" "<<resztvevok[i]->getGreed()<<endl;
            }
        }
        eladok.close();
        vevok.close();
        for (int i=0;i<targydb;i++) {

        }

    }

