#include "common.h"
//not checked yet

/*
 * Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        bleaf = false;
        pchild.assign(26, nullptr);
    }
    bool bleaf;
    vector<TrieNode*> pchild;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.length();
        if(len == 0)
            return ;
        TrieNode** pp = &root;

        for (int i = 0; i < len; ++i) {
            int ch = (int)word[i] - 'a';
            if((*pp)->pchild[ch] == nullptr)
                (*pp)->pchild[ch] = new TrieNode();
            pp = &((*pp)->pchild[ch]);
        }
        (*pp)->bleaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int len = word.length();
        if(len == 0)
            return false;
        TrieNode** pp =&root;
        for (int i = 0; i < len; ++i) {
            int ch = (int) word[i] - 'a';
            if((*pp)->pchild[ch] == nullptr){
                return false;
            }
            pp = &((*pp)->pchild[ch]);
        }
        return (*pp)->bleaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();
        if(len == 0)
            return true;
        TrieNode** pp = &root;
        for (int i = 0; i < len; ++i) {
            int ch = (int)prefix[i] - 'a';
            if((*pp)->pchild[ch] == nullptr){
                return false;
            }
            pp = &((*pp)->pchild[ch]);
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
 Trie trie;
 trie.insert("somestring");
 trie.search("key");
    return 1;
}