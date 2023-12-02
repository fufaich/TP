#pragma once
#include <iostream>
#include <string>

//#define DEBUG 1
using namespace std;

class Student{
    private:
        string fio;
        short int idGroup;
    protected:
        int progress[5] = {0};
    public:
        Student();
        ~Student();

        void setFio(string f, string n, string o);
        void setIdGroup(short int idGroupValue);
        void setProgress(int* listValues);
        string getFio() const;
        short int getIdGroup() const;
        int* getProgress();
        int* getAndPrintProgress();
};