#include "../keeper/keeper.h"

class UI{
    private:
        string fileName;
        void menu(Keeper* kep);
        void StartMenu(Keeper* kep);
        void addAuto();
        void addBus();
        void addMoto();
    public:
        UI(Keeper* kep);
        ~UI();
};