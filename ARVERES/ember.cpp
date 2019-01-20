#include "ember.h"

const std::string Vevo::szerep="vevo";
const std::string Elado::szerep="elado";

int Vevo::vasarol(int t,int ar){
    double kedv = (rand()%10)*0.01;
    if (!(ar<(getEgyenleg()*(1-kedv)))) return 0;
    if (((ar+50)<getEgyenleg()*riskfakt) && (((t)*4)>ar)) return ar+50;
    else return 0;
}
void Vevo::adatok(){
        Ember::adatok();
        std::cout << "Egyenleg: "<< egyenleg << "\nBevallalossag: " << riskfakt << std::endl << std::endl;
        }

void Elado::adatok(){
        Ember::adatok();
        std::cout << "Keszpenz: "<< kp << "\nKapzsisag: " << greed << std::endl << std::endl;
        }
