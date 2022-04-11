//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_PLANT_H
#define PROJEKT1_PLANT_H

#include "Organism.h"

class Plant: public Organism
{
protected:
    void action() override;
    void collision() override;
public:
    virtual void spread() const = 0;
    virtual void eaten() = 0;
};


#endif //PROJEKT1_PLANT_H
