#include "seuraaja.h"

using namespace std;

seuraaja::seuraaja(string n)
{
    nimi = n;
    cout << " Luodaan seuraaja " << nimi << endl;
}

void seuraaja::paivitys(string viesti)
{
    cout << nimi << " sai viestin: " << viesti <<endl;
}

string seuraaja::getNimi() const
{
    return nimi;
}

