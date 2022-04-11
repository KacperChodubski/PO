//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_WORLD_H
#define PROJEKT1_WORLD_H

#include "Organism.h"
#include "OrganismList.h"

struct Tile
{
    Organism *organism;
};

class World
{
private:
    Tile *map;
public:
    World();
    OrganismList* organisms;
    void nextTurn();
    void drawWorld();
    ~World();
};


#endif //PROJEKT1_WORLD_H
