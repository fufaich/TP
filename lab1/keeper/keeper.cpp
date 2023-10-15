#include "keeper.h"

Keeper::~Keeper(){
    Node* tmp;
    while(head != nullptr){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

void Keeper::addUnit(Garage* unit){
    if(head == nullptr){
        head = new Node(unit);
        lastUnit = head;
    }
    else{
        lastUnit->next = new Node(unit);
        lastUnit = lastUnit->next;
    }
}

void Keeper::printToConsole(){
    Node* tmp = head;
    while (tmp != nullptr)
    {
        tmp->PtrGarage->PrintDetails(std::cout);
        tmp = tmp->next;
    }
    
}