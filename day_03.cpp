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




// --- Alternative: two-pointer in-place ---
// Time O(n), Space O(1) - no extra string allocation
// Edge cases: empty string is palindrome; single alphanumeric char valid
// Compare: original builds filtered string O(n) space then checks;
// two-pointer skips non-alnum on the fly with zero allocation
class SolutionTwoPtr {
    static bool isAlnum(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
            || (c >= '0' && c <= '9');
    }
    static char toLower(char c) {
        return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
    }
public:
    bool isPalindrome(const string &s) {
        int lo = 0, hi = (int)s.size() - 1;
        while (lo < hi) {
            while (lo < hi && !isAlnum(s[lo])) ++lo;
            while (lo < hi && !isAlnum(s[hi])) --hi;
            if (toLower(s[lo++]) != toLower(s[hi--])) return false;
        }
        return true;
    }
};