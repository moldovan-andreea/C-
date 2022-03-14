//
// Created by Moldo on 24.05.2021.
//

#ifndef PROIECTFINALOOP_REPOFILE_H
#define PROIECTFINALOOP_REPOFILE_H

#include "Repo.h"

class RepoFile : public Repo {
private:
    string fileName;
public:
    RepoFile(string fileName);
    ~RepoFile()=default;

    void setFileName(string fileName);

    void addOpera(OperaDeArta* opera);
    void updateOpera(OperaDeArta* vechi, OperaDeArta* nou);
    void deleteOpera(const string& nume);

    void loadFromFile();
    void saveToFile();



};
#endif //PROIECTFINALOOP_REPOFILE_H
