#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

class Luottotili : public Pankkitili {
protected:
    double luottoraja=0;
public:
    Luottotili(double);
    bool withdraw(double amount) override;
    bool deposit(double amount);
    double getLuottoraja() const { return saldo; }
};

#endif
