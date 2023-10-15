#include <fstream>
#include <iostream>
#include <sstream>

#include "struct.h"
#include "../entity/Auto.h"
#include "../entity/Bus.h"
#include "../entity/Motorcycle.h"



using namespace std;

class Keeper{
    private:
        Node* head;
        Node* lastUnit;
        Node* tail;

    public:
        Keeper():head(nullptr),tail(nullptr), lastUnit(nullptr){};
        ~Keeper();
        void addUnit(Garage* unit);
        void printToConsole();
        void loadToFile(string nameFile);
        void loadFromFile(string nameFile);

};