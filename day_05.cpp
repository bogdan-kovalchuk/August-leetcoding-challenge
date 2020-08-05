#include <iostream>
#include <string>

using std::string;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {

    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {

    }
};

int main(){
    auto dict = new WordDictionary();

    dict->addWord("bad");
    dict->addWord("dad");
    dict->addWord("mad");
    dict->addWord("pad");

    std:: cout << dict->search("bad") << std::endl;
    std:: cout << dict->search(".ad") << std::endl;
    std:: cout << dict->search("b..") << std::endl;

    return 0;
}
