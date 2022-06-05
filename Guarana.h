//
// Created by Kacper Chodubski on 16/04/2022.
//

#ifndef PROJEKT1_GUARANA_H
#define PROJEKT1_GUARANA_H

#include "Roslina.h"

class Guarana: public Roslina
{
public:
    Guarana(Swiat* swiat, int y, int x);
    void rodzeniePotomka (Wspolrzedne miejceNarodzin) override;
    bool obrona(Organizm &atakujacy) override;
    ~Guarana() override;
};


#endif //PROJEKT1_GUARANA_H
