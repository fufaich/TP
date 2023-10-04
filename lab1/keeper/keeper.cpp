#include "keeper.h"

int Keeper::addUnit(Garage* unit){
    switch (unit->getType())
    {
    case 0://Auto
        if(headAuto == nullptr){
            headAuto = new Node(unit);
            lastAuto = headAuto;
        }else{
            lastAuto->next = new Node(unit);
            lastAuto = lastAuto->next;
        }
        break;

    case 1://Bus
        if(headBus == nullptr){
            headBus = new Node(unit);
            lastBus = headBus;
        }else{
            lastBus->next = new Node(unit);
            lastBus = lastBus->next;
        }
        break;

    case 2://Motorcycle
        if(headMoto == nullptr){
            headMoto = new Node(unit);
            lastMoto = headMoto;
        }else{
            lastMoto->next = new Node(unit);
            lastMoto = lastMoto->next;
        }
        break;
    
    default:
        break;
    };

    return 0;
}