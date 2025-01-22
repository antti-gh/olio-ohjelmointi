#include "Chef.h"
#include <iostream>
#include <algorithm>
using namespace std;


Chef::Chef(string name) : chefName(name) {
    cout << "Chef " << chefName << " Konstruktori" << endl;
}

Chef::~Chef() {
    cout << "Chef " << chefName << " Destruktori" << endl;
}

int Chef::makeSalad(int ingredients) {
    int portions = ingredients / 5;
    cout << " Chef " << chefName << " can make " << portions << " salad portions with these items." << endl;
    return portions;
}

int Chef::makeSoup(int ingredients) {
    int portions = ingredients / 3;
    cout << " Chef " << chefName << " can make " << portions << " soup portions with these items." << endl;
    return portions;
}

ItalianChef::ItalianChef(string name) : Chef(name), password("pizza") {
    cout << "ItalianChef " << chefName << " Konstruktori " << endl;
}

ItalianChef::~ItalianChef() {
    cout << "ItalianChef " << chefName << " Destruktori " << endl;
}

int ItalianChef::makePizza(int flour, int water) {
    int maxPortions = min(flour / 5, water / 5);
    cout << " Chef " << chefName << " Can make " << maxPortions << " pizzas with this amount of water and flour." << endl;
    return maxPortions;
}

bool ItalianChef::askSecret(string givenPassword, int flour, int water) {
    cout << "ItalianChef " << chefName << " checks the password " << endl;
    if (password.compare(givenPassword) == 0) {
        cout << "Password correct!" << endl;
        makePizza(flour, water);
        return true;
    } else {
        cout << "Wrong password!" << endl;
        return false;
    }
}
