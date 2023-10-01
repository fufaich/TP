#include "Garage.h"

/*Для
каждого автомобиля определено: марка, модель, объем двигателя, цвет, тип
КПП.
*/
using namespace std;
class Auto: public Garage{
    private:
        float SizeEngine;
        string Color;
        string KPP;
    protected:

    public:
        Auto(string brand, string model, float SizeEngine, string color, string kpp):Garage(brand, model),SizeEngine(SizeEngine),
        Color(color), KPP(kpp){};
        float getSizeEngine() const;
        string getColor() const;
        string getKPP() const;

};