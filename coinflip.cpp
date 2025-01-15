#include <iostream>
#include <time.h>

size_t coinFlip(unsigned row){
    size_t tries = 1ull;
    unsigned count = 0;
    while (true){
        if(rand() % 2){
            count = 0;
            tries += 1ull;
        } else {
                count += 1;
        }
        if (count == row){
            return tries;
        }
    }
}

int main(){
    std::cout << "Coin flip streak game\n";

    while (true){
    srand(time(0ull));
    double games = 0.0;
    unsigned inARow = 0u;
    double average = 0.0;
    std::cout << '\n' << "What streak do you desire? ";
    std::cin >> inARow;
    std::cout << '\n' << "In how many games? ";
    std::cin >> games;
    if(!inARow || !games) return 0;
    std::cout << '\n';

    for (unsigned i = 0; i < games; i++){
        average += coinFlip(inARow) / games;
    }
    std::cout << "Average of " << average << " tries in " << games << " games, to get a " << inARow << " streak! A " << 100 / average << "% chance to get it!" << '\n';
    }
}
