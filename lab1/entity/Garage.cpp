#include "Garage.h"
using namespace std;

Garage::Garage(string brand, string model){
    this->brand = brand;
    this->model = model;
}

Garage::Garage(const Garage& other){
            this->brand = other.brand;
            this->model = other.model;
}

Garage::Garage(){
    this->brand = "Undefined";
    this->model = "Undefined";
}

string Garage::getBrand() const{
    return this->brand;
}

string Garage::getModel() const{
    return this->model;
}