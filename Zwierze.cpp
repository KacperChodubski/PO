//
// Created by Kacper on 05.04.2022.
//

#include "Zwierze.h"

#define ZASIEG_ROZMANAZANIA 1


void Zwierze::akcja()
{
    this->rogny = true;
    this->ruch();
}
void Zwierze::kolizja(Organizm& org, Wspolrzedne kafelek)
{
    if(this->porownanieGatunkow(org))
    {
        if (this->rogny && org.GetRogny())
        {
            this->rozmnazanie(org);
        }
    }
    else
    {
        walka(*this, org, kafelek);
    }
}

bool Zwierze::walidacjaRuchu(const Wspolrzedne& wektor, bool **dostepnePola) const
{
    Wspolrzedne srodek (this->zasiegRuchu, this->zasiegRuchu);
    if (dostepnePola[srodek.y + wektor.y][srodek.x + wektor.x])
    {
        return true;
    }
    return false;
}

bool Zwierze::atak(Organizm &broniacy)
{
    if (this->sila >= broniacy.GetSila())
    {
        return true;
    }
    else
    {
        this->umieransko();
        return false;
    }
}

bool Zwierze::obrona(Organizm &atakujacy)
{
    if (this->sila < atakujacy.GetSila())
    {
        this->umieransko();
        return false;
    }
    else
    {
        return true;
    }
}

Wspolrzedne Zwierze::ustaleniePrzyszlejPoz()
{
    short kierunek;
    Wspolrzedne przyszlaPoz = this->poz;
    Wspolrzedne wektor;
    bool **dostepnePola = swiat->mapa->dostepnePola(this->poz,this->zasiegRuchu);
    do
    {
        wektor.y = 0;
        wektor.x = 0;
        kierunek = rand() % 8;
        switch (kierunek) {
            case N:
                wektor.y -= this->zasiegRuchu;
                break;
            case NE:
                wektor.y -= this->zasiegRuchu;
                wektor.x += this->zasiegRuchu;
                break;
            case E:
                wektor.x += this->zasiegRuchu;
                break;
            case SE:
                wektor.x += this->zasiegRuchu;
                wektor.y -= this->zasiegRuchu;
                break;
            case S:
                wektor.y += this->zasiegRuchu;
                break;
            case SW:
                wektor.y += this->zasiegRuchu;
                wektor.x -= this->zasiegRuchu;
                break;
            case W:
                wektor.x -= this->zasiegRuchu;
                break;
            case NW:
                wektor.y -= this->zasiegRuchu;
                wektor.x -= this->zasiegRuchu;
                break;
            default:
                break;
        }
    } while (!this->walidacjaRuchu(wektor, dostepnePola));
    przyszlaPoz = this->poz + wektor;
    return przyszlaPoz;
}

void Zwierze::ruch()
{
    Wspolrzedne przyszlaPoz = this->ustaleniePrzyszlejPoz();
    Organizm* organizmNaPrzyszlejPozycji = this->swiat->mapa->GetOrganizmNaKafelku(przyszlaPoz.y, przyszlaPoz.x);
    if (organizmNaPrzyszlejPozycji)
    {
        this->kolizja(*organizmNaPrzyszlejPozycji, przyszlaPoz);
        if (!swiat->mapa->GetOrganizmNaKafelku(przyszlaPoz.y, przyszlaPoz.x))
        {
            this->przesunNaPozycje(przyszlaPoz);
        }
    }
    else
    {
        this->przesunNaPozycje(przyszlaPoz);
    }
}

void Zwierze::rozmnazanie(Organizm& org)
{
    this->rogny = false;
    org.SetRogny(false);

    Wspolrzedne miejsceNardzin = ustaleniaMiejscaNarodzin(org);
    Organizm* organizmNaMiejscuNarodzin = this->swiat->mapa->GetOrganizmNaKafelku(miejsceNardzin.y, miejsceNardzin.x);
    if(!organizmNaMiejscuNarodzin)
    {
        this->rodzeniePotomka(miejsceNardzin);
    }
    else if (!organizmNaMiejscuNarodzin->obrona(*this))
    {
        organizmNaMiejscuNarodzin->umieransko();
        this->rodzeniePotomka(miejsceNardzin);
    }
}

Wspolrzedne Zwierze::ustaleniaMiejscaNarodzin(Organizm& org)
{
    Wspolrzedne wektor_I_C = org.GetPozycja() - this->poz;
    bool **dostepnePola = this->wyznaczanieDostepnychPolDoRuchu();
    dostepnePola[this->zasiegRuchu + wektor_I_C.y][this->zasiegRuchu + wektor_I_C.x] = false;

    Wspolrzedne miejsceNarodzin;
    bool czyJestNaPlanszy;

    do {
        miejsceNarodzin.y = rand() % (2 * this->zasiegRuchu + 1);
        miejsceNarodzin.x = rand() % (2 * this->zasiegRuchu + 1);
        czyJestNaPlanszy = dostepnePola[miejsceNarodzin.y][miejsceNarodzin.x];
    } while (!czyJestNaPlanszy);

    miejsceNarodzin = miejsceNarodzin + this->poz;
    miejsceNarodzin.x -= this->zasiegRuchu;
    miejsceNarodzin.y -= this->zasiegRuchu;


    return miejsceNarodzin;
}

bool **Zwierze::wyznaczanieDostepnychPolDoRuchu()
{
    return this->swiat->mapa->dostepnePola(this->poz, this->zasiegRuchu);
}