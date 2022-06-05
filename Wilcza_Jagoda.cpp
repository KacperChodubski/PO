//
// Created by Kacper Chodubski on 16/04/2022.
//

#include "Wilcza_Jagoda.h"


Wilcza_Jagoda::Wilcza_Jagoda(Swiat* swiat, int y, int x)
{
    this->swiat = swiat;
    this->sila = WILCZA_JAGODA_SILA;
    this->poz.y = y;
    this->poz.x = x;
    this->zywy = true;
    this->rogny = true;
    this->tekstura = WILCZA_JAGODA_TEKSTURA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->szybkoscUmyslu = SZYBKOSC_UMYSLU_ROSLIN;
    this->typ = TYP_ROSLINA;
    this->gatunek = WILCZA_JAGODA_GATUNEK;
}

void Wilcza_Jagoda::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Wilcza_Jagoda* potomek = new Wilcza_Jagoda(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    potomek->rogny = false;
    this->swiat->dodajOrganizm(*potomek);
}

bool Wilcza_Jagoda::obrona(Organizm &atakujacy)
{
    atakujacy.umieransko();
    this->umieransko();
    return false;
}

Wilcza_Jagoda::~Wilcza_Jagoda()
{

}
