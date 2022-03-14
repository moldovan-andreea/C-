//
// Created by Moldo on 17.05.2021.
//

#ifndef PROIECTFINALOOP_TABLOU_H
#define PROIECTFINALOOP_TABLOU_H
#include "OperaDeArta.h"
class Tablou : public OperaDeArta{
private:
    string mediu;
public:
    Tablou();
    Tablou(string nume,int an, int dimensiune,string mediu);
    Tablou(const Tablou& s);
    ~Tablou();

    string getmediu();
    void setmediu(string mediu);

    OperaDeArta* clone();

    Tablou& operator=(const Tablou& s);
    bool operator==(const Tablou& s);

    string toString(bool);
    string toPrint();

};
#endif //PROIECTFINALOOP_TABLOU_H
