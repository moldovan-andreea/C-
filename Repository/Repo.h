//
// Created by Moldo on 23.05.2021.
//

#ifndef PROIECTFINALOOP_REPO_H
#define PROIECTFINALOOP_REPO_H
#include <vector>
#include "../Domain/OperaDeArta.h"
#include "../Domain/Sculptura.h"
#include "../Domain/Tablou.h"
#include "../Validator/Validator.h"
#include "../Validator/ValidatorTablou.h"
#include "../Validator/ValidatorSculptura.h"
#include "../Exceptions/RepoException.h"


class Repo{
protected:
    vector<OperaDeArta*> opere;
    ValidatorTablou validatorTablou;
    ValidatorSculptura validatorSculptura;
public:
    Repo();
    ~Repo();

    vector<OperaDeArta*> getAll();
    int getSize();
    OperaDeArta* get(int index);
    int find(const string& nume);
    void remove(int pos);

    virtual void addOpera(OperaDeArta* a);
    virtual void updateOpera(OperaDeArta* vechi,OperaDeArta*nou);
    virtual void deleteOpera(const string& nume);

    OperaDeArta* cautare(const string& nume);

    void empty();

};
#endif //PROIECTFINALOOP_REPO_H
