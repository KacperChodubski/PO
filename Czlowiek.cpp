//
// Created by Kacper Chodubski on 25/04/2022.
//

#include "Czlowiek.h"

#define UMIEJETNOSC_BIND "u"


Czlowiek::Czlowiek(Swiat *s, int y, int x)
{
    this->poz.x = x;
    this->poz.y = y;
    this->swiat = s;
    this->szybkoscUmyslu = CZLOWIEK_SZYBKOSC_UMYSLU;
    this->zasiegRuchu = BAZOWY_ZASIEG_RUCHU;
    this->sila = CZLOWIEK_SILA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->rogny = POCZATKOWA_WARTOSC_ROGNEGO;
    this->tekstura = CZLOWIEK_TEKSTURA;
    this->gatunek = CZLOWIEK_GATUNEK;
    this->czasUmiejetnosci = 0;
    this->zywy = true;
    this->typ = TYP_ZWIERZE;

    this->swiat->dodajOrganizm(*this);
}

int Czlowiek::GetCzasUmiejetnosci()
{
    return this->czasUmiejetnosci;
}

void Czlowiek::SetCzasUmiejetnosci(int czas)
{
    this->czasUmiejetnosci = czas;
}

Wspolrzedne Czlowiek::ustaleniePrzyszlejPoz() {
    std::string kierunek = this->swiat->GetWejscie();
    Wspolrzedne przyszlaPoz = this->poz;
    Wspolrzedne wektor;
    bool **dostepnePola = swiat->mapa->dostepnePola(this->poz, this->zasiegRuchu);
    wektor.y = 0;
    wektor.x = 0;
    if (kierunek == "w")
    {
        wektor.y -= this->zasiegRuchu;
    }
    else if (kierunek == "wd")
    {
        wektor.y -= this->zasiegRuchu;
        wektor.x += this->zasiegRuchu;
    }
    else if (kierunek == "d")
    {
        wektor.x += this->zasiegRuchu;
    }
    else if (kierunek == "sd")
    {
        wektor.x += this->zasiegRuchu;
        wektor.y += this->zasiegRuchu;
    }
    else if (kierunek == "s")
    {
        wektor.y += this->zasiegRuchu;
    }
    else if(kierunek == "sa")
    {
        wektor.y += this->zasiegRuchu;
        wektor.x -= this->zasiegRuchu;
    }
    else if(kierunek == "a")
    {
        wektor.x -= this->zasiegRuchu;
    }
    else if(kierunek == "wa")
    {
        wektor.y -= this->zasiegRuchu;
        wektor.x -= this->zasiegRuchu;
    }
    if (this->walidacjaRuchu(wektor, dostepnePola)) {
        przyszlaPoz = this->poz + wektor;
    }
    return przyszlaPoz;
}

void Czlowiek::akcja()
{
    if (this->czasUmiejetnosci)
    {
        this->czasUmiejetnosci--;
        this->umiejetnosc();
    }
    if (this->swiat->GetWejscie() == UMIEJETNOSC_BIND)
    {
        this->czasUmiejetnosci = CZLOWIEK_CZAS_TRWANIA_UMIEJETNOSCI;
    }
    this->ruch();
}

void Czlowiek::umiejetnosc()
{
    bool** organizmyDoAtaku = this->wyznaczanieOrgaznizmowDoAtaku();

    if (organizmyDoAtaku)
    {
        int prawdziwy_y;
        int prawdziwy_x;
        for (int y = 0; y < 2 * CZLOWIEK_ZASIEG_UMIEJETNOSCI + 1; y++)
        {
            for (int x = 0; x < 2 * CZLOWIEK_ZASIEG_UMIEJETNOSCI + 1; x++)
            {
                prawdziwy_x = this->poz.x - CZLOWIEK_ZASIEG_UMIEJETNOSCI + x;
                prawdziwy_y = this->poz.y - CZLOWIEK_ZASIEG_UMIEJETNOSCI + y;
                if (organizmyDoAtaku[y][x])
                {
                    this->swiat->mapa->GetOrganizmNaKafelku(prawdziwy_y,prawdziwy_x)->umieransko();
                }
            }
        }
    }

}

bool **Czlowiek::wyznaczanieOrgaznizmowDoAtaku()
{
    bool **dostepnePola = this->swiat->mapa->dostepnePola(this->poz, CZLOWIEK_ZASIEG_UMIEJETNOSCI);
    int liczbaDostepnychPol = 0;
    for (int y = 0; y < 2*CZLOWIEK_ZASIEG_UMIEJETNOSCI + 1; y++)
    {
        for (int x = 0; x < 2 * CZLOWIEK_ZASIEG_UMIEJETNOSCI + 1; x++)
        {
            Wspolrzedne pozycjaNaMapie;
            pozycjaNaMapie.y = y + poz.y - CZLOWIEK_ZASIEG_UMIEJETNOSCI;
            pozycjaNaMapie.x = x + poz.x - CZLOWIEK_ZASIEG_UMIEJETNOSCI;
            Organizm* organizmNaKafelku = nullptr;
            if (dostepnePola[y][x])
            {
                organizmNaKafelku = this->swiat->mapa->GetOrganizmNaKafelku(pozycjaNaMapie.y,pozycjaNaMapie.x);
                dostepnePola[y][x] = false;
            }
            if (organizmNaKafelku)
            {
                dostepnePola[y][x] = true;
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

void Czlowiek::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{

}


Czlowiek::~Czlowiek()
{

}