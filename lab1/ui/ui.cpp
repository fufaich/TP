#include "ui.h"
using namespace std;

UI::UI(){
    StartMenu();
};

UI::~UI(){
    cout << "Destructor UI" << endl;
    system("pause");
};

void UI::addAuto(){
    std::string tmp;
    std::string brand;
    std::string model;
    float sizeEngine;
    std::string Color;
    std::string KPP;

    cout << "Enter the brand: ";
    cin >> brand;
    system("cls");

    cout << "Enter the model: ";
    cin >> model;
    

    while(1){
        system("cls");
        cout << "Enter the sizeEngine: ";
        cin >> tmp;
        try {
            sizeEngine = std::stof(tmp);
            break;
        } catch (const std::invalid_argument& e){
            std::cout << "Error. Try again." << std::endl;
            system("pause");
        }
    }
    
    system("cls");
    cout << "Enter the Color: ";
    cin >> Color;
    system("cls");

    cout << "Enter the KPP: ";
    cin >> KPP;
    system("cls");
    kep->addUnit(new Auto(brand, model, sizeEngine, Color, KPP));
};

void UI::addBus(){
    std::string tmp;

    std::string brand;
    std::string model;

    int countSitPlace;
    int countPlace;
    string destination;

    cout << "Enter the brand: ";
    cin >> brand;
    system("cls");

    cout << "Enter the model: ";
    cin >> model;
    

    while(1){
        system("cls");
        cout << "Enter the countSitPlace: ";
        cin >> tmp;
        try {
            countSitPlace = std::stoi(tmp);
            break;
        } catch (const std::invalid_argument& e){
            std::cout << "Error. Try again." << std::endl;
            system("pause");
        }
    }
    
    while(1){
        system("cls");
        cout << "Enter the countPlace: ";
        cin >> tmp;
        try {
            countPlace = std::stoi(tmp);
            break;
        } catch (const std::invalid_argument& e){
            std::cout << "Error. Try again." << std::endl;
            system("pause");
        }
    }

    system("cls");
    cout << "Enter the destination: ";
    cin >> destination;

    kep->addUnit(new Bus(brand, model, countSitPlace, countPlace, destination));
}

void UI::addMoto(){
    std::string tmp;

    std::string brand;
    std::string model;

    float SizeEngine;
    int HP;
    string Mission;

    cout << "Enter the brand: ";
    cin >> brand;
    system("cls");

    cout << "Enter the model: ";
    cin >> model;
    

    while(1){
        system("cls");
        cout << "Enter the SizeEngine: ";
        cin >> tmp;
        try {
            SizeEngine = std::stof(tmp);
            break;
        } catch (const std::invalid_argument& e){
            std::cout << "Error. Try again." << std::endl;
            system("pause");
        }
    }
    
    while(1){
        system("cls");
        cout << "Enter the HP: ";
        cin >> tmp;
        try {
            HP = std::stoi(tmp);
            break;
        } catch (const std::invalid_argument& e){
            std::cout << "Error. Try again." << std::endl;
            system("pause");
        }
    }

    system("cls");
    cout << "Enter the Mission: ";
    cin >> Mission;

    kep->addUnit(new Motorcycle(brand, model, SizeEngine, HP, Mission));
}


void UI::addMenu(){
    char choose;
    system("cls");
    cout << "1 - add Auto" << endl;
    cout << "2 - add Bus" << endl;
    cout << "3 - add Moto" << endl;
    while(1){
        cin >> choose;
        switch (choose)
        {
        case '1':
            addAuto();
            return void();
        case '2':
            addBus();
            return void();

        case '3':
            addMoto();
            return void();

        default:
            cout << "Incorecct command. Try again" << endl;
            system("pause");
            break;
        }
    }
    
}

void UI::menu(int mode){
    string tmp;
    char choose;
    int pos;
    
    while(1){
        system("cls");
        cout << "1 - print data" << endl;
        cout << "2 - add unit" << endl;
        cout << "3 - delete unit" << endl;
        cout << "4 - save to file" << endl;
        cout << "0 - exit" << endl;
        cin >> choose;
        switch (choose)
        {
            case '1':
                system("cls");
                kep->printToConsole();
                system("pause");
                break;
            case '2':
                addMenu();
                break;
            case '3':
                while(1){
                    system("cls");
                    cout << "Enter the pos: ";
                    cin >> tmp;
                    try {
                        pos = std::stoi(tmp);
                        break;
                    } catch (const MyException& e){
                        std::cerr << "Error. Try again." << std::endl;
                        system("pause");
                    }
                }

                try
                {
                    kep->deleteUnit(pos);
                }
                catch(const MyException& e)
                {
                    std::cout << e.what() << '\n';
                    system("pause");
                }
                
                break;
            case '4':
                if (mode == 1){
                    kep->loadToFile(fileName); 
                }else{
                    cout << "Enter the filename: " << endl;
                    cin >> tmp;
                    kep->loadToFile(tmp);
                }
                break;
            case '0':
                return void();
            default:
                cout << "Incorecct command. Try again" << endl;
                system("pause");
                break;
        }
    }
}

void UI::StartMenu(){
    
    char choose;
    while (1){    
        system("cls");
        cout << "1 - load from file" << endl;
        cout << "2 - new DB" << endl;
        cout << "0 - exit" << endl;

        cin >> choose;
        switch (choose)
        {
        case '1':
            kep = new Keeper();

            system("cls");
            cout << "Enter filename:" << endl;
            cin >> fileName; //обработать исключение
            system("cls");
            try
            {
                kep->loadFromFile(fileName);
            }
            catch(const MyException& e)
            {
                std::cerr << e.what() << '\n';
                system("pause");
                break;
            }
            
            menu(1);
            
            delete kep;
            break;
        case '2':
            kep = new Keeper();
            menu(2);
            delete kep;
            break;
        case '0':
            return void();
        default:
            break;
        }
    }
}
