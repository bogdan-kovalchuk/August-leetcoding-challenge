#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    // Hash map counting: O(n) time, O(sigma) space where sigma = distinct chars
    // unordered_map has higher constant factor than fixed array for ASCII input
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

class SolutionArray {
public:
    // Fixed array counting: O(n) time, O(1) space (128-int array for ASCII)
    // Avoids hash overhead; direct index by char value
    int longestPalindrome(string s) {
        int counts[128] = {};
        for (char c : s) counts[c]++;
        int len = 0;
        bool has_odd = false;
        for (int i = 0; i < 128; ++i) {
            len += counts[i] / 2 * 2;
            if (counts[i] % 2) has_odd = true;
        }
        return len + (has_odd ? 1 : 0);
    }
};

int main() {
    Solution orig;
    SolutionArray arr;
    string tests[] = {"abccccdd", "a", "bb", "abcdef", "aaaaaacccccccccc"};
    const char *labels[] = {"mixed", "single", "pair", "all_unique", "heavy_repeat"};
    for (int t = 0; t < 5; ++t) {
        int r1 = orig.longestPalindrome(tests[t]);
        int r2 = arr.longestPalindrome(tests[t]);
        std::cout << labels[t] << ": orig=" << r1 << " array=" << r2
                  << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    }
    return 0;
}

