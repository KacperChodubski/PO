//
// Created by Kacper on 05.04.2022.
//

#include "Plant.h"

void Plant::action()
{
    this->spread();
}

void Plant::collision()
{
    this->eaten();
}
