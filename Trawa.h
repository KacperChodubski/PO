//
// Created by Kacper Chodubski on 15/04/2022.
//

#ifndef PROJEKT1_TRAWA_H
#define PROJEKT1_TRAWA_H

#include "Roslina.h"

class Trawa: public Roslina
{
private:
public:
    Trawa(Swiat* swiat, int y, int x);
    void rodzeniePotomka (Wspolrzedne miejceNarodzin) override;
    ~Trawa() override;
};


#endif //PROJEKT1_TRAWA_H
