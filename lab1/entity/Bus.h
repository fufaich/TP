/*
Для
каждого автобуса определено: марка, модель, количество сидячих
пассажирских мест, общее количество пассажирских мест, конечный пункт
*/
#include "Garage.h"
using namespace std;

class Bus: public Garage{
    private:
        int countSitPlace;
        int countPlace;
        string destination;
    protected:

    public:
        Bus(string brand, string model, int countSitPlace, int countPlace, string destination) :Garage(brand, model),
        countSitPlace(countSitPlace), countPlace(countPlace), destination(destination){};

        int getCountSitPlace() const;
        int getCoutnPlace() const;
        string getDestination() const;
};
