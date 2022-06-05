//
// Created by Kacper Chodubski on 17/04/2022.
//

#include "Antylopa.h"


Antylopa::Antylopa(Swiat *s, int y, int x)
{
    this->poz.x = x;
    this->poz.y = y;
    this->swiat = s;
    this->szybkoscUmyslu = ANTYLOPA_SZYBKOSC_UMYSLU;
    this->zasiegRuchu = ANTYLOPA_ZASIEG_RUCHU;
    this->sila = ANTYLOPA_SILA;
    this->dlugoscZycia = POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA;
    this->rogny = POCZATKOWA_WARTOSC_ROGNEGO;
    this->tekstura = ANTYLOPA_TEKSTURA;
    this->gatunek = ANTYLOPA_GATUNEK;
    this->zywy = true;
    this->typ = TYP_ZWIERZE;
}

void Antylopa::rodzeniePotomka(Wspolrzedne miejsceNarodzin)
{
    Antylopa *dziecko = new Antylopa(this->swiat, miejsceNarodzin.y, miejsceNarodzin.x);
    this->swiat->dodajOrganizm(*dziecko);
}

bool Antylopa::obrona(Organizm &atakujacy)
{
    if (this->sila < atakujacy.GetSila())
    {
        if (rand() % 100 < ANTYLOPA_SZANSA_NA_UCIECZKE)
        {
            bool **dostepnePolaDoUcieczki = this->wyznaczanieDostepnychPol(ANTYLOPA_ZASIEG_UCIECZKI);
            if (dostepnePolaDoUcieczki)
            {
                int losowy_y;
                int losowy_x;
                Wspolrzedne prawdzieWspolrzedne;
                do
                {
                    losowy_y = rand() % (2 * ANTYLOPA_ZASIEG_UCIECZKI + 1);
                    losowy_x = rand() % (2 * ANTYLOPA_ZASIEG_UCIECZKI + 1);
                }while (!dostepnePolaDoUcieczki[losowy_y][losowy_x]);

                prawdzieWspolrzedne.y = this->poz.y - ANTYLOPA_ZASIEG_UCIECZKI + losowy_y;
                prawdzieWspolrzedne.x = this->poz.x - ANTYLOPA_ZASIEG_UCIECZKI + losowy_x;
                this->przesunNaPozycje(prawdzieWspolrzedne);
                std::cout << "Obrona - " << this->gatunek << " uciekla" << std::endl;
                return true;
            }
            else
            {
                this->umieransko();
                return false;
            }
        }
        else
        {
            this->umieransko();
            return false;
        }
    }
    return true;
}

Antylopa::~Antylopa() {}