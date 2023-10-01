#include "Motorcycle.h"

using namespace std;

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

float Motorcycle::getSizeEngine() const{
    return this->SizeEngine;
}

int Motorcycle::getHP() const{
    return this->HP;
}

string Motorcycle::getMission() const{
    return this->Mission;
}