//
// Created by Kacper Chodubski on 16/04/2022.
//

#ifndef PROJEKT1_MLECZ_H
#define PROJEKT1_MLECZ_H

#include "Roslina.h"

class Mlecz: public Roslina
{
private:
public:
    Mlecz(Swiat* swiat, int y, int x);
    void rodzeniePotomka (Wspolrzedne miejceNarodzin) override;
    void akcja() override;
    ~Mlecz() override;
};


#endif //PROJEKT1_MLECZ_H
