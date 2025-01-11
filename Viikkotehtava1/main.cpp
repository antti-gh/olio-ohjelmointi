#include <iostream>
#include <cstdlib>
#include <ctime>

int game (int maxnum) {
    int oikea_luku = std::rand() % maxnum + 1;
    int arvaus = 0;
    int arvausten_maara = 0;

    std::cout << "Arvaa luku valilta 1-" << maxnum <<  "!" << std::endl;

    while (arvaus != oikea_luku) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> arvaus;
        arvausten_maara++;

        if (arvaus < oikea_luku) {
            std::cout << "Luku on suurempi!" << std::endl;
        } else if (arvaus > oikea_luku) {
            std::cout << "Luku on pienempi!" << std::endl;
        } else {
            std::cout << "Oikea vastaus! Luku oli:" << oikea_luku << "." << std::endl;
        }
}
    return arvausten_maara;
}

int main()
{
    std::srand(std::time(0));

    int maxnum;
    std::cout << "Anna korkein etsittava luku:";
    std::cin >> maxnum;
    int arvausten_maara = game(maxnum);
    std::cout << "Arvasit: " << arvausten_maara << "kertaa." << std::endl;
    return 0;
}
