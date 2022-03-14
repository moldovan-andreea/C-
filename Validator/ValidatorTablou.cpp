//
// Created by Moldo on 23.05.2021.
//

#include "ValidatorTablou.h"

ValidatorTablou::ValidatorTablou() {

}

ValidatorTablou::~ValidatorTablou() {

}

void ValidatorTablou::validate(OperaDeArta *opera) {
    string errorMessage="";
    try{
        Validator::validate(opera);
    }
    catch(ValidationException& e)
    {
        errorMessage+=e.toString();
    }

    Tablou* sc= dynamic_cast<Tablou *>((OperaDeArta *) opera);
    if(sc->getmediu().empty())
    {
        errorMessage+="Mediul nu poate fi gol! \n";
    }
    for (char c : sc->getmediu())
    {
        if (!isalpha(c))
        {
            errorMessage += "Mediul poate sa contina doar litere! \n";
            break;
        }
    }
    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
