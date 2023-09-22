#include "Auto.h"

Auto::Auto(string brand, string model, string engineVal, string colorVal, string KPP):Garage(brand, model){
    this->engine = engineVal;
    this->color = colorVal;
    this->KPP = KPP;
};