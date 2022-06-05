//
// Created by Kacper on 12.04.2022.
//

#include "Wspolrzedne.h"


Wspolrzedne::Wspolrzedne()
{
    this->x = 0;
    this->y = 0;
}

Wspolrzedne::Wspolrzedne(int y, int x)
{
    this->y = y;
    this->x = x;
}

Wspolrzedne &Wspolrzedne::operator+(const Wspolrzedne &w)
{

    Wspolrzedne* wynik = new Wspolrzedne(this->y + w.y, this->x + w.x);
    return *wynik;
}

Wspolrzedne &Wspolrzedne::operator-(const Wspolrzedne &w)
{
    Wspolrzedne* wynik = new Wspolrzedne(this->y - w.y, this->x - w.x);
    return *wynik;
}

Wspolrzedne &Wspolrzedne::operator+=(const Wspolrzedne &w)
{
    this->y += w.y;
    this->x += w.x;
    return *this;
}

Wspolrzedne &Wspolrzedne::operator-=(const Wspolrzedne &w)
{
    this->y -= w.y;
    this->x -= w.x;
    return *this;
}

bool Wspolrzedne::operator==(const Wspolrzedne &w) const
{
    if (this->x == w.x && this->y == w.y)
    {
        return true;
    }
    return false;
}

bool Wspolrzedne::operator!=(const Wspolrzedne &w) const
{
    if (this->x == w.x && this->y == w.y)
    {
        return false;
    }
    return true;
}

Wspolrzedne::~Wspolrzedne() {}