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


// --- Alternative: bit manipulation ---
// Time O(1), Space O(1)
// Edge cases: n<=0 returns false; mask 0x55555555 checks odd bit positions
// Compare: original uses floating-point log which risks precision errors;
// bit trick is exact integer arithmetic - no rounding issues
class SolutionBit {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};