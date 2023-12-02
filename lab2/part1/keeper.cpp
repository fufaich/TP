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
    int prog[5];
    bool mode = true;
    for(int i = 0; i < countNodes; i++){
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

void Keeper::sort(){
    if (countNodes <= 1)
        return;

    StudentV2 **studentsArray = new StudentV2 *[countNodes];
    Node *current = head;
    int index = 0;

    while (current != nullptr)
    {
        studentsArray[index++] = current->value;
        current = current->next;
    }

    std::sort(studentsArray, studentsArray + countNodes, [](const StudentV2 *a, const StudentV2 *b)
              { return a->getSredBall() > b->getSredBall(); });

    head = new Node(studentsArray[0]);
    current = head;

    for (int i = 1; i < countNodes; ++i)
    {
        current->next = new Node(studentsArray[i]);
        current = current->next;
    }

    delete[] studentsArray;
}

void Keeper::loadToFile(string nameFile){
    ofstream outputFile(nameFile);
    Node* tmp = head;
    while (tmp != nullptr){
        tmp->value->PrintDetails(outputFile);
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
