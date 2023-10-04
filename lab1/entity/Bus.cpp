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

int Bus::getCountSitPlace() const{
    return this->countSitPlace;
}

int Bus::getCoutnPlace() const{
    return this->countPlace;
}

string Bus::getDestination() const{
    return this->destination;
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

short int Bus::getType() const{
    return 1;
}

