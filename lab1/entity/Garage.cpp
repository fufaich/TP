#include "Garage.h"
using namespace std;

Garage::Garage(string brand, string model){
    this->brand = brand;
    this->model = model;
}

string Garage::getBrand() const{
    return this->brand;
}

string Garage::getModel() const{
    return this->model;
}