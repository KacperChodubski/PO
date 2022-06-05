//
// Created by Kacper Chodubski on 16/04/2022.
//

#include "Mlecz.h"


Mlecz::Mlecz(Swiat* swiat, int y, int x)
{
    this->swiat = swiat;
    this->sila = BAZOWA_SILA_ROSLIN;
    this->poz.y = y;
    this->poz.x = x;
    this->zywy = true;
    this->rogny = true;
    this->tekstura = MLECZ_TEKSTURA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->szybkoscUmyslu = SZYBKOSC_UMYSLU_ROSLIN;
    this->gatunek = MLECZ_GATUNEK;


}

void Mlecz::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Mlecz* potomek = new Mlecz(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    potomek->rogny = false;
    this->swiat->dodajOrganizm(*potomek);

}

void Mlecz::akcja()
{
    for (int i = 0; i < MLECZ_ILOSC_PROB_ROZSIANIA; i++)
    {
        this->rozprzestrzenianie();
    }

}

Mlecz::~Mlecz()
{

}