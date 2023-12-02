#pragma once
#include "StudentWrap.h"
#include "MyException.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

struct Node{
    StudentV2* value;
    
    Node* next;
    Node(StudentV2* val, Node* nextNode = nullptr){
        value = val;
        next = nextNode;
    };
};

class Keeper{
private:
    Node* head;
    Node* tail;
    Node* tmp;
    int countNodes;
    
public:
    Keeper();
    ~Keeper();

    void deleteUnit(int pos);
    void printToConsole();
    void printToConsoleGenius();
    void add(StudentV2* student);
    void sort();
    void loadToFile(string nameFile);
    void loadFromFile(string nameFile);
    void changeUnit(int pos);
    Node& operator[] (const int index);
};