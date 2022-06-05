//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_ZWIERZE_H
#define PROJEKT1_ZWIERZE_H

#include "Organizm.h"


class Zwierze: public Organizm
{
private:
    virtual Wspolrzedne ustaleniePrzyszlejPoz ();
    Wspolrzedne ustaleniaMiejscaNarodzin (Organizm& org);
    bool obrona(Organizm& atakujacy) override;
    bool atak(Organizm& broniacy) override;
    virtual bool** wyznaczanieDostepnychPolDoRuchu ();
protected:
    bool walidacjaRuchu (const Wspolrzedne& wektor, bool** dostepnePola) const;
    unsigned short zasiegRuchu;
    void akcja () override;
    void kolizja (Organizm& org, Wspolrzedne kafelek) override;
    void rozmnazanie (Organizm& org);
public:
    virtual void ruch ();
};


#endif //PROJEKT1_ZWIERZE_H
