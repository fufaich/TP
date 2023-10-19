#include "ui.h"
using namespace std;

UI::UI(Keeper* kep){
    StartMenu(kep);
}

UI::~UI(){
}

void UI::menu(Keeper* kep){
    char choose;
    
    while(1){
        system("cls");
        cout << "1 - print data" << endl;
        cout << "2 - add unit" << endl;
        cout << "3 - delete unit" << endl;
        cout << "4 - edit unit" << endl;
        cout << "5 - save to file" << endl;
        cout << "0 - exit" << endl;
        cin >> choose;
        switch (choose)
        {
            case '1':
                kep->printToConsole();
                system("pause");
                break;
            case '2':
                /* code */
                break;
            case '3':
                /* code */
                break;
            case '4':
                /* code */
                break;
            case '5':
                /* code */
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

void UI::StartMenu(Keeper* kep){
    char choose;
    cout << "1 - load from file" << endl;
    cout << "2 - new DB" << endl;
    cin >> choose;
    switch (choose)
    {
    case '1':
        system("cls");
        cout << "Enter filename:" << endl;
        cin >> fileName; //обработать исключение
        system("cls");
        kep->loadFromFile(fileName);
        menu(kep);
        break;
    case '2':
        menu(kep);
        break;
    
    default:
        break;
    }
    
}
