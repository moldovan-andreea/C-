//
// Created by Moldo on 23.05.2021.
//

#ifndef PROIECTFINALOOP_SERVICE_H
#define PROIECTFINALOOP_SERVICE_H

#include "../Repository/Repo.h"

class Service {
private:
    Repo* repo;
public:
    Service();
    Service(Repo* repo);
    ~Service();

    vector<OperaDeArta*> getAll();

    void addTablou(Tablou* tablou);
    void addSculptura(string nume, int an, int dimensiune, string material);
    void deleteOpera(string nume);
    void updateTablou(string numeVechi,string numeNou, int anNou, int dimensiuneNou, string mediuNou);
    void updateSculptura(string numeVechi,string numeNou, int anNou, int dimensiuneNou, string materialNou);


    OperaDeArta* cautareService(string nume);
    vector<OperaDeArta*> filtruDupaDimensiune(int min, int max);
    vector<OperaDeArta*> sortDupaAn();
};
bool compareByAn(OperaDeArta* p1, OperaDeArta* p2);


#endif //PROIECTFINALOOP_SERVICE_H
