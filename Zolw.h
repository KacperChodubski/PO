//
// Created by Kacper Chodubski on 16/04/2022.
//

#ifndef PROJEKT1_ZOLW_H
#define PROJEKT1_ZOLW_H

#include "Zwierze.h"

class Zolw: public Zwierze
{
public:
    Zolw(Swiat* w, int y, int x);
    void rodzeniePotomka(Wspolrzedne miejsceNarodzin) override;
    void akcja() override;
    bool obrona(Organizm& atakujacy) override;
    ~Zolw() override;
};


#endif //PROJEKT1_ZOLW_H
