#include <iostream>
#include "Tests/tests.h"
#include "Repository/Repo.h"
#include "Service/Service.h"
#include "UI/UI.h"
#include "Tests/TestRepo.h"
#include "Repository/RepoFile.h"
#include<iostream>
using namespace std;

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors





int main() {
    TestRepo t;
    t.testAddProdus();
    allTests();
    RepoFile* r=new RepoFile("C:\\Users\\Moldo\\OneDrive\\Desktop\\ProiectFinalOOP\\Fisiere\\Opere.txt");
    Service s(r);
    UI u(s);
    u.comenzi();
}
