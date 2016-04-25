#include <random>
#include <iostream>


int state_gen() {
    std::random_device generator;
    std::exponential_distribution<double> distribution(4.0);
    double rand = distribution(generator);
    if (rand < 0.4)
        return 3;
    else if (rand >= 0.4 && rand < 0.8)
        return 2;
    else 
        return 1;
}

int main () {
    std::random_device generator;
    std::uniform_int_distribution<int> wind_dist(1, 6);
    std::exponential_distribution<double> state_dist(2.0);
    int dice_roll = wind_dist(generator);
    double state_roll = state_dist(generator);
    std::cout << dice_roll << std::endl;
    std::cout << state_roll << std::endl;
    std::cout << state_gen() << std::endl;
    return 0;
}
