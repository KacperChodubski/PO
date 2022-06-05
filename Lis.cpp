//
// Created by Kacper Chodubski on 17/04/2022.
//

#include "Lis.h"



Lis::Lis(Swiat *s, int y, int x)
{
    this->poz.x = x;
    this->poz.y = y;
    this->swiat = s;
    this->szybkoscUmyslu = LIS_SZYBKOSC_UMYSLU;
    this->zasiegRuchu = BAZOWY_ZASIEG_RUCHU;
    this->sila = LIS_SILA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->rogny = POCZATKOWA_WARTOSC_ROGNEGO;
    this->tekstura = LIS_TEKSTURA;
    this->gatunek = LIS_GATUNEK;
    this->zywy = true;
    this->typ = TYP_ZWIERZE;
}

void Lis::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Lis *dziecko = new Lis(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    this->swiat->dodajOrganizm(*dziecko);
}

bool **Lis::wyznaczanieDostepnychPolDoRuchu()
{
    bool** dostepnePola = this->swiat->mapa->dostepnePola(this->poz, this->zasiegRuchu);
    Wspolrzedne prawdziweWspolrzedne;
    for (int y = 0; y < 2*zasiegRuchu + 1; y++)
    {
        for (int x = 0; x < 2*zasiegRuchu + 1; x++)
        {
            prawdziweWspolrzedne.y = this->poz.y - zasiegRuchu + y;
            prawdziweWspolrzedne.x = this->poz.x - zasiegRuchu + x;
            Organizm* orgNaKafelku = nullptr;
            if (dostepnePola[y][x])
            {
                orgNaKafelku = this->swiat->mapa->GetOrganizmNaKafelku(prawdziweWspolrzedne.y, prawdziweWspolrzedne.x);
            }
            if (orgNaKafelku && orgNaKafelku->GetSila() > this->sila)
            {
                dostepnePola[y][x] = false;
            }
        }
    }
    return dostepnePola;
}

Lis::~Lis() {}