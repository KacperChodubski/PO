//
// Created by Kacper on 12.04.2022.
//

#include "Owca.h"




Owca::Owca(Swiat* s, int y, int x)
{
    this->poz.x = x;
    this->poz.y = y;
    this->swiat = s;
    this->szybkoscUmyslu = OWCA_SZYBKOSC_UMYSLU;
    this->zasiegRuchu = BAZOWY_ZASIEG_RUCHU;
    this->sila = OWCA_SILA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->rogny = POCZATKOWA_WARTOSC_ROGNEGO;
    this->tekstura = OWCA_TEKSTURA;
    this->gatunek = OWCA_GATUNEK;
    this->zywy = true;
    this->typ = TYP_ZWIERZE;


}


void Owca::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Owca *dziecko = new Owca(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    this->swiat->dodajOrganizm(*dziecko);
}


Owca::~Owca()
{}