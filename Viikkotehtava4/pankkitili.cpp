#include "pankkitili.h"

Pankkitili::Pankkitili() : saldo(0) {}

bool Pankkitili::deposit(double amount) {
    if (amount > 0) {
        saldo += amount;
        return true;
    }
    return false;
}

bool Pankkitili::withdraw(double amount) {
    if (amount > 0 && saldo >= amount) {
        saldo -= amount;
        return true;
    }
    return false;
}

double Pankkitili::getBalance() const { return saldo; }

Pankkitili::~Pankkitili() {}
