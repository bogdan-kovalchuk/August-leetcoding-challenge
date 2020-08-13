#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        for (int i = 0; i < (1 << characters.size()); ++i) {
            string s;
            for (int j = 0; j < characters.size(); ++j) {
                //  1<<j shifts the 1 for j places and then we check j-th binary digit of i
                if (i & (1 << j)) {
                    s += characters[j];
                }
            }
            if (s.size() == combinationLength) {
                combinations.push_back(s);
            }
        }
        combinations_len = combinations.size();
    }

    string next() {
        return combinations[i++];
    }

    bool hasNext() {
        bool out = true;
        if (i >= combinations_len)
            out = false;
        return out;
    }

private:
    vector<string> combinations;
    int combinations_len;
    int i = 0;
};

int main() {
    auto iterator = new CombinationIterator("abc", 2); // creates the iterator.

    std::cout << iterator->next() << std::endl; // returns "ab"
    std::cout << iterator->hasNext() << std::endl; // returns true
    std::cout << iterator->next() << std::endl; // returns "ac"
    std::cout << iterator->hasNext() << std::endl; // returns true
    std::cout << iterator->next() << std::endl; // returns "bc"
    std::cout << iterator->hasNext() << std::endl; // returns false

    return 0;
}

