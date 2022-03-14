//
// Created by Moldo on 23.05.2021.
//

#ifndef PROIECTFINALOOP_VALIDATORSCULPTURA_H
#define PROIECTFINALOOP_VALIDATORSCULPTURA_H
#include "Validator.h"
#include "../Domain/Sculptura.h"

class ValidatorSculptura: public Validator{

public:
    ValidatorSculptura();
    ~ValidatorSculptura();
    void validate(OperaDeArta* opera);
};
#endif //PROIECTFINALOOP_VALIDATORSCULPTURA_H
