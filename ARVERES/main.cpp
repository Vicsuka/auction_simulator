
#include <iostream>
#include "aukcioshaz.h"



using namespace std;

int main()
{
    try {
    Aukcioshaz ah(40,50);
    ah.betolt();

    for (int i=0;i<ah.getTargy();i++){
        ah.setTargytulaj(i,19);
    }
    for (int i=0;i<ah.getTargy();i++){
        ah.targyElad(i);
    }
    ah.kiir();
    ah.ment();

    }

    catch (out_of_range& e) {cout << "Tele a haz";}
    cout << endl;
    cout << "Arveres vege!" << endl;
    return 0;
}
