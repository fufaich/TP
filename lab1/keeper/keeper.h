#include <fstream>
#include "struct.h"


using namespace std;

class Keeper{
    private:
        Node* headAuto = nullptr;
        Node* lastAuto= nullptr;
        Node* headBus= nullptr;
        Node* lastBus= nullptr;
        Node* headMoto= nullptr;
        Node* lastMoto= nullptr;
        string filename= nullptr;

    public:
        Keeper(){};
        int addUnit(Garage* unit);
        int deleteUnit(const Garage* unit);


};