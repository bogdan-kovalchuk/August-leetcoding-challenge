#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> m;
        int p_len = 0, odd_num = 0;
        for (const auto &ch : s) m[ch]++;

        for (const auto &item : m) {
            if (item.second % 2 == 0) {
                p_len += item.second;
            } else if (item.second > 2 && item.second % 2 != 0){
                p_len += item.second - 1;
                ++odd_num;
            } else {
                ++odd_num;
            }
        }
        return odd_num > 0 ? p_len + 1 : p_len;
    }
};

int main() {
    string s = "abccccdd";
    Solution solution;
    std::cout << solution.longestPalindrome(s) << std::endl;
    return 0;
}

