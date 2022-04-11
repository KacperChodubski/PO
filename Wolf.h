//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_WOLF_H
#define PROJEKT1_WOLF_H

#include "Animal.h"

class Wolf: public Animal
{
private:

public:
    Wolf(World* w);
    void fight() override;
    void move() override;
    ~Wolf() override;
};


#endif //PROJEKT1_WOLF_H
