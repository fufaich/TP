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
    Motorcycle* motik = new Motorcycle(string("Honda"), string("CBR600"), 4.5,205,string("Sport"));
    kep->addUnit(bmw);
    kep->addUnit(busik);
    kep->addUnit(motik);
    //kep->printToConsole();
    //kep->loadToFile("test.txt");
    kep->loadFromFile(string("test.txt"));

    delete kep;
    return 0;
}