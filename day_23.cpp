#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
    Trie *node[26];
    bool endOfTheWord = false;
public:
    /** Initialize data structure. */
    Trie() {
        for (auto &n : node) n = nullptr;
        endOfTheWord = false;
    }

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        Trie *curr = this;
        for (const auto &ch : word) {
            if (!curr->node[ch - 'a']) {
                curr->node[ch - 'a'] = new Trie();
            }
            curr = curr->node[ch - 'a'];
        }
        curr->endOfTheWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        if (word.length() == 0) return false;
        Trie *curr = this;
        for (const auto &ch : word) {
            if (curr->node[ch - 'a'])
                curr = curr->node[ch - 'a'];
            else return false;
            if (curr->endOfTheWord) return true;
        }
        return curr->endOfTheWord;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string> &words) {
        for (auto word : words) {
            reverse(word.begin(), word.end());
            length = max(length, (int) word.length());
            trie.insert(word);
        }
    }

    bool query(char letter) {
        str = letter + str;
        if (str.length() > length) str.pop_back();
        return trie.search(str);
    }

private:
    Trie trie;
    string str;
    int length = 0;
};

int main() {
    vector<string> words = {"cd", "f", "kl"};
    auto streamChecker = new StreamChecker(words); // init the dictionary.
    std::cout << streamChecker->query('a') << std::endl; // return false
    std::cout << streamChecker->query('b') << std::endl; // return false
    std::cout << streamChecker->query('c') << std::endl; // return false
    std::cout << streamChecker->query('d') << std::endl; // return true, because 'cd' is in the wordlist
    std::cout << streamChecker->query('e') << std::endl; // return false
    std::cout << streamChecker->query('f') << std::endl; // return true, because 'f' is in the wordlist
    std::cout << streamChecker->query('g') << std::endl; // return false
    std::cout << streamChecker->query('h') << std::endl; // return false
    std::cout << streamChecker->query('i') << std::endl; // return false
    std::cout << streamChecker->query('j') << std::endl; // return false
    std::cout << streamChecker->query('k') << std::endl; // return false
    std::cout << streamChecker->query('l') << std::endl; // return true, because 'kl' is in the wordlist
    return 0;
}

