#include <string>
using namespace std;
class Garage{
    protected:
        string brand; 
        string model;
    public:
        Garage(string brand, string model):brand(brand), model(model){};
        ~Garage(){};
        
        virtual string getBrand() = 0;
        virtual string getModel() = 0;
};