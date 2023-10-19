#include "keeper.h"



Keeper::~Keeper()
{
    Node* tmp;
    while(head != nullptr){
        tmp = head;
        head = head->next;
        delete tmp;
    }
    cout << "Destructor Keeper" << endl;
    system("pause");
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

void Keeper::deleteUnit(int pos){
    if (pos < 0 || pos >= (count)){
        throw MyException("Out of range");
    }
    Node* tmp;
    Node* pred_del;
    Node* posle_del;

    if(pos == 0){
        tmp = head;
        head = head->next;
        delete tmp;
        count -= 1;
    } else if(pos == (count -1)){
        pred_del = head;
       for (size_t i = 0; i < pos - 1; i++)
       {
        pred_del = pred_del->next;
       }
       tmp = pred_del->next;
       pred_del->next = nullptr;
       lastUnit = pred_del;
       delete tmp;
       count--;
    }else{
        pred_del = head;
        for (size_t i = 0; i < pos - 1; i++)
        {
            pred_del = pred_del->next;
        }
        tmp = pred_del->next;
        posle_del = tmp->next;
        delete tmp;
        pred_del->next = posle_del;
        count--;
    }

    

}

void Keeper::printToConsole(){
    Node* tmp = head;
    int i = 0;
    while (tmp != nullptr)
    {
        cout << i++ << " - ";
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
    outputFile.close();
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
            count += 1;
        }else{
            break;
        }
        
    }
    readFile.close();
    
}