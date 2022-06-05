//
// Created by Kacper on 05.04.2022.
//

#include "ListaOrganizmow.h"

ListaOrganizmow::ListaOrganizmow()
{
    this->info.glowa = nullptr;
    this->info.ogon = nullptr;
}

int ListaOrganizmow::dlugosc()
{
    return this->dlu;
}



void ListaOrganizmow::dodaj(Organizm &org)
{
    Element* elementToAdd = new Element;
    elementToAdd->organizm = &org;
    elementToAdd->nastepny = nullptr;
    if (this->info.glowa == nullptr)
    {
        this->info.glowa = elementToAdd;
        this->info.ogon = elementToAdd;
    }
    else {
        if (this->info.glowa->organizm->GetSzybkoscUmyslu() < org.GetSzybkoscUmyslu())
        {
            elementToAdd->nastepny = this->info.glowa;
            this->info.glowa = elementToAdd;
        }
        else
        {
            Element *temp = this->info.glowa;
            while (temp->nastepny != nullptr && temp->nastepny->organizm->GetSzybkoscUmyslu() >= org.GetSzybkoscUmyslu())
            {
                temp = temp->nastepny;
            }
            elementToAdd->nastepny = temp->nastepny;
            if (temp->nastepny == nullptr)
            {
                this->info.ogon = elementToAdd;
            }
            temp->nastepny = elementToAdd;
        }
    }
    dlu++;
}

void ListaOrganizmow::usun(std::size_t index)
{
    if (index == 0 && this->info.glowa != nullptr)
    {
        Element* temp = this->info.glowa;
        if (this->info.glowa->nastepny)
        {
            this->info.glowa = this->info.glowa->nastepny;
        }
        else
        {
            this->info.glowa = nullptr;
            if (info.ogon == info.glowa)
            {
                this->info.ogon = nullptr;
            }
        }
        delete temp;
    }
    else if (index < this->dlu)
    {
        Element* temp = this->info.glowa;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->nastepny;
        }
        if (temp->nastepny == this->info.ogon)
        {
            delete this->info.ogon;
            info.ogon = temp;
            temp->nastepny = nullptr;
        }
        else
        {
            Element *temp2 = temp->nastepny->nastepny;
            delete temp->nastepny;
            temp->nastepny = temp2;
        }
    }
    dlu--;
}

void ListaOrganizmow::usun(Organizm *org)
{
    Element* temp = this->info.glowa;
    int index = 0;
    while (index < dlu && temp->organizm != org)
    {
        index++;
        temp = temp->nastepny;
    }
    if (temp && temp->organizm == org)
    {
        usun(index);
    }
}

Element& ListaOrganizmow::operator[](int index)
{
    Element* temp = this->info.glowa;
    for (int i = 0; i < index; i++)
    {
        temp = temp->nastepny;
    }
    return *temp;
}
const Element& ListaOrganizmow::operator[](int index) const
{
    Element* temp = this->info.glowa;
    for (int i = 0; i < index; i++)
    {
        temp = temp->nastepny;
    }
    return *temp;
}

Element *ListaOrganizmow::pierwszyElement()
{
    return this->info.glowa;
}

Organizm *ListaOrganizmow::organizmNaIndeksie(int index)
{
    Element* temp = this->info.glowa;
    for (int i = 0; i < index; i++)
    {
        temp = temp->nastepny;
    }
    return temp->organizm;
}

ListaOrganizmow::~ListaOrganizmow()
{
    Element *temp2, *temp = this->info.glowa;
    if (temp != nullptr)
    {
        while (temp != this->info.ogon)
        {
            temp2 = temp;
            temp = temp->nastepny;
            delete temp2;
        }
        delete temp;
    }
}

