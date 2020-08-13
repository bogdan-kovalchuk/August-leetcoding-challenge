#include <iostream>
#include <string>

using std::string;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {

    }

    string next() {

    }

    bool hasNext() {

    }
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

