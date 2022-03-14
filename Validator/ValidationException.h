//
// Created by Moldo on 23.05.2021.
//

#ifndef PROIECTFINALOOP_VALIDATIONEXCEPTION_H
#define PROIECTFINALOOP_VALIDATIONEXCEPTION_H
#include <exception>
#include <string>
#include <utility>

using namespace std;

class ValidationException {
private:
    string message;
public:
    explicit ValidationException(string msg) : message(std::move(msg))
    {}

    string toString()
    {
        return message;
    }
};
#endif //PROIECTFINALOOP_VALIDATIONEXCEPTION_H
