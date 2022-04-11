//
// Created by Kacper on 05.04.2022.
//

#include "OrganismList.h"

OrganismList::OrganismList()
{
    this->info.head = nullptr;
    this->info.tail = nullptr;
}

int OrganismList::length()
{
    return this->len;
}

void OrganismList::add(Organism &org)
{
    Element* elementToAdd = new Element;
    elementToAdd->organism = &org;
    elementToAdd->next = nullptr;
    if (this->info.head == nullptr)
    {
        this->info.head = elementToAdd;
        this->info.tail = elementToAdd;
    }
    else {
        if (this->info.head->organism->dexterity < org.dexterity)
        {
            elementToAdd->next = this->info.head;
            this->info.head = elementToAdd;
        }
        else
        {
            Element *temp = this->info.head;
            while (temp->next != nullptr && temp->next->organism->dexterity >= org.dexterity) {
                temp = temp->next;
            }
            elementToAdd->next = temp->next;
            if (temp->next == nullptr)
            {
                this->info.tail = elementToAdd;
            }
            temp->next = elementToAdd;
        }
    }
}

void OrganismList::del(std::size_t index)
{
    if (index == 0 && this->info.head != nullptr)
    {
        delete this->info.head;
        this->info.head = nullptr;
        if (info.tail == info.head)
        {
            this->info.tail = nullptr;
        }
    }
    else if (index < this->len)
    {
        Element* temp = this->info.head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        if (temp->next == this->info.tail)
        {
            delete this->info.tail;
            info.tail = temp;
        }
        else
        {
            Element *temp2 = temp->next->next;
            delete temp->next;
            temp->next = temp2;
        }
    }
}

Element&OrganismList::operator[](std::size_t index)
{
    Element* temp = this->info.head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return *temp;
}

OrganismList::~OrganismList()
{
    Element *temp2, *temp = this->info.head;
    if (temp != nullptr)
    {
        while (temp != this->info.tail)
        {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        delete temp;
    }
}

