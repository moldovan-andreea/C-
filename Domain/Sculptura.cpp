//
// Created by Moldo on 17.05.2021.
//

#include "Sculptura.h"

Sculptura::Sculptura(): OperaDeArta() {
    this->material="";
}

Sculptura::Sculptura(string nume, int an, int dimensiune, string n) : OperaDeArta (nume,an,dimensiune){
    this->material=n;
}

Sculptura::Sculptura(const Sculptura &s):OperaDeArta(s) {
    this->material=s.material;
}

Sculptura::~Sculptura() {

}

string Sculptura::getMaterial() {
    return this->material;
}

void Sculptura::setMaterial(string m) {
    this->material=m;
}

OperaDeArta *Sculptura::clone() {
    return new Sculptura(this->getNume(),this->an,this->dimensiune,this->material);
}

Sculptura &Sculptura::operator=(const Sculptura &s) {
    if (&s != this)
    {
        OperaDeArta::operator=(s);
        this->setMaterial(s.material);
    }
    return *this;
}

bool Sculptura::operator==(const Sculptura &s) {
    return OperaDeArta:: operator==(s) && this->material==s.material;
}

string Sculptura::toString(bool forFile) {
    string result=OperaDeArta::toString()+ " "+ this->material;
    if (forFile)
    {
        result = "SCULPTURA " + result;
    }
    return result;
}

string Sculptura::toPrint() {
    return "SCULPTURA: "+OperaDeArta::toPrint()+"_______MATERIAL: "+this->material;
}






