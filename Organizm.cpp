//
// Created by Kacper on 05.04.2022.
//

#include "Organizm.h"


Organizm::~Organizm() {};

void Organizm::umieransko()
{
    std::cout << "Smierc - " << this->gatunek << std::endl;
    this->zywy = false;
    this->rogny = false;
    this->swiat->mapa->aktualizujOrganizmNaKafelku(this->poz, *this);
}

bool Organizm::GetRogny()
{
    return this->rogny;
}

void Organizm::SetRogny(bool r)
{
    this->rogny = r;
}

short Organizm::GetSzybkoscUmyslu()
{
    return this->szybkoscUmyslu;
}

short Organizm::GetSila()
{
    return this->sila;
}

void Organizm::SetSila(short s)
{
    this->sila = s;
}

bool Organizm::zyje()
{
    return this->zywy;
}

short Organizm::GetDlugoscZycia()
{
    return this->dlugoscZycia;
}

void Organizm::SetDlugoscZycia(short dlu)
{
    this->dlugoscZycia = dlu;
}

Wspolrzedne Organizm::GetPozycja()
{
    return this->poz;
}

char Organizm::GetTekstura()
{
    return this->tekstura;
}

std::string Organizm::GetGatunek()
{
    return this->gatunek;
}

std::string Organizm::GetTyp()
{
    return this->typ;
}

void Organizm::przesunNaPozycje(Wspolrzedne poz)
{
    Wspolrzedne staraPoz = this->poz;
    this->poz = poz;
    this->swiat->mapa->aktualizujOrganizmNaKafelku(staraPoz, *this);
}

void Organizm::walka(Organizm &orgAtakujacy, Organizm &orgBroniacy, Wspolrzedne pozycja)
{
    std::cout << "Walka - Atakujacy: " << orgAtakujacy.gatunek << " Broniacy: " << orgBroniacy.gatunek << std::endl;
    bool rezultatAtaku = orgAtakujacy.atak(orgBroniacy);
    if (rezultatAtaku && orgAtakujacy.zywy)
    {
        orgBroniacy.obrona(orgAtakujacy);
    }
}

void Organizm::przesunWektorowo(Wspolrzedne wek)
{
    Wspolrzedne staraPoz = this->poz;
    this->poz+=wek;
    this->swiat->mapa->aktualizujOrganizmNaKafelku(staraPoz, *this);
}

bool **Organizm::wyznaczanieDostepnychPol(int zasieg)
{
    bool **dostepnePola = this->swiat->mapa->dostepnePola(this->poz, zasieg);
    int liczbaDostepnychPol = 0;
    for (int y = 0; y < 2*zasieg + 1; y++)
    {
        for (int x = 0; x < 2 * zasieg + 1; x++)
        {
            Wspolrzedne pozycjaNaMapie;
            pozycjaNaMapie.y = y + poz.y - zasieg;
            pozycjaNaMapie.x = x + poz.x - zasieg;
            Organizm* organizmNaKafelku = nullptr;
            if (dostepnePola[y][x])
            {
                organizmNaKafelku = this->swiat->mapa->GetOrganizmNaKafelku(pozycjaNaMapie.y,pozycjaNaMapie.x);
            }
            if (organizmNaKafelku)
            {
                dostepnePola[y][x] = false;
            }
            if (dostepnePola[y][x])
            {
                liczbaDostepnychPol++;
            }
        }
    }
    if (liczbaDostepnychPol == 0)
    {
        return nullptr;
    }
    return dostepnePola;
}

bool Organizm::porownanieGatunkow(Organizm &o) const
{
    if (this->gatunek == o.gatunek)
    {
        return true;
    }
    else
    {
        return false;
    }
}