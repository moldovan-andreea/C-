//
// Created by Moldo on 23.05.2021.
//

#include "Repo.h"

Repo::Repo() {

}

Repo::~Repo() {
    this->empty();
}

vector<OperaDeArta *> Repo::getAll() {
        vector<OperaDeArta*> opereCopie;
    opereCopie.reserve(this->opere.size());
for (auto & i : this->opere)
    {
        opereCopie.push_back(i->clone());
    }
    return opereCopie;
}

int Repo::getSize() {
    return this->opere.size();
}

OperaDeArta *Repo::get(int index) {{
        if (index < 0 || index >= this->opere.size())
        {
            throw RepoException("Index invalid!");
        }
        return this->opere[index]->clone();
    }
}

int Repo::find(const string& nume) {
    for (int i = 0; i < this->opere.size();i++)
    {
        if (this->opere[i]->getNume()==nume)
        {
            return i;
        }
    }
    return -1;
}

void Repo::addOpera(OperaDeArta *a) {
    if (typeid(*a) == typeid(Sculptura))
    {
        this->validatorSculptura.validate(a);
    }
    if (typeid(*a) == typeid(Tablou))
    {
        this->validatorTablou.validate(a);
    }
    if (this->find(a->getNume()) != -1)
    {
        throw RepoException("Opera nu poate fi adaugata pt ca exista deja!\n");
    }
    this->opere.push_back(a->clone());
}

void Repo::updateOpera(OperaDeArta *vechi, OperaDeArta*nou) {
    if (typeid(*nou) == typeid(Sculptura))
    {
        this->validatorSculptura.validate(nou);
    }
    if (typeid(*nou) == typeid(Tablou))
    {
        this->validatorTablou.validate(nou);
    }

    for (int i = 0; i < this->opere.size(); i++)
    {
        if (this->opere[i]->getNume() == vechi->getNume())
        {
            delete this->opere[i];
            this->opere[i] = nou->clone();
            return;
        }
    }
    throw RepoException("Opera nu poate fi updatata pt. ca nu exista!");
}
void Repo::remove(int pos) {
    for(int i=pos; i<opere.size()-1;i++)
    {
        opere[i]=opere[i+1];
    }
    opere.pop_back();
}

void Repo::deleteOpera(const string &nume) {
    for(int i=0; i<opere.size();i++)
    {
        if(opere[i]->getNume()==nume)
        {
            this->remove(i);
            i--;
        }
    }
}

void Repo::empty()
{
    for (int i = 0; i < this->opere.size(); i++)
    {
        if (this->opere[i] != nullptr)
        {
            delete this->opere[i];
            this->opere[i] = nullptr;
        }
    }
    this->opere.clear();
}

OperaDeArta *Repo::cautare(const string& nume) {
    for (int i = 0; i < this->opere.size();i++)
    {
        if (this->opere[i]->getNume()==nume)
        {
            return opere[i];
        }
    }
    return nullptr;
}





