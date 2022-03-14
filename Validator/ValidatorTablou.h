//
// Created by Moldo on 23.05.2021.
//

#ifndef PROIECTFINALOOP_VALIDATORTABLOU_H
#define PROIECTFINALOOP_VALIDATORTABLOU_H
#include "Validator.h"
#include "../Domain/Tablou.h"


class ValidatorTablou: public Validator{
public:
    ValidatorTablou();
    ~ValidatorTablou();
    void validate(OperaDeArta* opera);
};
#endif //PROIECTFINALOOP_VALIDATORTABLOU_H
