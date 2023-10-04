#include <iostream>
#include "entity/Auto.h"
#include "entity/Bus.h"
#include "entity/Garage.h"
#include <fstream>

using namespace std;

int main(int *argc, char **argv){
    cout << "Hello wordl" << endl;
    Auto BMW(string("BMW"), string("X5"), 3.5, string("Black"), string("Auto"));
    cout << BMW.getBrand() << " " << BMW.getModel() << endl;
    Garage* ptrBase = &BMW;

    ofstream out("Output.txt");
    ptrBase->PrintDetails(out);
    Bus* ptrBus = new Bus("Mercedes", "Busik", 15, 20, "City");
    ptrBase = ptrBus;
    ptrBase->PrintDetails(out);
    out.close();
    ifstream in("Output.txt");
    Auto* ptrNewTestBMW = new Auto();
    ptrNewTestBMW->ReadDetails(in);
    in.close();
    cout << ptrNewTestBMW->getBrand() << " " << ptrNewTestBMW->getModel() << endl;

    
    return 0;
}