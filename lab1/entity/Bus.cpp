#include "Bus.h"

Bus::Bus(const Bus& other): Garage(other){
    this->countSitPlace = other.countSitPlace;
    this->countPlace = other.countPlace;
    this->destination = other.destination;
}

Bus::Bus():Garage(){
    this->countSitPlace =  0;
    this->countPlace = 0;
    this->destination = "Undefined";
}

Bus::Bus(string str):Garage(){
    string brand;
    string model;
    int countSitPlace;
    int countPlace;
    string destination;
    istringstream iss(str);
    iss >> brand >> model >> countSitPlace >> countPlace>> destination;
    this->brand = brand;
    this->model = model;
    this->countSitPlace = (int)countSitPlace;
    this->countPlace = (int)countPlace;
    this->destination = destination;   
}

Bus::~Bus(){
    cout << "Destructor Bus" << endl;
    system("pause");
}

int Bus::getCountSitPlace() const{
    return this->countSitPlace;
}

int Bus::getCoutnPlace() const{
    return this->countPlace;
}

string Bus::getDestination() const{
    return this->destination;
}

void Bus::setCountSitPlace(int value){
    this->countSitPlace = value;
}

void Bus::setCoutnPlace(int value){
    this->countPlace = value;
}

void Bus::setDestination(string value){
    this->destination = value;
}



void Bus::PrintDetails(std::ostream& os) const{
        os << "Bus ";
        os << this->brand << " ";
        os << this->model << " ";
        os << this->countSitPlace << " ";
        os << this->countPlace << " ";
        os << this->destination << endl;
}

void Bus::ReadDetails(istream& is) {
    is >> brand >> model >> countSitPlace >> countPlace >> destination;
}

void Bus::editUnit(string str){
    string brand;
    string model;
    int countSitPlace;
    int countPlace;
    string destination;
    istringstream iss(str);
    iss >> brand >> model >> countSitPlace >> countPlace>> destination;
    this->brand = brand;
    this->model = model;
    this->countSitPlace = (int)countSitPlace;
    this->countPlace = (int)countPlace;
    this->destination = destination;   
}


int Bus::getType() const{
    return 1;
}
