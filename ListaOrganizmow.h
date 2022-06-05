//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_LISTAORGANIZMOW_H
#define PROJEKT1_LISTAORGANIZMOW_H

#include "Organizm.h"
#include <iostream>

class Organizm;

typedef struct foo
{
    Organizm* organizm;
    foo* nastepny;
}Element;

class ListaOrganizmow
{
private:
    struct INFO
    {
        Element* glowa;
        Element* ogon;
    };
    INFO info;
    int dlu;
public:
    Element* pierwszyElement();
    ListaOrganizmow();
    int dlugosc();
    void dodaj(Organizm &org);
    void usun(std::size_t index);
    void usun(Organizm* org);
    Organizm* organizmNaIndeksie (int index);
    Element& operator[](int index);
    const Element& operator[](int index) const;
    ~ListaOrganizmow();
};


#endif //PROJEKT1_LISTAORGANIZMOW_H
