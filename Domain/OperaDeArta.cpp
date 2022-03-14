//
// Created by Moldo on 17.05.2021.
//

#include "OperaDeArta.h"
#include "../Utils.h"

OperaDeArta::OperaDeArta() {
    this->nume="";
    this->an=0;
    this->dimensiune=0;
}

OperaDeArta::OperaDeArta(string n, int a, int d) {
    this->nume=n;
    this->an=a;
    this->dimensiune=d;
}

OperaDeArta::OperaDeArta(const OperaDeArta &o) {
    this->nume=o.nume;
    this->an=o.an;
    this->dimensiune=o.dimensiune;
}

OperaDeArta::~OperaDeArta() {

}

string OperaDeArta::getNume() {
    return this->nume;
}

void OperaDeArta::setNume(string n) {
    this-> nume=n;
}

int OperaDeArta::getAn() {
    return this->an;
}

void OperaDeArta::setAn(int a) {
    this->an=a;
}

int OperaDeArta::getDimensiune() {
    return this->dimensiune;
}

void OperaDeArta::setDimensiune(int d) {
    this->dimensiune=d;
}

OperaDeArta *OperaDeArta::clone() {
    return new OperaDeArta(this->nume,this->an,this->dimensiune);
}

OperaDeArta &OperaDeArta::operator=(const OperaDeArta &p) {if (&p != this)
    {
        this->setNume(p.nume);
        this->setAn(p.an);
        this->setDimensiune(p.dimensiune);
    }
    return *this;
}

bool OperaDeArta::operator==(const OperaDeArta &p) {
    return this->nume == p.nume && this->an == p.an && this->dimensiune == p.dimensiune ;
}

string OperaDeArta::toString(bool forFile) {
    return nume +" " +  convertIntToString(this->an)+" " +convertIntToString(this->dimensiune);
}

string OperaDeArta::toPrint() {
    return "NUME "+nume +" AN: " +  convertIntToString(this->an)+" DIMENSIUNE: " +convertIntToString(this->dimensiune);
}















