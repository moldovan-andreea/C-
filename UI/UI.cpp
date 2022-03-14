//
// Created by Moldo on 23.05.2021.
//

#include "UI.h"
#include <iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
void UI::Color(int color) {
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
}
void UI::showMenu() {
    Color(15);
    cout << "1. Adaugare Tablou\n";
    cout << "2. Adaugare Sculptura\n";
    cout << "3. Stergere opera dupa nume\n";
    cout << "4. Update\n";
    cout<<"____________________________________________\n";
    cout << "5. Cautare\n";
    cout << "6. Filtru\n";
    cout << "7. Sortare\n";
    cout<<"____________________________________________\n";
    cout << "a. Afisare toate operele\n";
    cout << "x. Iesire\n";
}

void UI::printOpere(vector<OperaDeArta *> opere) {
    cout<<"\n";
    for (int i = 0; i < opere.size();i++)
    {
        if (typeid(*opere[i]) == typeid(Sculptura))
        {
            Color(1);
        }
        else
        {
            Color(5);
        }
        cout << opere[i]->toPrint();
        cout<<"\n";cout<<"\n";

    }
    cout<<"\n";
}

void UI::comenzi() {
    bool ok = true;

    while(ok) {
        showMenu();
        cout<<"Selectati optiunea:";
        char* alegere=new char[10];
        cin>>alegere;
        if(strcmp(alegere,"1")==0){
            this->uiAddTablou();
        }
        else if(strcmp(alegere,"2")==0){
            this->uiAddSculptura();
        }
        else if(strcmp(alegere,"3")==0){
            this->uiStergere();
        }
        else if(strcmp(alegere,"4")==0){
            this->uiUpdate();
        }
        else if(strcmp(alegere,"5")==0){
            this->uiCautare();
        }
        else if(strcmp(alegere,"6")==0){
            this->uiFiltru();
        }
        else if(strcmp(alegere,"7")==0){
            this->uiSortare();
        }
        else if(strcmp(alegere,"a")==0){
            this->printOpere(service.getAll());
        }

        else if(strcmp(alegere,"x")==0){
            ok = false;
            cout<<"Byeeeeeeeeeeeeeee";

        }
        else{
            cout<<"Optiunea invalida! Reincercati!\n";
        }
        delete [] alegere;

    }

}

void UI::uiAddTablou() {

    cout<<"Dati numele:";
    string nume;
    cin>>nume;

    cout<<"Dati anul:";
    int an;
    cin>>an;

    cout<<"Dati dimensiunea:";
    int dim;
    cin>>dim;

    cout<<"Dati mediul in care a fost realizat tabloul:";
    string mediu;
    cin>>mediu;

    Tablou* t=new Tablou(nume,an,dim,mediu);
    try
    {
        this->service.addTablou(t);
    }
    catch (RepoException& e)
    {
        Color(12);
        cout << e.what() << endl;
    }
    catch (ValidationException& e)
    {
        Color(12);
        cout << e.toString() << endl;
    }

}
void UI::uiAddSculptura() {

    cout<<"Dati numele:";
    string nume;
    cin>>nume;

    cout<<"Dati anul:";
    int an;
    cin>>an;
    cin.ignore();

    cout<<"Dati dimensiunea:";
    int dim;
    cin>>dim;
    cin.ignore();

    cout<<"Dati materialul in care a fost realizata sculptura:";
    string material;
    cin>>material;
    try
    {
        this->service.addSculptura(nume, an, dim,material);
    }
    catch (RepoException& e)
    {
        Color(12);
        cout << e.what() << endl;
    }
    catch (ValidationException& e)
    {
        Color(12);
        cout << e.toString() << endl;
    }

}

UI::UI(Service &s ) {
    this->service=s;
}

void UI::uiStergere() {
    string nume;
    cout<<"Dati numele dupa care sa se faca stergerea";
    cin>>nume;

    service.deleteOpera(nume);
}

void UI::uiUpdate() {
    cout << "Dati numele vechii opere: ";
    string numeVechi;
    cin>>numeVechi;
    int option;
    do {
        cout << "Ce fel de opera se adauga? 1. Tablou 2. Sculptura \n";
        cin >> option;
    } while (option < 1 || option > 2);
    cout << "Dati numele nou: ";
    string numeNou;
    cin>>numeNou;

    int an;
    cout << "Dati anul nou: ";
    cin >> an;

    int dimensiune;
    cout<<"Dati noua dimensiune";
    cin>>dimensiune;

    if (option == 1) {
        string mediu;
        cout << "Dati noul mediu: ";
        cin>>mediu;
        try {
            this->service.updateTablou(numeVechi, numeNou,an ,dimensiune, mediu);
        }
        catch (ValidationException& e) {
            Color(12);
            cout << e.toString() << endl;
        }
        catch (RepoException& e) {
            Color(12);
            cout << e.what() << endl;
        }
    }
    else {
        string material;
        cout << "Dati noul material: ";
        cin >> material;
        try {
            this->service.updateSculptura(numeVechi,numeNou,an,dimensiune,material);
        }
        catch (ValidationException& e) {
            Color(12);
            cout << e.toString() << endl;
        }
        catch (RepoException& e) {
            Color(12);
            cout << e.what() << endl;
        }
    }
}

void UI::uiCautare() {
    string nume;
    cout << "Dati numele de cautat:";
    cin >> nume;
    if(this->service.cautareService(nume)!= nullptr) {
        if (typeid(*this->service.cautareService(nume)) == typeid(Sculptura))
        {
            Color(1);
        }
        else
        {
            Color(5);
        }
        cout<<"\n";
        cout << this->service.cautareService(nume)->toPrint() << "\n";
    }
    else { Color(12);cout<<"\n"<<"Nu exista Opera cautata :(("<<"\n";}
}

void UI::uiFiltru() {
    int lowerBound, upperBound;
    cout << "Dati limita inferioara: ";
    cin >> lowerBound;
    do {
        cout << "Dati limita superioara: ";
        cin >> upperBound;
    } while (upperBound < lowerBound);
    this->printOpere(this->service.filtruDupaDimensiune(lowerBound, upperBound));
}

void UI::uiSortare() {
    this->printOpere(this->service.sortDupaAn());
}




