#include <iostream>
#include "entity/Auto.h"

using namespace std;

int main(int *argc, char **argv){
    cout << "Hello wordl" << endl;
    Auto BMW(string("BMW"), string("X5"), 3.5, string("Black"), string("Auto"));
    cout << BMW.getBrand() << " " << BMW.getModel() << endl;
    return 0;
}