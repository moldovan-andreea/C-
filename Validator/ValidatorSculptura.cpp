//
// Created by Moldo on 23.05.2021.
//

#include "ValidatorSculptura.h"

ValidatorSculptura::ValidatorSculptura() {

}

ValidatorSculptura::~ValidatorSculptura() {

}

void ValidatorSculptura::validate(OperaDeArta *opera) {
    string errorMessage="";
    try{
        Validator::validate(opera);
    }
    catch(ValidationException& e)
    {
        errorMessage+=e.toString();
    }

    Sculptura* sc= dynamic_cast<Sculptura *>((OperaDeArta *) opera);
    if(sc->getMaterial().empty())
    {
        errorMessage+="Materialul nu poate fi gol! \n";
    }
    for (char c : sc->getMaterial())
    {
        if (!isalpha(c))
        {
            errorMessage += "Materialul poate sa contina doar litere! \n";
            break;
        }
    }
    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
