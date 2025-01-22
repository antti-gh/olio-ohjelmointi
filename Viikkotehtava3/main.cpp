#include "Chef.h"
#include <iostream>
using namespace std;

int main() {
    Chef basicChef("Gordon");
    basicChef.makeSalad(11);
    basicChef.makeSoup(14);

    ItalianChef italianChef("Mario");
    italianChef.makeSalad(9);
    italianChef.makeSoup(15);

    italianChef.askSecret("pizza", 12, 12);
    italianChef.askSecret("wrong_password", 25, 25);

    return 0;
}
