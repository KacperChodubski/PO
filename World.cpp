//
// Created by Kacper on 05.04.2022.
//

#include "World.h"

World::World()
{
    this->organisms = new OrganismList;
}

void World::drawWorld() {}

void World::nextTurn() {}

World::~World()
{
    delete this->organisms;
}