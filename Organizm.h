//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_ORGANIZM_H
#define PROJEKT1_ORGANIZM_H
#include <time.h>
#include <iostream>
#include "Wspolrzedne.h"
#include "Swiat.h"

#define ILOSC_GATUNKOW 10
#define MAKS_ORGANIZMOW_NA_START 4

#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7

#define POCZATKOWA_WARTOSC_DLUGOSCI_ZYCIA -1
#define BAZOWY_ZASIEG_RUCHU 1
#define POCZATKOWA_WARTOSC_ROGNEGO 1
#define ZASIEG_ROZSIEWANIA 1
#define SZANSA_NA_ROZSZANIE 20
#define BAZOWA_SILA_ROSLIN 0
#define TYP_ROSLINA "Roslina"
#define TYP_ZWIERZE "Zwierze"

#define SZYBKOSC_UMYSLU_ROSLIN 0

// DANE DLA CZLOWIEK

#define CZLOWIEK_SILA 5
#define CZLOWIEK_SZYBKOSC_UMYSLU 4
#define CZLOWIEK_TEKSTURA '@'
#define CZLOWIEK_GATUNEK "Czowiek"
#define CZLOWIEK_CZAS_TRWANIA_UMIEJETNOSCI 20
#define CZLOWIEK_ZASIEG_UMIEJETNOSCI 5

//  DANE DLA WILKA

#define WILK_SILA 9
#define WILK_SZYBKOSC_UMYSLU 5
#define WILK_TEKSTURA 'W'
#define WILK_GATUNEK "Wilk"

// DANE DLA OWCY

#define OWCA_SILA 4
#define OWCA_SZYBKOSC_UMYSLU 4
#define OWCA_TEKSTURA 'O'
#define OWCA_GATUNEK "Owca"

// DANE DLA LISA

#define LIS_SILA 3
#define LIS_SZYBKOSC_UMYSLU 7
#define LIS_TEKSTURA 'L'
#define LIS_GATUNEK "Lis"

// DANE DLA ZOLWIA

#define ZOLW_SILA 2
#define ZOLW_SZYBKOSC_UMYSLU 1
#define ZOLW_TEKSTURA 'Z'
#define ZOLW_GATUNEK "Zolw"
#define ZOLW_SZANSA_NA_RUCH 0

// DANE DLA ANTYLOPY

#define ANTYLOPA_SILA 4
#define ANTYLOPA_SZYBKOSC_UMYSLU 4
#define ANTYLOPA_TEKSTURA 'A'
#define ANTYLOPA_ZASIEG_RUCHU 2
#define ANTYLOPA_GATUNEK "Antylopa"
#define ANTYLOPA_SZANSA_NA_UCIECZKE 50
#define ANTYLOPA_ZASIEG_UCIECZKI 1

// DANE DLA TRAWY

#define TRAWA_TEKSTURA 't'
#define TRAWA_GATUNEK "Trawa"

// DANE DLA MELCZA

#define MLECZ_ILOSC_PROB_ROZSIANIA 3
#define MLECZ_TEKSTURA 'm'
#define MLECZ_GATUNEK "Mlecz"

// DANE DLA GUARANY

#define GUARANA_TEKSTURA 'g'
#define GUARANA_DODAWANA_SILA 3
#define GUARANA_GATUNEK "Guarana"

// DANE DLA WILCZEJ_JAGODY

#define WILCZA_JAGODA_SILA 99
#define WILCZA_JAGODA_TEKSTURA 'w'
#define WILCZA_JAGODA_GATUNEK "Wilcza jagoda"

// DANE DLA BARSZCZU SOSNOWSKIEGO

#define BARSZCZ_SILA 10
#define BARSZCZ_TEKSTURA 'b'
#define BARSZCZ_ZASIEG_RAZENIA 1
#define BARSZCZ_GATUNEK "Barszcz sosnowskiego"

class Swiat;

class Organizm
{

protected:
    Swiat* swiat;
    bool** wyznaczanieDostepnychPol(int zasieg);
    std::string gatunek;
    std::string typ;
    char tekstura;
    short sila;
    short szybkoscUmyslu;
    short dlugoscZycia;
    bool rogny;
    bool zywy;
    Wspolrzedne poz;
public:

    bool GetRogny();
    void SetRogny(bool r);
    short GetSzybkoscUmyslu();
    short GetSila();
    void SetSila(short s);
    bool zyje();
    short GetDlugoscZycia ();
    void SetDlugoscZycia(short dlu);
    Wspolrzedne GetPozycja ();
    char GetTekstura();
    std::string GetGatunek();
    std::string GetTyp();

    virtual void akcja() = 0;
    bool porownanieGatunkow (Organizm& o) const;
    virtual void rodzeniePotomka(Wspolrzedne miejsceNarodzin) = 0;
    virtual void umieransko();
    void przesunNaPozycje(Wspolrzedne poz);
    void przesunWektorowo(Wspolrzedne wek);
    virtual void kolizja (Organizm& org, Wspolrzedne kafelek) = 0;
    virtual void walka(Organizm& orgAtakujacy, Organizm& orgBroniacy, Wspolrzedne pozycja);
    virtual bool obrona(Organizm& atakujacy) = 0;
    virtual bool atak(Organizm& broniacy) = 0;
    virtual ~Organizm();
};


#endif //PROJEKT1_ORGANIZM_H
