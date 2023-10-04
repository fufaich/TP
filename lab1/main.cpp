#include <iostream>
#include "entity/Auto.h"
#include "entity/Bus.h"
#include "entity/Motorcycle.h"
#include "keeper/keeper.h"



int main(int *argc, char **argv){
     Auto BMW(string("BMW"), string("X5"), 3.5, string("Black"), string("Auto"));
     Bus busik(string("Mercedes"), string("Busik"), 15,20,string("City"));
     Motorcycle motik(string("Honda"), string("CBR600"), 0.6, 249, string("sport"));
     Keeper kep;
     kep.addUnit(&BMW);
     kep.addUnit(&busik);
     kep.addUnit(&motik);
     kep.printToConsole();

    

    return 0; 
}