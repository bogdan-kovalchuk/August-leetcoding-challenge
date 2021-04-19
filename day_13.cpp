#include <iostream>
#include <string>
#include <set>
#include <vector>

using std::string;
using std::set;
using std::vector;

class CombinationIterator {
public:
    // Bitmask enumeration + sorted set: O(2^n * n) time, O(C(n,k) * k) space
    // Enumerates all 2^n subsets, filters by length, inserts into ordered set
    CombinationIterator(string characters, int combinationLength) {
        for (int i = 0; i < (1 << characters.size()); ++i) {
            string s;
            for (int j = 0; j < characters.size(); ++j) {
                if (i & (1 << j)) {
                    s += characters[j];
                }
            }
            if (s.size() == combinationLength) {
                combinations.insert(s);
            }
        }
        it = begin(combinations);
    }

    string next() {
        return *it++;
    }

    bool hasNext() {
        return !(it == end(combinations));
    }

private:
    set<string> combinations;
    set <string> :: iterator it;
};

class CombinationIteratorBacktrack {
public:
    // Recursive backtracking: O(C(n,k) * k) time, O(C(n,k) * k) space
    // Generates only valid k-length combinations in lexicographic order;
    // avoids enumerating all 2^n subsets
    CombinationIteratorBacktrack(string characters, int combinationLength) {
        string current;
        backtrack(characters, combinationLength, 0, current);
        idx = 0;
    }

    string next() {
        return combinations[idx++];
    }

    bool hasNext() {
        return idx < (int)combinations.size();
    }

private:
    vector<string> combinations;
    int idx;

    void backtrack(const string &chars, int len, int start, string &current) {
        if ((int)current.size() == len) {
            combinations.push_back(current);
            return;
        }
        for (int i = start; i < (int)chars.size(); ++i) {
            current.push_back(chars[i]);
            backtrack(chars, len, i + 1, current);
            current.pop_back();
        }
    }
};

int main() {
    auto test_pair = [](const string &chars, int len, const char *label) {
        CombinationIterator bitmask(chars, len);
        CombinationIteratorBacktrack bt(chars, len);
        std::cout << label << ":";
        while (bitmask.hasNext() && bt.hasNext()) {
            string s1 = bitmask.next();
            string s2 = bt.next();
            std::cout << " " << s1;
            if (s1 != s2) std::cout << "[MISMATCH:" << s2 << "]";
        }
        std::cout << std::endl;
    };

    test_pair("bvwz", 2, "4C2");
    test_pair("abc", 2, "3C2");
    test_pair("abcd", 1, "4C1");
    test_pair("abcde", 3, "5C3");

    return 0;
}

