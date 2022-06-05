//
// Created by Kacper Chodubski on 15/04/2022.
//

#include "Trawa.h"


Trawa::Trawa(Swiat* swiat, int y, int x)
{
    this->swiat = swiat;
    this->sila = BAZOWA_SILA_ROSLIN;
    this->poz.y = y;
    this->poz.x = x;
    this->zywy = true;
    this->rogny = true;
    this->tekstura = TRAWA_TEKSTURA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->szybkoscUmyslu = SZYBKOSC_UMYSLU_ROSLIN;
    this->gatunek = TRAWA_GATUNEK;
    this->typ = TYP_ROSLINA;

}

void Trawa::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Trawa* potomek = new Trawa(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    potomek->rogny = false;
    this->swiat->dodajOrganizm(*potomek);
}

Trawa::~Trawa()
{

}