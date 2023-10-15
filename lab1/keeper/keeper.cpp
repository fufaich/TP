#include "keeper.h"



Keeper::~Keeper()
{
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
};


void Keeper::loadFromFile(string nameFile){
    ifstream readFile(nameFile);
    string word;
    string line;
    while (!readFile.eof())
    {
        if(readFile >> word){
            if(word== string("Auto")){
                getline(readFile, line);
                this->addUnit(new Auto(line));
            }else if(word == string("Bus")){
                getline(readFile, line);
                this->addUnit(new Bus(line));
            }
            else if(word == string("Moto")){
                getline(readFile, line);
                this->addUnit(new Motorcycle(line));
            }
        }else{
            break;
        }
        
    }
    readFile.close();
    
}