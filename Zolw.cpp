//
// Created by Kacper Chodubski on 16/04/2022.
//

#include "Zolw.h"


Zolw::Zolw(Swiat* s, int y, int x)
{
    this->poz.x = x;
    this->poz.y = y;
    this->swiat = s;
    this->szybkoscUmyslu = ZOLW_SZYBKOSC_UMYSLU;
    this->zasiegRuchu = BAZOWY_ZASIEG_RUCHU;
    this->sila = ZOLW_SILA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->rogny = POCZATKOWA_WARTOSC_ROGNEGO;
    this->tekstura = ZOLW_TEKSTURA;
    this->gatunek = ZOLW_GATUNEK;
    this->zywy = true;
    this->typ = TYP_ZWIERZE;
}


void Zolw::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Zolw *dziecko = new Zolw(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    this->swiat->dodajOrganizm(*dziecko);
}


void Zolw::akcja()
{
    this->rogny = true;
    if (rand() % 100 < ZOLW_SZANSA_NA_RUCH)
    {
        this->ruch();
    }
}

bool Zolw::obrona(Organizm &atakujacy)
{
    if (atakujacy.GetSila() < 5 || atakujacy.GetSila() < this->sila)
    {
        std::cout << "Obrona - " << this->gatunek << " odbil atak" << std::endl;
        return true;
    }
    else
    {
        this->umieransko();
        return false;
    }
}


Zolw::~Zolw()
{}