//
// Created by Kacper on 05.04.2022.
//

#include "Wilk.h"



Wilk::Wilk(Swiat* s, int y, int x)
{
    this->poz.x = x;
    this->poz.y = y;
    this->swiat = s;
    this->szybkoscUmyslu = WILK_SZYBKOSC_UMYSLU;
    this->zasiegRuchu = BAZOWY_ZASIEG_RUCHU;
    this->sila = WILK_SILA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->rogny = POCZATKOWA_WARTOSC_ROGNEGO;
    this->tekstura = WILK_TEKSTURA;
    this->gatunek = WILK_GATUNEK;
    this->zywy = true;
    this->typ = TYP_ZWIERZE;

}


void Wilk::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Wilk *dziecko = new Wilk(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    this->swiat->dodajOrganizm(*dziecko);
}


Wilk::~Wilk()
{}