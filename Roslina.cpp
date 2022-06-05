//
// Created by Kacper on 05.04.2022.
//

#include "Roslina.h"

void Roslina::akcja()
{
    this->rozprzestrzenianie();
}

void Roslina::rozprzestrzenianie()
{
    if (rand() % 100 < SZANSA_NA_ROZSZANIE)
    {
        bool **dostepnePola = this->wyznaczanieDostepnychPol(ZASIEG_ROZSIEWANIA);
        if (dostepnePola) {
            Wspolrzedne miejsceNarodzin = wyznaczenieMiejscaNarodzin(dostepnePola);
            this->rodzeniePotomka(miejsceNarodzin);
        }
    }
}

Wspolrzedne Roslina::wyznaczenieMiejscaNarodzin(bool** dostepnePola)
{
    Wspolrzedne miejsceNarodzin;

    bool czyJestNaDostepnymPolu;

    do {
        miejsceNarodzin.y = rand() % (2 * ZASIEG_ROZSIEWANIA + 1);
        miejsceNarodzin.x = rand() % (2 * ZASIEG_ROZSIEWANIA + 1);
        czyJestNaDostepnymPolu = dostepnePola[miejsceNarodzin.y][miejsceNarodzin.x];
    } while (!czyJestNaDostepnymPolu);

    miejsceNarodzin = miejsceNarodzin + this->poz;
    miejsceNarodzin.x -= ZASIEG_ROZSIEWANIA;
    miejsceNarodzin.y -= ZASIEG_ROZSIEWANIA;

    return miejsceNarodzin;
}

void Roslina::kolizja(Organizm& org, Wspolrzedne kafelek)
{}

bool Roslina::atak(Organizm &broniacy)
{
    return false;
}

bool Roslina::obrona(Organizm &atakujacy)
{
    this->umieransko();
    return false;
}
