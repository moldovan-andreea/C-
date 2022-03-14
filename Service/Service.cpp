//
// Created by Moldo on 23.05.2021.
//

#include "Service.h"
#include <algorithm>
Service::Service() {

}

Service::Service(Repo* r) {
    this->repo=r;
}

Service::~Service() {

}

vector<OperaDeArta *> Service::getAll() {
    return this->repo->getAll();
}

void Service::addTablou(Tablou* tablou) {
    this->repo->addOpera(tablou);

}

void Service::addSculptura(string nume, int an, int dimensiune, string material) {
    Sculptura*sculptura=new Sculptura(nume,an,dimensiune,material);
    this->repo->addOpera(sculptura);
}

void Service::deleteOpera(string nume) {
    this->repo->deleteOpera(nume);

}

void Service::updateTablou(string numeVechi, string numeNou, int anNou, int dimensiuneNou, string mediuNou) {
    OperaDeArta* veche=new OperaDeArta(numeVechi,0,0);
    Tablou* nou = new Tablou(numeNou,  anNou,  dimensiuneNou,  mediuNou);
    this->repo->updateOpera(veche,nou);

}

void Service::updateSculptura(string numeVechi, string numeNou, int anNou, int dimensiuneNou, string materialNou) {
    OperaDeArta* veche=new OperaDeArta(numeVechi,0,0);
    Sculptura* nou = new Sculptura(numeNou,  anNou,  dimensiuneNou,  materialNou);
    this->repo->updateOpera(veche,nou);
}

OperaDeArta* Service::cautareService(string nume) {
    return repo->cautare(nume);
}

vector<OperaDeArta *> Service::filtruDupaDimensiune(int min, int max) {
    vector<OperaDeArta*> opere = this->repo->getAll();
    vector<OperaDeArta*> result;
    for (OperaDeArta* p : opere)
    {
        if (p->getDimensiune() >= min && p->getDimensiune() <= max)
        {
            result.push_back(p->clone());
        }
    }
    return result;
}
bool compareByAn(OperaDeArta *p1, OperaDeArta *p2) {
    return p1->getAn()>p2->getAn();
}

vector<OperaDeArta *> Service::sortDupaAn() {
    vector<OperaDeArta*> opere = this->repo->getAll();
    sort(opere.begin(), opere.end(), compareByAn);
    return opere;
}


