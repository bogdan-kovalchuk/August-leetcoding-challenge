#include <iostream>
#include <string>

using std::string;

class Trie {
    Trie *node[26];
    bool endOfTheWord = false;
    friend class WordDictionary;
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
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() = default;

    /** Adds a word into the data structure. */
    void addWord(const string& word) {
        trie->insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(std::move(word), trie);
    }

private:
    Trie *trie = new Trie();

    bool search(string word, Trie *node) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (!node->node[c - 'a']) {
                    return false;
                }
                node = node->node[c - 'a'];
            } else {
                bool found = false;
                int j = 0;
                for (; j < 26; j++) {
                    if (node->node[j]) {
                        found |= search(word.substr(i + 1), node->node[j]);
                    }
                    if (found) return true;
                }
                if (j == 26) return false;
            }
        }
        return node->endOfTheWord;
    }
};

int main() {
    auto dict = new WordDictionary();

    dict->addWord("bad");
    dict->addWord("dad");
    dict->addWord("mad");

    std::cout << dict->search("pad") << std::endl;
    std::cout << dict->search("bad") << std::endl;
    std::cout << dict->search(".ad") << std::endl;
    std::cout << dict->search("b..") << std::endl;

    return 0;
}
