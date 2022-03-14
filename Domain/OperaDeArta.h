//
// Created by Moldo on 17.05.2021.
//

#ifndef PROIECTFINALOOP_OPERADEARTA_H
#define PROIECTFINALOOP_OPERADEARTA_H
#include <iostream>
#include<string>
#include <cstring>
using namespace std;

class OperaDeArta{
protected:
    string nume; ///unic
    int an; ///strict pozitiv
    int dimensiune; ///strict pozitiv
public:
    OperaDeArta();
    OperaDeArta(string nume,int an,int dimensiune);
    OperaDeArta(const OperaDeArta&o);
    virtual ~OperaDeArta();

    string getNume();
    void setNume(string nume);

    int getAn();
    void setAn(int an);

    int getDimensiune();
    void setDimensiune(int dimensiune);

    virtual OperaDeArta* clone();

    OperaDeArta& operator=(const OperaDeArta& o);
    bool operator==(const OperaDeArta& o);

    virtual string toString(bool ff=false);
    virtual string toPrint();
};
#endif //PROIECTFINALOOP_OPERADEARTA_H
