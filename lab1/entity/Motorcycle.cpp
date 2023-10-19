#include "Motorcycle.h"

Motorcycle::Motorcycle(const Motorcycle& other):Garage(other){
    this->SizeEngine = other.SizeEngine;
    this->HP = other.HP;
    this->Mission = other.Mission;
}

Motorcycle::Motorcycle():Garage(){
    this->SizeEngine = 0;
    this->HP = 0;
    this->Mission = "Undefined";
}

Motorcycle::Motorcycle(string str):Garage(){
    string brand;
    string model;
    float sizeEngine;
    int HP;
    string Mission;

    istringstream iss(str);
    iss >> brand >> model >> sizeEngine >> HP>> Mission;
    this->brand = brand;
    this->model = model;
    this->SizeEngine = (float)sizeEngine;
    this->HP = (int)HP;
    this->Mission = Mission;   
}

Motorcycle::~Motorcycle(){
    cout << "Destructor Moto" << endl;
    system("pause");
}

float Motorcycle::getSizeEngine() const{
    return this->SizeEngine;
}

int Motorcycle::getHP() const{
    return this->HP;
}

string Motorcycle::getMission() const{
    return this->Mission;
}

void Motorcycle::PrintDetails(std::ostream& os) const{
        os << "Moto ";
        os << this->brand << " ";
        os << this->model << " ";
        os << this->SizeEngine << " ";
        os << this->HP << " ";
        os << this->Mission << endl;
    }

void Motorcycle::ReadDetails(istream& is) {
    is >> brand >> model >> SizeEngine >> HP >> Mission;
}


