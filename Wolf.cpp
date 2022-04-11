//
// Created by Kacper on 05.04.2022.
//

#include "Wolf.h"


Wolf::Wolf(World* w)
{
    this->world = w;
    this->dexterity = 5;
    this->strength = 9;
    this->lifeDuration = 0;
}

void Wolf::fight() {}

void Wolf::move() {}

Wolf::~Wolf()
{}