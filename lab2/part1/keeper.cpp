#include "Keeper.h"

Keeper::Keeper(){
    head = nullptr;
    tail = nullptr;
    tmp = nullptr;
    countNodes = 0;
    #ifdef DEBUG
    std::cout << "Constructor Keeper" << std::endl;
    #endif
}

Keeper::~Keeper(){
    Node* tmp;
    while(head != nullptr){
        tmp = head;
        head = head->next;
        delete tmp;
    }
    #ifdef DEBUG
    std::cout << "Destructor Keeper" << std::endl;
    #endif
}

void Keeper::add(StudentV2* student){
   if(head == nullptr){
        head = new Node(student);
        tail = head;
   }else{
        tail->next = new Node(student);
        tail = tail->next;
   }
    countNodes++;

}


void Keeper::printToConsoleGenius(){
    Node* iterator = head;
    iterator = head;
    int k = 0;
    int prog[5];
    bool mode = true;
    for(int i = 0; i < countNodes; i++){
        mode = true;
        StudentV2 *student = iterator->value;
        int* prog = student->getProgress();
        for (size_t i = 0; i < 5; i++)
        {
            prog[i] = *(prog+i);
            if(*(prog+i) < 4){
                mode = false;
            }
        }
        if(mode){
            k++;
            std:: cout << i << "  - ";
            std:: cout << student->getFio() << " ";
            std:: cout << "IdGorup: " << student->getIdGroup() << " ";
            std:: cout << "Math: " << prog[0] << " ";
            std:: cout << "TP: " << prog[1] << " ";
            std:: cout << "KG: " << prog[2] << " ";
            std:: cout << "Philosofia: " << prog[3] << " ";
            std:: cout << "English: " << prog[4] << " ";
            std:: cout << "SredBall: " <<student->getSredBall() <<std::endl;;
        }
        iterator = iterator->next;
    }
    if (k==0){
        std:: cout << "Genius not found"<< std::endl;
    }
}


void Keeper::printToConsole(){
    Node* iterator = head;
    iterator = head;
    int prog[5];
    for(int i = 0; i < countNodes; i++){
        StudentV2 *student = iterator->value;
        int* prog = student->getProgress();
        for (size_t i = 0; i < 5; i++)
        {
            prog[i] = *(prog+i);
        }
        std:: cout << i << "  -";
        std:: cout << student->getFio() << " ";
        std:: cout << "IdGorup: " << student->getIdGroup() << " ";
        std:: cout << "Math: " << prog[0] << " ";
        std:: cout << "TP: " << prog[1] << " ";
        std:: cout << "KG: " << prog[2] << " ";
        std:: cout << "Philosofia: " << prog[3] << " ";
        std:: cout << "English: " << prog[4] << " ";
        std:: cout << "SredBall: " <<student->getSredBall() <<std::endl;;

        iterator = iterator->next;
    }
}

void Keeper::deleteUnit(int pos){
    if (pos < 0 || pos >= (countNodes)){
        throw MyException("Out of range");
    }
    Node* tmp;
    Node* pred_del;
    Node* posle_del;

    if(pos == 0){
        tmp = head;
        head = head->next;
        delete tmp;
        countNodes -= 1;
    } else if(pos == (countNodes -1)){
        pred_del = head;
       for (size_t i = 0; i < pos - 1; i++)
       {
        pred_del = pred_del->next;
       }
       tmp = pred_del->next;
       pred_del->next = nullptr;
       tail = pred_del;
       delete tmp;
       countNodes--;
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
        countNodes--;
    }
}

 void Keeper::changeUnit(int pos){
    if (pos < 0 || pos >= countNodes){
        throw MyException("Out of range");
    }

    Node* tmp = head;

    for (size_t i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }

    tmp->value->setUnit();
 }

 bool isSort(Node* start, Node* end){
    Node* tmp;
    bool result = true;
    tmp = start->next;
    while(start != end){
        if(tmp == nullptr){
            break;
        }
        if(*(start->value) < *(tmp->value)){
            return !result;
        }
        start = start->next;
        tmp = tmp->next;
    }
    return result;
 }

 void swap(Node* l, Node* r){
    StudentV2* tmp = l->value;
    l->value = r->value;
    r->value = tmp;
 }

void Keeper::sort(){
    if(countNodes <= 1){
        return void();
    }
    if(isSort(head,tail)){
        system("pause");
    }
    else{
        int lenght = countNodes;
        Node* left = head;
        Node* right = head->next;
    
        for (size_t i = 0; i < lenght; i++)
        {   
            for (size_t j = 0; j < lenght-1; j++)
            {
                if( *(((*this)[j]).value) <=   *(((*this)[j+1]).value) ){
                    swap((((*this)[j]).value), (((*this)[j+1]).value)); 
                }
                
            }
        }
    }
}

void Keeper::loadToFile(string nameFile){
    ofstream outputFile(nameFile);
    Node* tmp = head;
    while (tmp != nullptr){
        tmp->value->PrintDetails(outputFile);
        if(tmp->next != nullptr)
            outputFile << "\n";
        tmp = tmp->next;
    }
    outputFile.close();
};

void Keeper::loadFromFile(string nameFile){
    ifstream readFile(nameFile);
    if (!readFile.is_open()){
        throw MyException("File not found");
    }
    string word;
    string line;
    while (!readFile.eof())
    {
        getline(readFile, line);
        this->add(new StudentV2(line));
        
    }
    readFile.close();
    
}

Node& Keeper::operator[] (const int index) {
    Node* tmp = head;
    if (index < 0 || index >= (countNodes)){
        throw MyException("Out of range");
    }

    for (size_t i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return *tmp;
}
