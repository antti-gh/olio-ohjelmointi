#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {}

void Notifikaattori::lisaa(seuraaja *seur)
{
    cout << "Lisataan seuraaja" << seur->getNimi() <<endl;
    seur-> next = seuraajat;
    seuraajat = seur;
}

void Notifikaattori::poista(seuraaja *poist)
{
    if (poist == seuraajat) {
        seuraajat = seuraajat->next;
    } else {
        seuraaja *alku = seuraajat;
        while(alku != nullptr) {
            if (alku->next == poist->next) {
                alku = alku->next;
            }
            alku = alku->next;

            }
            }
}
void Notifikaattori::tulosta()
{
    seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        cout << "Listassa nyt=" << alku->getNimi() << endl;
        alku = alku->next;
        if (alku != nullptr) {
            cout << "Listassa seuraava=" << alku->getNimi() <<endl;
        } else {
            cout << "Lista loppui";
        }
    }
        cout <<endl;
}

void Notifikaattori::postita(string viesti)
{
    seuraaja *alku = seuraajat;
    while(alku !=nullptr) {
        alku->paivitys(viesti);
        alku = alku->next;
    }
    cout << endl;
}


