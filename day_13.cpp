#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;

class CombinationIterator {
public:
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

int main() {
    auto iterator = new CombinationIterator("bvwz", 2); // creates the iterator.

    std::cout << iterator->next() << std::endl; // returns "ab"
    std::cout << iterator->hasNext() << std::endl; // returns true
    std::cout << iterator->next() << std::endl; // returns "ac"
    std::cout << iterator->hasNext() << std::endl; // returns true
    std::cout << iterator->next() << std::endl; // returns "bc"
    std::cout << iterator->hasNext() << std::endl; // returns false

    return 0;
}

