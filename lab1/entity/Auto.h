#pragma once
#include "Garage.h"
#include <fstream>
#include <sstream>

/*Для
каждого автомобиля определено: марка, модель, объем двигателя, цвет, тип
КПП.
*/
class Auto: public Garage{
    private:
        float SizeEngine;
        string Color;
        string KPP;
    protected:

    public:
        Auto(string brand, string model, float SizeEngine, string color, string kpp):Garage(brand, model),SizeEngine(SizeEngine),
        Color(color), KPP(kpp){};
        Auto(const Auto& other);
        Auto(string str);
        Auto();
        float getSizeEngine() const;
        string getColor() const;
        string getKPP() const;

        void PrintDetails(std::ostream& os) const override;
        void ReadDetails(istream& is)  override;
};