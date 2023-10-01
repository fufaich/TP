#include <string>
using namespace std;
class Garage{
    protected:
        string brand; 
        string model;
    public:
        Garage(string brand, string model);
        Garage(const Garage& other);
        Garage();
        ~Garage(){};
        
        string getBrand() const;
        string getModel() const;
};