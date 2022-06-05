//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_ROSLINA_H
#define PROJEKT1_ROSLINA_H

#include "Organizm.h"

class Roslina: public Organizm
{
protected:
    virtual void rozprzestrzenianie ();
    Wspolrzedne wyznaczenieMiejscaNarodzin (bool** dostepnePola);
public:
    void kolizja(Organizm& org, Wspolrzedne kafelek) override;
    void akcja() override;
    bool obrona(Organizm& atakujacy) override;
    bool atak(Organizm& broniacy) override;
};


#endif //PROJEKT1_ROSLINA_H
