#include <iostream>
#include <random>

int rand7() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 7); // define the range

    return distr(gen);
}

class Solution {
public:
    int rand10() {
        int n = 40;
        while (n >= 40) {
            n = (rand7() - 1) * 7 + rand7() - 1;
        }
        return n % 10 + 1;;
    }
};

int main() {
    Solution solution;
    for (int i = 0; i < 100; ++i) {
        std::cout << solution.rand10() << std::endl;
    }
    return 0;
}

