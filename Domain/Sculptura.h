//
// Created by Moldo on 17.05.2021.
//

#ifndef PROIECTFINALOOP_SCULPTURA_H
#define PROIECTFINALOOP_SCULPTURA_H
#include "OperaDeArta.h"

class Sculptura : public OperaDeArta{
private:
    string material;
public:
    Sculptura();
    Sculptura(string nume,int an, int dimensiune,string material);
    Sculptura(const Sculptura& s);
    ~Sculptura();

    string getMaterial();
    void setMaterial(string material);

    OperaDeArta* clone();

    Sculptura& operator=(const Sculptura& s);
    bool operator==(const Sculptura& s);

    string toString(bool);
    string toPrint();

};
#endif //PROIECTFINALOOP_SCULPTURA_H
