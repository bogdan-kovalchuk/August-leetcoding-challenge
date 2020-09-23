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

// --- Alternative: hash set grouped by word length ---
// Time O(n*m) search worst case with many dots, Space O(total chars stored)
// Edge cases: dots match any single char; length filter prunes non-matches early
// Compare: trie is O(m) for no-dot words but branches 26 ways per dot;
// hash set approach is simpler, uses standard containers, and prunes by length
#include <unordered_map>
#include <unordered_set>
class WordDictionaryHash {
    unordered_map<int, unordered_set<string>> words;
public:
    void addWord(const string& word) {
        words[word.size()].insert(word);
    }
    bool search(const string& word) {
        auto it = words.find(word.size());
        if (it == words.end()) return false;
        for (const auto& w : it->second) {
            bool match = true;
            for (int i = 0; i < (int)word.size(); ++i) {
                if (word[i] != '.' && word[i] != w[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};
// --- Alternative: iterative BFS search with explicit queue ---
// Time O(n * 26^d) worst case with d dots, Space O(queue width)
// Edge cases: avoids stack overflow on deep tries; same correctness as recursive
// Compare: recursive DFS uses call stack O(depth); BFS uses heap queue O(width)
// - BFS may use more memory for wide tries but will not overflow the stack
#include <queue>
class WordDictionaryBFS {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };
    TrieNode* root = new TrieNode();
public:
    void addWord(const string& word) {
        auto* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a'])
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    bool search(const string& word) {
        queue<TrieNode*> q;
        q.push(root);
        for (char c : word) {
            int sz = q.size();
            while (sz--) {
                auto* node = q.front(); q.pop();
                if (c == '.') {
                    for (int i = 0; i < 26; ++i)
                        if (node->children[i])
                            q.push(node->children[i]);
                } else {
                    if (node->children[c - 'a'])
                        q.push(node->children[c - 'a']);
                }
            }
        }
        while (!q.empty()) {
            if (q.front()->isEnd) return true;
            q.pop();
        }
        return false;
    }
};