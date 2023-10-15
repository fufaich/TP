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

void Keeper::loadToFile(string nameFile){
    ofstream outputFile(nameFile);
    Node* tmp = head;
    while(tmp != nullptr){
        tmp->PtrGarage->PrintDetails(outputFile);
        tmp = tmp->next;
    }
}



void Keeper::loadFromFile(string nameFile){
    ifstream readFile(nameFile);
    string word;
    while (readFile >> word)
    {
        if(word== string("Auto")){
            cout << "Auto" << endl;
        }else if(word == string("Bus")){
            cout << "Bus" << endl;
        }
        else if(word == string("Moto")){
            cout << "Moto" << endl;
        }
    }
    
}