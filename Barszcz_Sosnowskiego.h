//
// Created by Kacper Chodubski on 16/04/2022.
//

#ifndef PROJEKT1_BARSZCZ_SOSNOWSKIEGO_H
#define PROJEKT1_BARSZCZ_SOSNOWSKIEGO_H

#include "Roslina.h"

class Barszcz_Sosnowskiego: public Roslina{
private:
    bool** wyznaczanieOrgaznizmowDoAtaku();
public:
    Barszcz_Sosnowskiego(Swiat* swiat, int y, int x);
    void rodzeniePotomka (Wspolrzedne miejceNarodzin) override;
    bool obrona(Organizm& atakujacy) override;
    void akcja() override;
    ~Barszcz_Sosnowskiego() override;
};


#endif //PROJEKT1_BARSZCZ_SOSNOWSKIEGO_H
