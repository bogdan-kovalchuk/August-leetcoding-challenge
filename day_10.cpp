#include <iostream>
#include <string>
#include <math.h>

using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int j = s.size(), result = 0;
        for (int i = j; i >= 1; --i){
            auto ch = s[j - i] - 'A' + 1;
            result += pow(26, i - 1) * ch;
        }
        return result;
    }
};

int main() {
    string s = "ZY";

    Solution solution;
    std::cout << solution.titleToNumber(s) << std::endl;

    return 0;
}