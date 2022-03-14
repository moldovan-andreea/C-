//
// Created by Moldo on 17.05.2021.
//

#include "Tablou.h"

Tablou::Tablou(): OperaDeArta() {
    this->mediu="";
}

Tablou::Tablou(string nume, int an, int dimensiune, string n) : OperaDeArta (nume,an,dimensiune){
    this->mediu=n;
}

Tablou::Tablou(const Tablou &s):OperaDeArta(s) {
    this->mediu=s.mediu;
}

Tablou::~Tablou() {

}

string Tablou::getmediu() {
    return this->mediu;
}

void Tablou::setmediu(string m) {
    this->mediu=m;
}

OperaDeArta *Tablou::clone() {
    return new Tablou(this->getNume(),this->an,this->dimensiune,this->mediu);
}

Tablou &Tablou::operator=(const Tablou &s) {
    if (&s != this)
    {
        OperaDeArta::operator=(s);
        this->setmediu(s.mediu);
    }
    return *this;
}

bool Tablou::operator==(const Tablou &s) {
    return OperaDeArta:: operator==(s) && this->mediu==s.mediu;
}

string Tablou::toString(bool forFile) {
    string result=OperaDeArta::toString()+ " " + this->mediu;
    if (forFile)
    {
        result = "TABLOU " + result;
    }
    return result;
}

string Tablou::toPrint() {
    return "TABLOU: "+OperaDeArta::toPrint()+ "_______MEDIU: "+this->mediu;
}
