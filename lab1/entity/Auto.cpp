#include "Auto.h"

using namespace std;

Auto::Auto(const Auto& other):Garage(other){
    this->SizeEngine = other.SizeEngine;
    this->Color = other.Color;
    this->KPP = other.KPP;
}

Auto::Auto():Garage(){
    this->SizeEngine = 0;
    this->Color = "Undefined";
    this->KPP = "Undefined";
}

float Auto::getSizeEngine() const{
    return this->SizeEngine;
}

string Auto::getColor() const{
    return this->Color;
}

string Auto::getKPP() const{
    return this->KPP;
}