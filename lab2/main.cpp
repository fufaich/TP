#include <iostream>
#include "part1/Keeper.h"
#include "part1/Menu.h"
#include "part2/part2.h"
using namespace std;

int main(int *argc, char **argv){
    int choose = 2;
    system("cls");
    std::cout << "Enter the part: " << std::endl;
    cin >> choose;

    if(choose == 1){
        Menu menu;
        menu.start();
    }else if(choose == 2){
        partTwo();
    }

    

    return 0;
}