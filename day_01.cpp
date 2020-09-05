#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    static bool detectCapitalUse(string word) {
        if (word.size() <= 1) return true;

        bool lowerIsIncluded = false;
        bool capitalIsIncluded = false;
        auto firsCharCapital = isCapital(word[0]);

        for (int i = 1; i < word.size(); ++i) {
            if (isCapital(word[i])) {
                capitalIsIncluded = true;
            } else {
                lowerIsIncluded = true;
            }

            if (lowerIsIncluded && capitalIsIncluded) return false;
        }

        return !(!firsCharCapital && capitalIsIncluded);
    }

    static bool isCapital(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }
};

int main() {
    string s1 = "Google";
    string s2 = "GooGle";

    std::cout << Solution::detectCapitalUse(s1) << std::endl;
    std::cout << Solution::detectCapitalUse(s2) << std::endl;

    return 0;
}


// --- Alternative: count-based validation ---
// Time O(n), Space O(1) - single pass counting uppercase
// Edge cases: single char always valid; all-lower and all-upper both valid
// Compare: original uses two bool flags tracking mixed case; this counts
// uppercase total and checks three valid patterns directly
class SolutionCount {
public:
    static bool detectCapitalUse(string word) {
        int upper = 0;
        for (char c : word)
            if (c >= 'A' && c <= 'Z') ++upper;
        return upper == 0
            || upper == (int)word.size()
            || (upper == 1 && word[0] >= 'A' && word[0] <= 'Z');
    }
};