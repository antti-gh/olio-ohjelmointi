#ifndef PANKKITILI_H
#define PANKKITILI_H


class Pankkitili {

protected:
    double saldo = 0;

public:
    Pankkitili();
    double getBalance() const;
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual ~Pankkitili();
};

#endif
