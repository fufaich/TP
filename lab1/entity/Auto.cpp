#include "Auto.h"

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

void Auto::PrintDetails(ostream& os) const{
        os << "Auto ";
        os << this->brand << " ";
        os << this->model << " ";
        os << this->SizeEngine << " ";
        os << this->Color << " ";
        os << this->KPP << endl;
    }

void Auto::ReadDetails(istream& is) {
    is >> brand >> model >> SizeEngine >> Color >> KPP;
}


