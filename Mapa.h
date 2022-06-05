//
// Created by Kacper on 12.04.2022.
//

#ifndef PROJEKT1_MAPA_H
#define PROJEKT1_MAPA_H

#include "ListaOrganizmow.h"
#include "Wspolrzedne.h"

class Organizm;

class Mapa
{
private:
    void tworzenieMapy();
    Organizm ***orgNaKafelku;
    int rozmiar_y;
    int rozmiar_x;
public:
    Mapa();
    Mapa(int y, int x);
    int GetRozmiar_y ();
    int GetRozmiar_x ();
    Wspolrzedne GetRozmiar ();
    bool** dostepnePola (const Wspolrzedne& wspol, unsigned short zasieg) const;
    Organizm* GetOrganizmNaKafelku (int y, int x) const;
    void aktualizujOrganizmNaKafelku (const Wspolrzedne& staraPoz, Organizm& org);
    void SetOrganizmNaKafelku(int y, int x, Organizm* org);
    void rysowanie();
    ~Mapa();
};


#endif //PROJEKT1_MAPA_H
