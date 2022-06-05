//
// Created by Kacper on 05.04.2022.
//

#include "Swiat.h"
#include <iostream>

#include "Wilk.h"
#include "Owca.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcza_Jagoda.h"
#include "Zolw.h"
#include "Barszcz_Sosnowskiego.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Czlowiek.h"


Swiat::Swiat()
{
    this->organizmy = new ListaOrganizmow;
    mapa = new Mapa;
    this->tury = 0;
    this->initSwiata();
}
Swiat::Swiat(int y, int x)
{
    this->organizmy = new ListaOrganizmow;
    mapa = new Mapa(y, x);
}

void Swiat::nastepnaTura()
{
    if (this->wejscie == "save")
    {
        this->zapis();
    }
    else if (this->wejscie == "load")
    {
        this->wczytanieZapisy();
    }
    else
    {
        tury++;
        Element *temp = organizmy->pierwszyElement();
        while (temp) {
            Element *pop = temp;
            if (temp->organizm->zyje()) {
                temp->organizm->SetDlugoscZycia(temp->organizm->GetDlugoscZycia() + 1);
                if (temp->organizm->GetDlugoscZycia() > 0) {
                    temp->organizm->akcja();
                }
            }
            temp = temp->nastepny;
            if (!pop->organizm->zyje()) {
                this->organizmy->usun(pop->organizm);
            }
        }
    }
}

void Swiat::initSwiata()
{
    Organizm* organizmy [ILOSC_GATUNKOW];
    organizmy[0] = new Owca(this, 0, 0);
    organizmy[1] = new Wilk(this, 0, 0);
    organizmy[2] = new Zolw(this, 0, 0);
    organizmy[3] = new Antylopa(this, 0, 0);
    organizmy[4] = new Lis(this, 0, 0);
    organizmy[5] = new Trawa(this, 0, 0);
    organizmy[6] = new Mlecz(this, 0, 0);
    organizmy[7] = new Guarana(this, 0, 0);
    organizmy[8] = new Wilcza_Jagoda(this, 0, 0);
    organizmy[9] = new Barszcz_Sosnowskiego(this, 0, 0);

    for (int i = 0; i < ILOSC_GATUNKOW; i++)
    {
        int ilosc = rand() % MAKS_ORGANIZMOW_NA_START + 1;
        for (int j = 0; j < ilosc; j++)
        {
            Wspolrzedne losowaPozycja;
            losowaPozycja.y = rand() % this->mapa->GetRozmiar_y();
            losowaPozycja.x = rand() % this->mapa->GetRozmiar_x();
            if (!this->mapa->GetOrganizmNaKafelku(losowaPozycja.y, losowaPozycja.x))
            {
                organizmy[i]->rodzeniePotomka(losowaPozycja);
            }
        }
    }

    Wspolrzedne pozCzlowieka;
    pozCzlowieka.y = rand() % this->mapa->GetRozmiar_y();
    pozCzlowieka.x = rand() % this->mapa->GetRozmiar_x();

    while (this->mapa->GetOrganizmNaKafelku(pozCzlowieka.y, pozCzlowieka.x))
    {
        pozCzlowieka.y = rand() % this->mapa->GetRozmiar_y();
        pozCzlowieka.x = rand() % this->mapa->GetRozmiar_x();
    }

    new Czlowiek (this, pozCzlowieka.y, pozCzlowieka.x);

}

std::string Swiat::GetWejscie()
{
    return this->wejscie;
}

void Swiat::SetWejscie(std::string wejscie)
{
    this->wejscie = wejscie;
}

void Swiat::dodajOrganizm(Organizm &org)
{
    this->organizmy->dodaj(org);
    mapa->SetOrganizmNaKafelku(org.GetPozycja().y, org.GetPozycja().x, &org);
}

unsigned int Swiat::GetTury()
{
    return tury;
}

void Swiat::zapis()
{
    std::ofstream zapisyGry;
    zapisyGry.open("zapisyGry.txt");
    if (zapisyGry.is_open()) {
        Element* temp = this->organizmy->pierwszyElement();
        zapisyGry << GetTury() << '\n';
        zapisyGry << this->mapa->GetRozmiar_y() << '\n' << this->mapa->GetRozmiar_x() << '\n';
        while (temp)
        {
            zapisyGry << temp->organizm->GetGatunek() << ';';
            zapisyGry << temp->organizm->GetPozycja().y << ';';
            zapisyGry << temp->organizm->GetPozycja().x << ';';
            zapisyGry << temp->organizm->GetDlugoscZycia() << ';';
            if (temp->organizm->GetGatunek() == CZLOWIEK_GATUNEK)
            {
                Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(temp->organizm);
                zapisyGry << czlowiek->GetCzasUmiejetnosci() << ';';
            }
            zapisyGry << '\n';
            temp = temp->nastepny;
        }
        zapisyGry.close();
    }
    else
    {
        std::cerr << "blad otworzenia pliku";
    }
}

