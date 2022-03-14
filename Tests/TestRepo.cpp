//
// Created by Moldo on 20.05.2021.
//

#include "TestRepo.h"
#include "../Service/Service.h"
#include <cassert>


void TestRepo::testAddProdus() {
Repo *repo=new Repo;
Service service(repo);

Tablou* pd = new Tablou("briosa", 6,6,"a");
service.addTablou(pd);
assert(service.getAll().size()==1);

}
