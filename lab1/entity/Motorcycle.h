#include "Garage.h"
#include <fstream>
/*
Для каждого мотоцикла определено: марка, модель, объем двигателя,
мощность двигателя, для какой местности мотоцикл предназначен.
*/
class Motorcycle: public Garage{
    private:
        float SizeEngine;
        int HP;
        string Mission;
    protected:

    public:
        Motorcycle(string brand, string model, float SizeEngine, int HP, string mission):Garage(brand, model),SizeEngine(SizeEngine),
        HP(HP), Mission(mission){};
        Motorcycle(const Motorcycle& other);
        Motorcycle();

        float getSizeEngine() const;
        int getHP() const;
        string getMission() const;


        short int getType() const override;
        void PrintDetails(std::ostream& os) const override;
        void ReadDetails(istream& is)  override;
};