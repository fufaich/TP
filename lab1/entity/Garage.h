#include <iostream>
using namespace std;
class Garage{
    private:
        string brand; 
        string model;
    public:
        Garage(string brand, string model);
        ~Garage(){};
        
        string getBrand() const;
        string getModel() const;
};