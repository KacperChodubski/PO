#include <iostream>
#include "World.h"
#include "Wolf.h"

int main() {

    World world;

    Wolf wolf(&world);

    world.organisms->add(wolf);

    Wolf wolf1(&world);
    wolf1.dexterity = 3;
    world.organisms->add(wolf1);

    Wolf wolf2(&world);
    wolf2.dexterity = 11;
    world.organisms->add(wolf2);

    //bla bla
    return 0;
}
