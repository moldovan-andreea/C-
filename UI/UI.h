//
// Created by Moldo on 23.05.2021.
//
#ifndef PROIECTFINALOOP_UI_H
#define PROIECTFINALOOP_UI_H
#include "../Service/Service.h"
class UI {
private:
    Service service;
    void showMenu();
    void printOpere(vector<OperaDeArta*> opere);

    void uiAddTablou();
    void uiAddSculptura();
    void uiStergere();
    void uiUpdate();

    void uiCautare();
    void uiFiltru();
    void uiSortare();

    void Color(int color);

public:
    UI()=default;
    UI(Service &s);
    ~UI()=default;

    void comenzi();

};


#endif //PROIECTFINALOOP_UI_H
