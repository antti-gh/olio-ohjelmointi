#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <iostream>
using namespace std;

class seuraaja
{
public:
    seuraaja();

    seuraaja *next = nullptr;
    seuraaja(string n);
    string getNimi() const;
    void paivitys(string viesti);

private:
    string nimi;
};


#endif // SEURAAJA_H
