#include <iostream>
#include <time.h>
#include <stdlib.h>

unsigned long long coinFlip(unsigned row);

int WinMain(){
    std::cout << "Coin flip streak game\n";

    while (true){
    srand(time(NULL));
    double games = 0;
    unsigned inARow = 0;
    long double average = 0;
    std::cout << std::endl << "What streak you desire: ";
    std::cin >> inARow;
    std::cout << std::endl << "In how many games: ";
    std::cin >> games; std::cout << std::endl;

    for (unsigned i = 0; i < games; i++){
        average += coinFlip(inARow)/games;
    }
    std::cout << "Average of " << average << " tries in " << games << " games, to get a " << inARow << " streak! A " << 1/average*100 << "\% chance to get it!" << std::endl;
    }

    return 0;
}

unsigned long long coinFlip(unsigned row){
    unsigned long long tries = 1;
    unsigned count = 0;
    while (true){
        unsigned rng = rand() % 2;
        switch (rng){
            case 0:
                count = 0;
                tries += 1;
                break;
            case 1:
                count += 1;
                break;
        }
        if (count == row){
            return tries;
        }
    }
}