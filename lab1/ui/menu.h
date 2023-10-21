#pragma once

#include "../entity/Auto.h"
#include "../entity/Bus.h"
#include "../entity/Motorcycle.h"
//#include "../entity/MyException.h"
#include "../keeper/keeper.h"

class Menu{
    private:
        Keeper* kep;
        std::string filename;
        void startMenu();
        void menuAdd();
        void menuDelete();
        void menuEdit();
    public:
        Menu();


};