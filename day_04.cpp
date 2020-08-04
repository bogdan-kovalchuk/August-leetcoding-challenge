#include <iostream>
#include <math.h>

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num > 0) {
            double res = log(num) / log(4);
            return res == static_cast<double>(int(res));
        }
        return false;
    }
};

int main() {
    int num = 5;
    Solution solution;
    std::cout << solution.isPowerOfFour(num) << std::endl;

    return 0;
}

