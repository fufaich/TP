#include "Student.h"

Student::Student(){
    #ifdef DEBUG
        std::cout << "Constructor Student" << std::endl;
    #endif

    fio = "";
    idGroup = 0;
    
}

Student::~Student(){
    #ifdef DEBUG
        std::cout << "Destructor Student" << std::endl;
    #endif
}

void Student::setFio(string f, string n, string o){
    try
    {
        fio = f + " " + n[0] + " " + o[0] + " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Student::setIdGroup(short int idGroupValue){
    idGroup = idGroupValue;
}

void Student::setProgress(int* listValues){
    for (size_t i = 0; i < 5; i++)
    {
        progress[i] = *(listValues++);
    }
    
};

string Student::getFio() const{
    return fio;
};


short int Student::getIdGroup() const{
    return idGroup;
}

int* Student::getProgress(){
    return progress;
}

int* Student::getAndPrintProgress(){
    std::cout << "[";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << progress[i] << ", ";
    }
    std::cout << progress[4] << "]" << std::endl;
    
    return progress;
}