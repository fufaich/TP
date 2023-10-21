#include "Auto.h"

Auto::Auto(const Auto& other):Garage(other){
    this->SizeEngine = other.SizeEngine;
    this->Color = other.Color;
    this->KPP = other.KPP;
}

Auto::Auto(string str):Garage(){
    string brand;
    string model;
    float sizeEngine;
    string color;
    string kpp;
    istringstream iss(str);
    iss >> brand >> model >> sizeEngine >> color>> kpp;
    this->brand = brand;
    this->model = model;
    this->SizeEngine = (float)sizeEngine;
    this->Color = color;
    this->KPP = kpp;   
}

Auto::Auto():Garage(){
    this->SizeEngine = 0;
    this->Color = "Undefined";
    this->KPP = "Undefined";
}

Auto::~Auto(){
    std::cout << "Destructor Auto" << endl;
    system("pause");
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

void Auto::setSizeEngine(float value){
    this->SizeEngine = value;
}

void Auto::setColor(string value){
    this->Color = value;
}

void Auto::setKPP(string value){
    this->KPP = value;
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

void Auto::editUnit(string str) {
    string brand;
    string model;
    float sizeEngine;
    string color;
    string kpp;
    istringstream iss(str);
    iss >> brand >> model >> sizeEngine >> color>> kpp;
    this->brand = brand;
    this->model = model;
    this->SizeEngine = (float)sizeEngine;
    this->Color = color;
    this->KPP = kpp;   
}

int Auto::getType() const{
    return 0;
}
