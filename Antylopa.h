//
// Created by Kacper Chodubski on 17/04/2022.
//

#ifndef PROJEKT1_ANTYLOPA_H
#define PROJEKT1_ANTYLOPA_H

#include "Zwierze.h"

class Antylopa: public Zwierze
{
public:
    Antylopa(Swiat* w, int y, int x);
    void rodzeniePotomka(Wspolrzedne miejsceNarodzin) override;
    bool obrona(Organizm& atakujacy) override;
    ~Antylopa() override;
};


#endif //PROJEKT1_ANTYLOPA_H
