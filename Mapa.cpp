//
// Created by Kacper on 12.04.2022.
//

#include "Mapa.h"
#include <iostream>

using namespace std;

#define DOMYSLNY_ROZMIAR_MAPY 20

Mapa::Mapa()
{
    this->rozmiar_y = DOMYSLNY_ROZMIAR_MAPY;
    this->rozmiar_x = DOMYSLNY_ROZMIAR_MAPY;
    this->tworzenieMapy();
}
Mapa::Mapa(int y, int x)
{
    this->rozmiar_y = y;
    this->rozmiar_x = x;
    this->tworzenieMapy();
}

Wspolrzedne Mapa::GetRozmiar()
{
    Wspolrzedne rozmiar;
    rozmiar.y = this->rozmiar_y;
    rozmiar.x = this->rozmiar_x;
    return rozmiar;
}

int Mapa::GetRozmiar_y()
{
    return this->rozmiar_y;
}

int Mapa::GetRozmiar_x()
{
    return this->rozmiar_x;
}

Organizm *Mapa::GetOrganizmNaKafelku(int y, int x) const
{
    return orgNaKafelku[y][x];
}

void Mapa::aktualizujOrganizmNaKafelku(const Wspolrzedne &staraPoz, Organizm& org)
{
    this->orgNaKafelku[staraPoz.y][staraPoz.x] = nullptr;
    if (org.zyje())
    {
        orgNaKafelku[org.GetPozycja().y][org.GetPozycja().x] = &org;
    }
}

void Mapa::SetOrganizmNaKafelku(int y, int x, Organizm* org)
{
    this->orgNaKafelku[y][x] = org;
}

bool** Mapa::dostepnePola(const Wspolrzedne& wspol, unsigned short zasieg) const
{
    bool **dosPola = new bool*[2*zasieg + 1];
    for (int i = 0; i < 2*zasieg + 1; i++)
    {
        dosPola[i] = new bool [2*zasieg + 1];
    }

    for (int y = -1 * zasieg; y <= zasieg; y++)
    {
        for (int x =  -1 * zasieg; x <= zasieg; x++)
        {
            if (wspol.y + y < this->rozmiar_y && wspol.y + y >= 0 && wspol.x + x < this->rozmiar_x && wspol.x + x >= 0)
            {
                dosPola[zasieg + y][zasieg + x] = true;
            }
            else
            {
                dosPola[zasieg + y][zasieg + x] = false;
            }
        }
    }
    dosPola[zasieg][zasieg] = false;
    return dosPola;
}

void Mapa::tworzenieMapy()
{
    this->orgNaKafelku = new Organizm**[this->rozmiar_y];
    for (int y = 0; y < this->rozmiar_y; y++)
    {
        this->orgNaKafelku[y] = new Organizm*[this->rozmiar_x];
        for (int x = 0; x < this->rozmiar_x; x++)
        {
            orgNaKafelku[y][x] = nullptr;
        }
    }
}

void Mapa::rysowanie()
{
    for (int y = 0; y < this->rozmiar_y; y++)
    {
        for (int x = 0; x < this->rozmiar_x; x++)
        {
            if (this->orgNaKafelku[y][x])
            {
                cout << orgNaKafelku[y][x]->GetTekstura();
            }
            else
            {
                if (x == 0 || y == 0 || x == rozmiar_x -1 || y == rozmiar_y - 1)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }

            }
            cout << ' ';
        }
        cout << endl;
    }
}

Mapa::~Mapa()
{

    for (int y = 0; y < this->rozmiar_y; y++)
    {
        delete orgNaKafelku[y];
    }

    delete orgNaKafelku;
}