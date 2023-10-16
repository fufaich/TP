#include "ui.h"
using namespace std;

UI::UI(){
    menu();
}

UI::~UI(){
}


void UI::menu(){
    char choose;
    Keeper kep;
    while (1)
    {
        cout << "1 - load from file" << endl;
        cout << "2 - create new\nChoose: " << endl;
        cin >> choose;
        system("cls");
        switch (choose)
        {
        case '1':
            cout<< "Enter the filename" << endl;
            cin >> fileName;
            kep.loadFromFile(fileName); //TODO Обработать ошибку ненайденого файла
            cout << "File: " << fileName << endl;
            system("cls");
            
            break;
        case '2':
            /* code */
            break;
        case '0':
            return void();
        default:
            cout << "Incorrect comand. Please try again." << endl;
            break;
        }
    }
    
}
