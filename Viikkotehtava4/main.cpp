#include "asiakas.h"
#include <iostream>
using namespace std;


int main() {

    Asiakas a1("Aaro", 1000);
    Asiakas a2("Merja", 1000);
    Asiakas a3("Jaakko", 5000);

    cout << "\nAsiakkaat ja tilien saldot:\n";
    a1.showSaldo();
    a2.showSaldo();
    a3.showSaldo();

    a2.talletus(100);
    a2.nosto(50);

    a3.talletus(6000);
    a3.nosto(350);
    a3.luotonNosto(4000);


    a1.tiliSiirto(50, a2);
    a3.tiliSiirto(3000, a1);

    cout << "\nLopulliset saldot tapahtumien jalkeen:\n";
    a1.showSaldo();
    a2.showSaldo();
    a3.showSaldo();

    return 0;
}


