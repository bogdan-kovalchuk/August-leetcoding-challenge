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
// --- Alternative: recursive division by 4 ---
// Time O(log4 n), Space O(log4 n) stack
// Edge cases: n<=0 returns false; n=1 returns true (4^0 = 1)
// Compare: log approach is O(1) but uses floats; recursion is exact
// integer math with O(log n) overhead
class SolutionRecurse {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 4 != 0) return false;
        return isPowerOfFour(n / 4);
    }
};
// --- Alternative: iterative modulo check ---
// Time O(log4 n), Space O(1)
// Edge cases: n<=0 returns false; handles INT_MAX safely (no overflow)
// Compare: same logic as recursive but O(1) space; vs log approach,
// avoids all floating-point concerns
class SolutionIterative {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};