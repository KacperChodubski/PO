//
// Created by Kacper Chodubski on 17/04/2022.
//

#ifndef PROJEKT1_LIS_H
#define PROJEKT1_LIS_H

#include "Zwierze.h"

class Lis: public Zwierze
{
private:
    bool ** wyznaczanieDostepnychPolDoRuchu() override;
public:
    Lis(Swiat* w, int y, int x);
    void rodzeniePotomka(Wspolrzedne miejsceNarodzin) override;
    ~Lis() override;
};


#endif //PROJEKT1_LIS_H
