#include <iostream>
#include "entity/Auto.h"
#include "entity/Bus.h"
#include "entity/Motorcycle.h"
#include "keeper/keeper.h"

int main(int *argc, char **argv){
    cout << "Hello wordl" << endl;
    Keeper kep;
    Auto BMW(string("BMW"), string("X5"), 3.5, string("Black"), string("Auto"));
    Bus busik(string("Mercedes"), string("Busik"), 15,20,string("City"));
    kep.addUnit(&BMW);
    kep.addUnit(&busik);
    kep.printToConsole();
    return 0;
}