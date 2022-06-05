//
// Created by Kacper Chodubski on 25/04/2022.
//

#ifndef PROJEKT1_CZLOWIEK_H
#define PROJEKT1_CZLOWIEK_H

#include "Zwierze.h"

class Czlowiek: public Zwierze
{
private:
    int czasUmiejetnosci;
    bool** wyznaczanieOrgaznizmowDoAtaku();
public:
    Czlowiek(Swiat *s, int y, int x);
    Wspolrzedne ustaleniePrzyszlejPoz () override;
    void rodzeniePotomka(Wspolrzedne miejsceNarodzin) override;
    int GetCzasUmiejetnosci ();
    void SetCzasUmiejetnosci (int czas);
    void akcja() override;
    void umiejetnosc();
    ~Czlowiek();
};


#endif //PROJEKT1_CZLOWIEK_H
