#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(seuraaja *seur);
    void poista(seuraaja *poist);
    void tulosta();
    void postita(string viesti);

private:
    seuraaja *seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
