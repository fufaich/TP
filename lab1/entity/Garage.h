#pragma once
#include <string>
#include <iostream>
using namespace std;
class Garage{
    protected:
        string brand; 
        string model;
    public:
        Garage(string brand, string model);
        Garage(const Garage& other);
        Garage();
        virtual ~Garage(){
            cout << "Destructor garage" << endl;
        };
        
        string getBrand() const;
        string getModel() const;
        void setBrand(std::string brand);
        void setModel(std::string model);

        virtual void setUnit() = 0;
        virtual void PrintDetails(std::ostream& os) const = 0;
        virtual void ReadDetails(std::istream& is)  = 0;
};