//
// Created by Moldo on 23.05.2021.
//

#include "Validator.h"
#include <string>


Validator::Validator() {

}

Validator::~Validator() {

}

void Validator::validate(OperaDeArta *opera){
    string errorMessage;

    if(opera->getNume().empty()){
        errorMessage+="Numele Operei nu poate fi nul!\n";
    }
    for (char c : opera->getNume())
    {
        if (!isalpha(c))
        {
            errorMessage += "Numele operei poate sa contina doar litere! \n";
            break;
        }
    }
    if(opera->getAn()<=0)
    {
        errorMessage+="Anul poate fi doar strict pozitiv!\n";

    }
    if(opera->getDimensiune()<=0)
    {
        errorMessage+="Dimensiunea poate fi doar strict pozitiva!\n";
    }
    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }

}
