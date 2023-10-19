#include <iostream>
#include "ui/ui.h"


int main(int *argc, char **argv){
    Keeper* kep = new Keeper();
    UI ui(kep);
    return 0;
}