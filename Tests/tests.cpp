//
// Created by Moldo on 17.05.2021.
//

#include "tests.h"
#include <iostream>
#include "../Domain/OperaDeArta.h"
#include "../Domain/Sculptura.h"
#include "../Domain/Tablou.h"
#include <cassert>
using namespace std;

void testOperaDeArta() {
    OperaDeArta opera1;
    assert(opera1.getNume()=="");
    assert(opera1.getAn()==0);
    assert(opera1.getDimensiune()==0);

    OperaDeArta opera2("Starry Night",1879,7);
    assert(opera2.getNume()=="Starry Night");
    assert(opera2.getAn()==1879);
    assert(opera2.getDimensiune()==7);

    OperaDeArta opera3= opera2;
    assert(opera3.getNume()=="Starry Night");
    assert(opera3.getAn()==1879);
    assert(opera3.getDimensiune()==7);

    OperaDeArta opera4(opera2);
    assert(opera4.getNume()=="Starry Night");
    assert(opera4.getAn()==1879);
    assert(opera4.getDimensiune()==7);
    assert(opera2==opera4);

    OperaDeArta* op1;
    op1=new OperaDeArta();
    assert(op1->getNume()=="");
    assert(op1->getDimensiune()==0);
    assert(op1->getAn()==0);

    OperaDeArta* op2;
    op2=new OperaDeArta("Nighthawks by Edward Hopper",1942,30);
    assert(op2->getNume()=="Nighthawks by Edward Hopper");
    assert(op2->getDimensiune()==30);
    assert(op2->getAn()==1942);

    if (op2 != NULL){
        delete op2; //destructor
        op2 = NULL;
    }
    if (op1 != NULL){
        delete op1;//destructor
        op1 = NULL;}

}

void testSculptura()
{
    Sculptura opera1;
    assert(opera1.getNume()=="");
    assert(opera1.getAn()==0);
    assert(opera1.getDimensiune()==0);
    assert(opera1.getMaterial()=="");

    Sculptura opera2("Starry Night",1879,7,"piatra");
    assert(opera2.getNume()=="Starry Night");
    assert(opera2.getAn()==1879);
    assert(opera2.getDimensiune()==7);
    assert(opera2.getMaterial()=="piatra");

    Sculptura opera3= opera2;
    assert(opera3.getNume()=="Starry Night");
    assert(opera3.getAn()==1879);
    assert(opera3.getDimensiune()==7);
    assert(opera3.getMaterial()=="piatra");

    Sculptura opera4(opera2);
    assert(opera4.getNume()=="Starry Night");
    assert(opera4.getAn()==1879);
    assert(opera4.getDimensiune()==7);
    assert(opera4.getMaterial()=="piatra");
    assert(opera2==opera4);

    Sculptura* op1;
    op1=new Sculptura();
    assert(op1->getNume()=="");
    assert(op1->getDimensiune()==0);
    assert(op1->getAn()==0);
    assert(op1->getMaterial()=="");

    Sculptura* op2;
    op2=new Sculptura("Nighthawks by Edward Hopper",1942,30,"lemn");
    assert(op2->getNume()=="Nighthawks by Edward Hopper");
    assert(op2->getDimensiune()==30);
    assert(op2->getAn()==1942);
    assert(op2->getMaterial()=="lemn");

    if (op2 != NULL){
        delete op2; //destructor
        op2 = NULL;
    }
    if (op1 != NULL){
        delete op1;//destructor
        op1 = NULL;}
}
void testTablou()
{
    Tablou opera1;
    assert(opera1.getNume()=="");
    assert(opera1.getAn()==0);
    assert(opera1.getDimensiune()==0);
    assert(opera1.getmediu()=="");

    Tablou opera2("Starry Night",1879,7,"piatra");
    assert(opera2.getNume()=="Starry Night");
    assert(opera2.getAn()==1879);
    assert(opera2.getDimensiune()==7);
    assert(opera2.getmediu()=="piatra");

    Tablou opera3= opera2;
    assert(opera3.getNume()=="Starry Night");
    assert(opera3.getAn()==1879);
    assert(opera3.getDimensiune()==7);
    assert(opera3.getmediu()=="piatra");

    Tablou opera4(opera2);
    assert(opera4.getNume()=="Starry Night");
    assert(opera4.getAn()==1879);
    assert(opera4.getDimensiune()==7);
    assert(opera4.getmediu()=="piatra");
    assert(opera2==opera4);

    Tablou* op1;
    op1=new Tablou();
    assert(op1->getNume()=="");
    assert(op1->getDimensiune()==0);
    assert(op1->getAn()==0);
    assert(op1->getmediu()=="");

    Tablou* op2;
    op2=new Tablou("Nighthawks by Edward Hopper",1942,30,"lemn");
    assert(op2->getNume()=="Nighthawks by Edward Hopper");
    assert(op2->getDimensiune()==30);
    assert(op2->getAn()==1942);
    assert(op2->getmediu()=="lemn");

    if (op2 != NULL){
        delete op2; //destructor
        op2 = NULL;
    }
    if (op1 != NULL){
        delete op1;//destructor
        op1 = NULL;}
}

void allTests() {
    testOperaDeArta();
    testSculptura();
    testTablou();

}