//
// Created by Kacper Chodubski on 16/04/2022.
//

#include "Barszcz_Sosnowskiego.h"

Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(Swiat* swiat, int y, int x)
{
    this->swiat = swiat;
    this->sila = BARSZCZ_SILA;
    this->poz.y = y;
    this->poz.x = x;
    this->zywy = true;
    this->rogny = true;
    this->tekstura = BARSZCZ_TEKSTURA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->szybkoscUmyslu = SZYBKOSC_UMYSLU_ROSLIN;
    this->typ = TYP_ROSLINA;
    this->gatunek = BARSZCZ_GATUNEK;
}

void Barszcz_Sosnowskiego::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Barszcz_Sosnowskiego* potomek = new Barszcz_Sosnowskiego(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    potomek->rogny = false;
    this->swiat->dodajOrganizm(*potomek);
}

void Barszcz_Sosnowskiego::akcja()
{
    bool **OrgaznimyWOkolicy = this->wyznaczanieOrgaznizmowDoAtaku();
    if (OrgaznimyWOkolicy)
    {
        int prawdziwy_y;
        int prawdziwy_x;
        for (int y = 0; y < 2 * BARSZCZ_ZASIEG_RAZENIA + 1; y++)
        {
            for (int x = 0; x < 2 * BARSZCZ_ZASIEG_RAZENIA + 1; x++)
            {
                prawdziwy_x = this->poz.x - BARSZCZ_ZASIEG_RAZENIA + x;
                prawdziwy_y = this->poz.y - BARSZCZ_ZASIEG_RAZENIA + y;
                if (OrgaznimyWOkolicy[y][x])
                {
                    this->swiat->mapa->GetOrganizmNaKafelku(prawdziwy_y,prawdziwy_x)->umieransko();
                }
            }
        }
    }
}

bool Barszcz_Sosnowskiego::obrona(Organizm &atakujacy)
{
    atakujacy.umieransko();
    this->umieransko();
    return true;
}

Barszcz_Sosnowskiego::~Barszcz_Sosnowskiego()
{

}

bool **Barszcz_Sosnowskiego::wyznaczanieOrgaznizmowDoAtaku()
{
    bool **dostepnePola = this->swiat->mapa->dostepnePola(this->poz, ZASIEG_ROZSIEWANIA);
    int liczbaDostepnychPol = 0;
    for (int y = 0; y < 2*ZASIEG_ROZSIEWANIA + 1; y++)
    {
        for (int x = 0; x < 2 * ZASIEG_ROZSIEWANIA + 1; x++)
        {
            Wspolrzedne pozycjaNaMapie;
            pozycjaNaMapie.y = y + poz.y - ZASIEG_ROZSIEWANIA;
            pozycjaNaMapie.x = x + poz.x - ZASIEG_ROZSIEWANIA;
            Organizm* organizmNaKafelku = nullptr;
            if (dostepnePola[y][x])
            {
                organizmNaKafelku = this->swiat->mapa->GetOrganizmNaKafelku(pozycjaNaMapie.y,pozycjaNaMapie.x);
                dostepnePola[y][x] = false;
            }
            if (organizmNaKafelku && organizmNaKafelku->GetTyp() == TYP_ZWIERZE)
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

