//
// Created by Kacper on 12.04.2022.
//

#ifndef PROJEKT1_WSPOLRZEDNE_H
#define PROJEKT1_WSPOLRZEDNE_H


class Wspolrzedne
{
public:
    Wspolrzedne();
    Wspolrzedne(int y, int x);
    Wspolrzedne& operator +(const Wspolrzedne& w);
    Wspolrzedne& operator -(const Wspolrzedne& w);
    Wspolrzedne& operator +=(const Wspolrzedne& w);
    Wspolrzedne& operator -=(const Wspolrzedne& w);
    bool operator ==(const Wspolrzedne& w) const;
    bool operator !=(const Wspolrzedne& w) const;
    int x;
    int y;
    ~Wspolrzedne();
};


#endif //PROJEKT1_WSPOLRZEDNE_H
