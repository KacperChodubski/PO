//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_ANIMAL_H
#define PROJEKT1_ANIMAL_H

#include "Organism.h"


class Animal: public Organism
{
protected:
    void action () override;
    void collision () override;
    void draw() const override;
    virtual void fight () = 0;
    virtual void move () = 0;
public:
};


#endif //PROJEKT1_ANIMAL_H
