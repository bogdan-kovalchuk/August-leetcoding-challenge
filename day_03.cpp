#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    bool isPalindrome(const string &s) {
        string str;
        char delta = 'a' - 'A';
        for (auto ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                str += ch + delta;
            } else if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z') {
                str += ch;
            }
        }
        return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";

    Solution solution;
    std::cout << solution.isPalindrome(s) << std::endl;

    return 0;
}



