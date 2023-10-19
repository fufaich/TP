#include "../keeper/keeper.h"

class UI{
    private:
        string fileName;
        Keeper* kep;
        void menu(int mode);
        void StartMenu();
        void addMenu();
        void addAuto();
        void addBus();
        void addMoto();
    public:
        UI(Keeper* kep);
        ~UI();
};