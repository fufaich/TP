#include "Garage.h"

/*
Для каждого мотоцикла определено: марка, модель, объем двигателя,
мощность двигателя, для какой местности мотоцикл предназначен.
*/
using namespace std;
class Motorcycle: public Garage{
    private:
        float SizeEngine;
        int HP;
        string Mission;
    protected:

    public:
        Motorcycle(string brand, string model, float SizeEngine, int HP, string mission):Garage(brand, model),SizeEngine(SizeEngine),
        HP(HP), Mission(mission){};

        float getSizeEngine() const;
        int getHP() const;
        string getMission() const;
};