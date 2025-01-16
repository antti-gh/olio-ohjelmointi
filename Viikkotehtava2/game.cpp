#include "game.h"
#include <iostream>

Game::Game(int mn)
{
    maxNumber = mn;
    cout << "Game konstruktori"
        << "maxNumber"
        << maxNumber
         << endl;
}

Game::~Game()
{
    cout << "Game destruktori"
         << endl;
}

void Game::play()
{
    cout << "Game play"
         << endl;
    // 1. tänne pelilogiikka
    {
        srand(std::time(0));
        randomNumber = (rand()%maxNumber)+1;  //otetaan jakojäännös, nyt pitäisi olla välillä 1-20
        bool stayInLoop = true;
        numOfGuesses = 0;
        while(stayInLoop)
        {
            cout<<"Give your guess between 1-"<<maxNumber<<endl;
            cin>>playerGuess;
            numOfGuesses++;
            if(playerGuess == randomNumber)
            {
                cout<<"Arvasit oikein luku = "<<playerGuess<<endl;
                stayInLoop = false;
            }
            else if(playerGuess<randomNumber)
            {
                cout<<"Lukusi on liian pieni"<<endl;
            }
            else
            {
                cout<<"Lukusi on liian suuri"<<endl;
            }

        }
    }


    // 2. muutetaan käyttämään jäsenmuuttujia
    // nyt jäsenmuuttuja koska pitää välittää arvausten määrä toiselle jäsenfunktiolle

    // 3. Lopuksi kutsutaan toista jäsenfunktiota
    // joka tekee tulostuksen
    printGameResult();
}

void Game::printGameResult()
{
    cout << "Your guess is right "
         << playerGuess
        << "with"
        << numOfGuesses
        << "Guesses"
         <<endl;
}
