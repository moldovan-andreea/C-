//
// Created by Moldo on 23.05.2021.
//

#ifndef PROIECTFINALOOP_VALIDATOR_H
#define PROIECTFINALOOP_VALIDATOR_H

#include "../Domain/OperaDeArta.h"
#include "ValidationException.h"
class Validator{
public:
    Validator();
    ~Validator();

    virtual void validate(OperaDeArta* opera);
};
#endif //PROIECTFINALOOP_VALIDATOR_H
