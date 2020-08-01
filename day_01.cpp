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

