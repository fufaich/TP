#include <iostream>
#include "entity/Auto.h"
#include "entity/Bus.h"
#include "entity/Motorcycle.h"
#include "keeper/keeper.h"

int main(int *argc, char **argv){
    cout << "Hello wordl" << endl;
    Keeper* kep = new Keeper();
    Auto* bmw= new Auto(string("BMW"), string("X5"), 3.5, string("Black"), string("Auto"));
    Bus*  busik = new Bus(string("Mercedes"), string("Busik"), 15,20,string("City"));
    kep->addUnit(bmw);
    kep->addUnit(busik);
    kep->printToConsole();

    delete kep;
    return 0;
}