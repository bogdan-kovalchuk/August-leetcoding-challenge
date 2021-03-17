#include <iostream>
#include <string>
#include <math.h>

using std::string;

class Solution {
public:
    // Reverse iteration with pow: O(n^2) time due to pow() calls, O(1) space
    // pow(26, i-1) recomputes exponent each iteration
    int titleToNumber(string s) {
        int j = s.size(), result = 0;
        for (int i = j; i >= 1; --i){
            auto ch = s[j - i] - 'A' + 1;
            result += pow(26, i - 1) * ch;
        }
        return result;
    }
};

class SolutionHorner {
public:
    // Horner's method: O(n) time, O(1) space
    // Single left-to-right pass, no repeated exponentiation
    int titleToNumber(string s) {
        int result = 0;
        for (char ch : s) {
            result = result * 26 + (ch - 'A' + 1);
        }
        return result;
    }
};

int main() {
    string tests[] = {"A", "Z", "AA", "AB", "ZY", "FXSHRXW"};
    Solution orig;
    SolutionHorner horner;
    for (const auto &t : tests) {
        int r1 = orig.titleToNumber(t);
        int r2 = horner.titleToNumber(t);
        std::cout << t << ": orig=" << r1 << " horner=" << r2
                  << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    }
    return 0;
}