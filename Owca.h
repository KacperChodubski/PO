//
// Created by Kacper on 12.04.2022.
//

#ifndef PROJEKT1_OWCA_H
#define PROJEKT1_OWCA_H

#include "Zwierze.h"

class Owca :public Zwierze
{
private:

public:
    Owca(Swiat* w, int y, int x);
    void rodzeniePotomka(Wspolrzedne miejsceNarodzin) override;
    ~Owca() override;
};


#endif //PROJEKT1_OWCA_H
