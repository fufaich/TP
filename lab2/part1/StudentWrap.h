#pragma once
#include "Student.h"
#include <sstream>

class StudentV2 : public Student {
    private:
        double sredBall;
    public:
        StudentV2():Student(){
            #ifdef DEBUG
                std::cout << "Constructor StudentV2" << std::endl;
            #endif
            
        };

        StudentV2(std::string str):Student(){
            #ifdef DEBUG
                std::cout << "Constructor StudentV2" << std::endl;
            #endif
            string n;
            string f;
            string o;
            
            int prog[5];
            istringstream iss(str);
            iss >> f >> n >> o >> prog[0]>> prog[1] >> prog[2] >> prog[3] >>prog[4];
            
            setFio(f,n,o);
            setProgress(prog);
            calculateSredBall(); 
        };

        void setOcenki(int* listValues){
            setProgress(listValues);
            calculateSredBall();
        }

        ~StudentV2(){
            #ifdef DEBUG
                std::cout << "Destructor StudentV2" << std::endl;
            #endif
        }

        double getSredBall()const{
            return sredBall;
        }

        void calculateSredBall(){
            sredBall = 0;
            
            for (size_t i = 0; i < 5; i++)
            {
                sredBall += progress[i];;
            }

            sredBall /= 5;
        };

        void setUnit(){
            string f;
            string n;
            string o;
            int prog[5];
            int idGroup;
            cout << "Name: "; cin >> n;
            cout << "Familia: "; cin >> f;
            cout << "Otchestvo: "; cin >> o;
            cout << "Group: "; cin >> idGroup;
            cout << "Math: "; cin >> prog[0];
            cout << "TP: "; cin >> prog[1];
            cout << "KG: "; cin >> prog[2];
            cout << "Philosofia: "; cin >> prog[3];
            cout << "English: "; cin >>prog[4] ;

            setFio(f,n,o);
            setIdGroup(idGroup);
            setProgress(prog);
            calculateSredBall();
        }
        void PrintDetails(std::ostream& os) const{
            os << getFio() << " ";
             os << getIdGroup() << " ";
            os  << progress[0] << " ";
            os << progress[1] << " "; 
            os << progress[2] << " "; 
            os << progress[3] << " "; 
            os << progress[4] << " ";
            

        }
        void ReadDetails(istream& is){
            string f;
            string n;
            string o;
            int prog[5];
            int idGroup;
            is >> f >> n >> o >>idGroup>> prog[0] >> prog[1] >> prog[2] >> prog[3]>> prog[4];
            this->setFio(f,n,o);
            this->setIdGroup(idGroup);
            this->setOcenki(prog);
        }


        bool operator>(const StudentV2& other) const {
        return sredBall > other.sredBall;
        }

        bool operator<(const StudentV2& other) const {
        return sredBall < other.sredBall;
        }

        bool operator>=(const StudentV2& other) const {
        return sredBall >= other.sredBall;
        }

        bool operator<=(const StudentV2& other) const {
        return sredBall <= other.sredBall;
        }


};
