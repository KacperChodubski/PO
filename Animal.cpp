//
// Created by Kacper on 05.04.2022.
//

#include "Animal.h"

void Animal::draw() const {}

void Animal::action()
{
    this->move();
}
void Animal::collision()
{
    this->fight();
}