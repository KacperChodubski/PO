//
// Created by Kacper Chodubski on 16/04/2022.
//

#include "Guarana.h"


Guarana::Guarana(Swiat* swiat, int y, int x)
{
    this->swiat = swiat;
    this->sila = BAZOWA_SILA_ROSLIN;
    this->poz.y = y;
    this->poz.x = x;
    this->zywy = true;
    this->rogny = true;
    this->tekstura = GUARANA_TEKSTURA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->szybkoscUmyslu = SZYBKOSC_UMYSLU_ROSLIN;
    this->gatunek = GUARANA_GATUNEK;


}

void Guarana::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Guarana* potomek = new Guarana(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    potomek->rogny = false;
    this->swiat->dodajOrganizm(*potomek);
}

bool Guarana::obrona(Organizm &atakujacy)
{
    atakujacy.SetSila(atakujacy.GetSila() + GUARANA_DODAWANA_SILA);
    this->umieransko();
    return false;
}

Guarana::~Guarana()
{

}

