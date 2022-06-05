#include <string>
#include <iostream>
#include "Swiat.h"
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
#include <time.h>
#include "Czlowiek.h"



using namespace std;

void clear()
{
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
}

int main() {

        srand(time(nullptr));
        Swiat *swiat = new Swiat;
        string wejscie = "!";

        while (wejscie != "quit") {
            clear();
            cout << "Kacper Chodubski 188864" << endl;
            swiat->nastepnaTura();
            cout << "Tura: " << swiat->GetTury() << endl;
            swiat->mapa->rysowanie();
            cin >> wejscie;
            swiat->SetWejscie(wejscie);
        }

    return 0;
}
