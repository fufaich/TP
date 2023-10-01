#include <string>
using namespace std;
class Garage{
    protected:
        string brand; 
        string model;
    public:
        Garage(string brand, string model);
        ~Garage(){};
        
        string getBrand() const;
        string getModel() const;
};