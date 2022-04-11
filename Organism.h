//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H

struct position
{
    short x,y;
};

class World;

class Organism
{
protected:
    char texture;
    World* world;
    virtual void collision () = 0;
    virtual void action() = 0;
    virtual void draw() const = 0;
public:
    short strength;
    short dexterity;
    short lifeDuration;
    position pos;
    virtual ~Organism();
};


#endif //PROJEKT1_ORGANISM_H
