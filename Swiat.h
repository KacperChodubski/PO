//
// Created by Kacper on 05.04.2022.
//

#ifndef PROJEKT1_SWIAT_H
#define PROJEKT1_SWIAT_H

#include "Organizm.h"
#include "ListaOrganizmow.h"
#include "Mapa.h"
#include <fstream>
#include <iostream>


class Organizm;
class ListaOrganizmow;
class Mapa;

class Swiat
{
private:
    std::string wczytanieGatunek(std::string line, int& i);
    Wspolrzedne wczytaniePoz(std::string line, int& i);
    int wczytanieDlugoscZycia(std::string line, int& i);
    int wczytanieCzasuUmiejetnosci(std::string line, int& i);
    std::string wejscie;
    void dodawanieDanegoGatunku(std::string gatunek, Wspolrzedne poz, int dlugoscZycia);
    void dodawanieCzlowieka(Wspolrzedne poz, int dlugoscZycia, int czasUmiejetnosci);
    unsigned int tury;
    void zapis();
    void wczytanieZapisy();
    void initSwiata();
    void czyszczenie(int y, int x, unsigned int tury);
public:
    Mapa *mapa;
    Swiat();
    Swiat(int y, int x);
    ListaOrganizmow* organizmy;
    unsigned int GetTury();
    void nastepnaTura();
    void SetWejscie(std::string wejscie);
    std::string GetWejscie();
    void dodajOrganizm(Organizm &org);
    ~Swiat();
};


#endif //PROJEKT1_SWIAT_H
