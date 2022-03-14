//
// Created by Moldo on 20.05.2021.
//

#ifndef PROIECTFINALOOP_TESTREPO_H
#define PROIECTFINALOOP_TESTREPO_H

#include "../Domain/OperaDeArta.h"
#include <vector>
#include "../Repository/Repo.h"
using namespace std;

class TestRepo {
private:
    vector<OperaDeArta*> produse;

public:
    TestRepo()=default;
    ~TestRepo()=default;
    void testAddProdus();
};



#endif //PROIECTFINALOOP_TESTREPO_H
