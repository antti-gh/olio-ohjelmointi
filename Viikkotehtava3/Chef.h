#ifndef CHEF_H
#define CHEF_H

#include <string>
using namespace std;

class Chef {
protected:
    string chefName;

public:
    Chef(string);
    ~Chef();
    string getName();
    int makeSalad(int);
    int makeSoup(int);
};

class ItalianChef : public Chef {
private:
    string password = "pizza";
    int flour;
    int water;
    int makePizza(int, int);

public:
    ItalianChef(string);
    ~ItalianChef();
    bool askSecret(string, int, int);
};

#endif
