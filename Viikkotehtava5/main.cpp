#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"
using namespace std;

int main()
{
    seuraaja *A = new seuraaja (" Aapeli ");
    seuraaja *B = new seuraaja (" Beepeli ");
    seuraaja *C = new seuraaja (" Ceepeli ");

    Notifikaattori *N = new Notifikaattori();
    cout << endl;

    N->lisaa(A);
    N->lisaa(B);
    N->lisaa(C);

    N->poista(B);
    N->tulosta();

    N->postita("Tama on viesti");

    /*
    A->next = B;
    B->next = C;

    seuraaja *alku = A;
    while (alku != nullptr) {
        cout << "Listassa nyt=" << alku->getNimi() << endl;
        alku->paivitys("Kaikki ok"); // tehdään silmukassa jotain oliolle	o = o->next
        alku = alku->next;
        if (alku != nullptr) {
        cout << "Listassa seuraava=" << alku->getNimi() <<endl;
    } else {
        cout << "Lista loppui";
    }
    cout <<endl;
*/

    delete A;
    delete B;
    delete C;
    delete N;

    return 0;
}