void Swiat::czyszczenie(int y, int x, unsigned int tury)
{
    delete this->mapa;
    delete this->organizmy;
    this->mapa = new Mapa (y, x);
    this->organizmy = new ListaOrganizmow;
    this->tury = tury;
}

void Swiat::wczytanieZapisy()
{

    std::string line;
    std::ifstream zapisyGry;
    zapisyGry.open("zapisyGry.txt");
    if (zapisyGry.is_open())
    {
        getline(zapisyGry, line);
        unsigned int tury = std::stoi(line);

        getline(zapisyGry, line);
        int y = std::stoi(line);

        getline(zapisyGry, line);
        int x = std::stoi(line);

        this->czyszczenie(y, x, tury);
        while (getline(zapisyGry, line))
        {
            int i = 0;
            std::string gatunek = this->wczytanieGatunek(line, i);
            i++;
            Wspolrzedne poz = this->wczytaniePoz(line, i);
            i++;
            int dlugoscZycia = wczytanieDlugoscZycia(line, i);
            if (gatunek == CZLOWIEK_GATUNEK)
            {
                i++;
                int czasUmiejetnosci = wczytanieCzasuUmiejetnosci(line, i);
                dodawanieCzlowieka(poz, dlugoscZycia, czasUmiejetnosci);
            }
            else
            {
                dodawanieDanegoGatunku(gatunek, poz, dlugoscZycia);
            }

        }
    }
    else
    {
        std::cerr << "blad otworzenia pliku";
    }
}

std::string Swiat::wczytanieGatunek(std::string line, int &i)
{
    std::string gatunek;
    while (line[i] != ';')
    {
        gatunek.push_back(line[i]);
        i++;
    }
    return gatunek;
}

int Swiat::wczytanieCzasuUmiejetnosci(std::string line, int &i)
{
    std::string umejka;
    while (line[i] != ';')
    {
        umejka.push_back(line[i]);
        i++;
    }
    int umejka_int = std::stoi(umejka);
    return umejka_int;
}

Wspolrzedne Swiat::wczytaniePoz(std::string line, int &i)
{
    std::string poz_y;
    while (line[i] != ';')
    {
        poz_y.push_back(line[i]);
        i++;
    }
    i++;
    std::string poz_x;
    while (line[i] != ';')
    {
        poz_x.push_back(line[i]);
        i++;
    }
    Wspolrzedne poz;
    poz.y = std::stoi(poz_y);
    poz.x = std::stoi(poz_x);
    return poz;
}

int Swiat::wczytanieDlugoscZycia(std::string line, int &i)
{
    std::string dlugoscZycia_s;
    while (line[i] != ';')
    {
        dlugoscZycia_s.push_back(line[i]);
        i++;
    }
    int dlugoscZycia = std::stoi(dlugoscZycia_s);
    return dlugoscZycia;
}

void Swiat::dodawanieCzlowieka(Wspolrzedne poz, int dlugoscZycia, int czasUmiejetnosci)
{
    Czlowiek* nowy = new Czlowiek(this, poz.y, poz.x);
    nowy->SetDlugoscZycia(dlugoscZycia);
    nowy->SetCzasUmiejetnosci(czasUmiejetnosci);
}

void Swiat::dodawanieDanegoGatunku(std::string gatunek, Wspolrzedne poz, int dlugoscZycia)
{
    Organizm* nowy;
    if (gatunek == ANTYLOPA_GATUNEK)
    {
        nowy = new Antylopa(this, poz.y, poz.x);
    }
    else if (gatunek == BARSZCZ_GATUNEK)
    {
        nowy = new Barszcz_Sosnowskiego(this, poz.y, poz.x);
    }
    else if (gatunek == GUARANA_GATUNEK)
    {
        nowy = new Guarana(this, poz.y, poz.x);
    }
    else if (gatunek == LIS_GATUNEK)
    {
        nowy = new Lis(this, poz.y, poz.x);
    }
    else if (gatunek == MLECZ_GATUNEK)
    {
        nowy = new Mlecz(this, poz.y, poz.x);
    }
    else if (gatunek == OWCA_GATUNEK)
    {
        nowy = new Owca(this, poz.y, poz.x);
    }
    else if (gatunek == TRAWA_GATUNEK)
    {
        nowy = new Trawa(this, poz.y, poz.x);
    }
    else if (gatunek == WILCZA_JAGODA_GATUNEK)
    {
        nowy = new Wilcza_Jagoda(this, poz.y, poz.x);
    }
    else if (gatunek == WILK_GATUNEK)
    {
        nowy = new Wilk(this, poz.y, poz.x);
    }
    else if (gatunek == ZOLW_GATUNEK)
    {
        nowy = new Zolw(this, poz.y, poz.x);
    }
    else
    {
        std::cerr << "Nieznany gatunek";
        nowy = nullptr;
    }
    if (nowy)
    {
        nowy->SetDlugoscZycia(dlugoscZycia);
        this->dodajOrganizm(*nowy);
    }

}

Swiat::~Swiat()
{
    delete mapa;
    delete this->organizmy;
}