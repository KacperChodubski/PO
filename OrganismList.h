//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_ORGANISMLIST_H
#define PROJEKT1_ORGANISMLIST_H

#include "Organism.h"
#include <iostream>

typedef struct foo
{
    Organism* organism;
    foo* next;
}Element;

class OrganismList
{
private:
    struct INFO
    {
        Element* head;
        Element* tail;
    };
    INFO info;
    int len;
public:
    OrganismList();
    int length();
    void add(Organism &org);
    void del(std::size_t index);
    Element& operator[](std::size_t index);
    ~OrganismList();
};


#endif //PROJEKT1_ORGANISMLIST_H
