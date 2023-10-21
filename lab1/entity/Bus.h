#pragma once

/*
Для
каждого автобуса определено: марка, модель, количество сидячих
пассажирских мест, общее количество пассажирских мест, конечный пункт
*/
#include "Garage.h"
#include <fstream>
#include <sstream>


class Bus: public Garage{
    private:
        int countSitPlace;
        int countPlace;
        string destination;

    public:
        Bus(string brand, string model, int countSitPlace, int countPlace, string destination) :Garage(brand, model),
        countSitPlace(countSitPlace), countPlace(countPlace), destination(destination){};
        Bus(const Bus& other);
        Bus(string str);
        Bus();
        ~Bus();

        int getCountSitPlace() const;
        int getCoutnPlace() const;
        string getDestination() const;

        void setCountSitPlace(int value);
        void setCoutnPlace(int value);
        void setDestination(string value);

        void editUnit(string str) override;
        void PrintDetails(ostream& os) const override;
        void ReadDetails(istream& is)  override;
        int getType() const;
};
