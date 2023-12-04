#include "Menu.h"


Menu::Menu(){
    
}

void Menu::start(){
    kep = new Keeper;
    startMenu();
    delete kep;
}

void Menu::startMenu(){
    int pos;
    char choose;
    while (1)
    {
        system("cls");
        std::cout << "Select command\n";
        std::cout << "1 - Add Element\n";
        std::cout << "2 - Delete Element\n";
        std::cout << "3 - Change Element\n";
        std::cout << "4 - Display\n";
        std::cout << "5 - Save to file\n";
        std::cout << "6 - Extract from file\n";
        std::cout << "7 - Print Genius\n";
        std::cout << "8 - Sort\n";

        std::cout << "0 - Exit\n";
        cin >> choose;
        switch (choose)
        {
        case '1':
            menuAdd();
            break;
        case '2':
            menuDelete();
            break;
        case '3':
            menuEdit();
            break;
        case '4':
            //kep->sort();
            kep->printToConsole();
            system("pause");
            break;
        case '5':
            system("cls");
            cout << "Enter filename:" << endl;
            cin >> filename; //обработать исключение
            system("cls");
            try
            {
                kep->loadToFile(filename);
            }
            catch(const MyException& e)
            {
                std::cerr << e.what() << '\n';
                system("pause");
            }
            break;
        case '6':
            system("cls");
            cout << "Enter filename:" << endl;
            cin >> filename; //обработать исключение
            system("cls");
           try
            {
                kep->loadFromFile(filename);
            }
            catch(const MyException& e)
            {
                std::cerr << e.what() << '\n';
                system("pause");
            }
            
            break;
        case '7':
            kep->sort();
            kep->printToConsoleGenius();
            system("pause");
            break;
        case '8':
            kep->sort();
            break;
        case '0':
            return void();
        default:
            std::cout << "Incorrect command. Try again." << std::endl;
            cin.clear();
            system("pause");
            break;
        }
    }
}

void Menu::menuAdd(){
    char choose;
    StudentV2 *element = new StudentV2();
    system("cls");
    element->setUnit();
 
    kep->add(element);
    system("pause");
}

void Menu::menuDelete(){
    system("cls");
    int pos;
    
    std::cout << "Enter the pos:";
    std::cin >> pos; 
    kep->deleteUnit(pos);
}

void Menu::menuEdit(){
    system("cls");
    int pos;
    std::cout << "Enter the pos:";
    std::cin >> pos;
    try
    {
         kep->changeUnit(pos);
    }
    catch(const MyException& e)
    {
        std::cerr << e.what() << '\n';
    };
    
   
 
}

