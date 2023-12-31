#pragma once
#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception{
    private:
        string msg;
    public:
        MyException(const char* message) : msg(message){};
        char const* what() const noexcept{
            return msg.c_str();
        }
};