//
// Created by Kacper Chodubski on 16/04/2022.
//

#ifndef PROJEKT1_WILCZA_JAGODA_H
#define PROJEKT1_WILCZA_JAGODA_H

#include "Roslina.h"

class Wilcza_Jagoda: public Roslina
{
public:
    Wilcza_Jagoda(Swiat* swiat, int y, int x);
    void rodzeniePotomka (Wspolrzedne miejceNarodzin) override;
    bool obrona(Organizm &atakujacy) override;
    ~Wilcza_Jagoda() override;
};


#endif //PROJEKT1_WILCZA_JAGODA_H
