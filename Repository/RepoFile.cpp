//
// Created by Moldo on 24.05.2021.
//

#include "RepoFile.h"
#include "../Exceptions/ReadFromFileException.h"
#include <fstream>


RepoFile::RepoFile(string fn) {
    fileName = fn;
    ifstream f(fn);
    while (!f.eof()) {
        string nume, delim, mediu, linie;
        int an, dim;
        delim=" ";
        while (getline(f, linie)){
         if(linie.substr(0, 6)=="TABLOU"){
                        linie = linie.erase(0, 7);

                        int pos = linie.find(delim);

                        string nume = linie.substr(0, pos);
                        linie = linie.erase(0, pos + 1);

                        pos = linie.find(delim);
                        an=stoi(linie.substr(0, pos));
                        linie = linie.erase(0, pos + 1);

                        pos = linie.find(delim);
                        dim=stoi(linie.substr(0, pos));

                        linie = linie.erase(0, pos + 1);

                        pos = linie.find(delim);
                        linie = linie.erase(0, pos + 1);

                        string mediu = linie;
                        linie = linie.erase(0, pos + 1);

                        Tablou* e=new Tablou(nume,an,dim,mediu);
                        this->validatorTablou.validate(e);
                        opere.push_back(e);
         }

         else if(linie.substr(0, 9)=="SCULPTURA"){
             linie = linie.erase(0, 10);

             int pos = linie.find(delim);

             string nume = linie.substr(0, pos);
             linie = linie.erase(0, pos + 1);

             pos = linie.find(delim);
             an=stoi(linie.substr(0, pos));
             linie = linie.erase(0, pos + 1);

             pos = linie.find(delim);
             dim=stoi(linie.substr(0, pos));

             linie = linie.erase(0, pos + 1);

             pos = linie.find(delim);
             linie = linie.erase(0, pos + 1);

             string mediu = linie;
             linie = linie.erase(0, pos + 1);

             Sculptura* e=new Sculptura(nume,an,dim,mediu);
             this->validatorSculptura.validate(e);
             opere.push_back(e);}

        }
    }f.close();}


void RepoFile::setFileName(string fn) {
    fileName=fn;
}

void RepoFile::addOpera(OperaDeArta *opera) {
Repo::addOpera(opera);
this->saveToFile();
}

void RepoFile::updateOpera(OperaDeArta *vechi, OperaDeArta *nou) {
    Repo::updateOpera(vechi,nou);
    this->saveToFile();
}

void RepoFile::deleteOpera(const string& nume) {
    Repo::deleteOpera(nume);
    this->saveToFile();
}
//
//void RepoFile::loadFromFile()
//    {
//
//        ifstream f(fileName);
//        while (!f.eof()) {
//            string nume, delim, mediu, linie;
//            int an, dim;
//            delim=" ";
//            try
//                {
//                    while (getline(f, linie)) {
//                        if (linie.substr(0, 6) == "TABLOU") {
//                            linie = linie.erase(0, 7);
//
//                            int pos = linie.find(delim);
//
//                            string nume = linie.substr(0, pos);
//                            linie = linie.erase(0, pos + 1);
//
//                            pos = linie.find(delim);
//                            an = stoi(linie.substr(0, pos));
//                            linie = linie.erase(0, pos + 1);
//
//                            pos = linie.find(delim);
//                            dim = stoi(linie.substr(0, pos));
//
//                            linie = linie.erase(0, pos + 1);
//
//                            pos = linie.find(delim);
//                            linie = linie.erase(0, pos + 1);
//
//                            string mediu = linie;
//                            linie = linie.erase(0, pos + 1);
//
//                            Tablou *e = new Tablou(nume, an, dim, mediu);
//                            this->validatorTablou.validate(e);
//                            opere.push_back(e);
//                        } else if (linie.substr(0, 6) == "SCULPTURA") {
//                            linie = linie.erase(0, 9);
//
//                            int pos = linie.find(delim);
//
//                            string nume = linie.substr(0, pos);
//                            linie = linie.erase(0, pos + 1);
//
//                            pos = linie.find(delim);
//                            an = stoi(linie.substr(0, pos));
//                            linie = linie.erase(0, pos + 1);
//
//                            pos = linie.find(delim);
//                            dim = stoi(linie.substr(0, pos));
//
//                            linie = linie.erase(0, pos + 1);
//
//                            pos = linie.find(delim);
//                            linie = linie.erase(0, pos + 1);
//
//                            string mediu = linie;
//                            linie = linie.erase(0, pos + 1);
//
//                            Sculptura *e = new Sculptura(nume, an, dim, mediu);
//                            this->validatorSculptura.validate(e);
//                            opere.push_back(e);
//                        }
//
//                    }
//                }
//            catch (...)
//            {
//                throw ReadFromFileException("formatul datelor din fisier este invalid!");
//            }
//            f.close();
//
//
//    }
//    }

void RepoFile::saveToFile() {
    ofstream f(this->fileName);
    if (f.is_open())
    {
        for (OperaDeArta* opera : this->opere)
        {
            f << opera->toString(true) << endl;
        }
    }
}



