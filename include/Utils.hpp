#ifndef ECONOMY_UTILS_HPP
#define ECONOMY_UTILS_HPP
#include <random>
class Utils {
public:
    static int randomBetween(int a, int b) {

        // Seed with a real random value, if available
        std::random_device r;

        // Choose a random mean between 1 and 6
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(a, b);
        int mean = uniform_dist(e1);

        return mean;
    }
};
#endif