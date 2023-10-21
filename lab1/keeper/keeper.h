#include <fstream>
#include <iostream>
#include <sstream>

#include "struct.h"
#include "../entity/Auto.h"
#include "../entity/Bus.h"
#include "../entity/Motorcycle.h"
#include "../entity/MyException.h"



using namespace std;

class Keeper{
    private:
        int count = 0;
        Node* head;
        Node* lastUnit;

        

    public:
        Keeper():head(nullptr), lastUnit(nullptr){};
        ~Keeper();
        int getTypeOfUnit(int pos) const;
        void addUnit(Garage* unit, int pos);
        void addUnit(Garage* unit);
        void deleteUnit(int pos);
        void changeUnit(int pos);
        void printToConsole();
        void loadToFile(string nameFile);
        void loadFromFile(string nameFile);

};