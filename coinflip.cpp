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

union num{
    size_t i;
    double d;
};

int main(){
    std::cout << "Coin flip streak game\n";
    num average;

    while (true){
    srand(time(0ull));
    unsigned games = 0u;
    unsigned inARow = 0u;
    average.i = 0ull;
    std::cout << '\n' << "What streak do you desire? ";
    std::cin >> inARow;
    std::cout << '\n' << "In how many games? ";
    std::cin >> games;
    if(!inARow || !games) return 0;
    std::cout << '\n';
    
    if(games == 1){
        average.i = coinFlip(inARow);
        std::cout << average.i << " tries to get a " << inARow << " streak! A " << 100.0 / average.i << "% chance to get it!" << '\n';
    } else {
        for (unsigned i = 0; i < games; i++)
            average.d += coinFlip(inARow) / static_cast<double>(games);
        std::cout << "Average of " << average.d << " tries in " << games << " games, to get a " << inARow << " streak! A " << 100.0 / average.d << "% chance to get it!" << '\n';
    }
    }
}
