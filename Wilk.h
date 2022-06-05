//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_WILK_H
#define PROJEKT1_WILK_H

#include "Zwierze.h"

class Wilk: public Zwierze
{
private:

public:
    Wilk(Swiat* s, int y, int x);
    ~Wilk() override;
    void rodzeniePotomka(Wspolrzedne miejsceNarodzin) override;
};


#endif //PROJEKT1_WILK_H
