#include <string>
#include "Garage.h"
class Auto : public Garage{
    private:
        string engine;
        string color;
        string KPP;
    protected:
    public:
        Auto(string brand, string model, string engineVal, string colorVal, string KPP):Garage(brand, model){};
};