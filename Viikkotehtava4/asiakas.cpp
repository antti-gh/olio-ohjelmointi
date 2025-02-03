#include "asiakas.h"
#include <iostream>

Asiakas::Asiakas(string n, double luottoraja) : nimi(n), luottotili(luottoraja) {}

void Asiakas::showSaldo() {
    cout << "\nAsiakas: " << nimi << endl;
    cout << "Kayttotilin saldo: " << kayttotili.getBalance() << " euroa" << endl;
    cout << "Luottotilin saldo: " << luottotili.getLuottoraja() << " euroa" << endl;
}


bool Asiakas::talletus(double amount) { return kayttotili.deposit(amount); }
bool Asiakas::nosto(double amount) { return kayttotili.withdraw(amount); }
bool Asiakas::luotonMaksu(double amount) { return luottotili.deposit(amount); }
bool Asiakas::luotonNosto(double amount) { return luottotili.withdraw(amount); }

bool Asiakas::tiliSiirto(double amount, Asiakas &vastaanottaja) {
    if (nosto(amount)) {
        return vastaanottaja.talletus(amount);
    }
    return false;
}

