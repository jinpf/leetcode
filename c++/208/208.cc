#include <iostream>
#include <memory.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

class TrieNode {
public:
    int count;
    // record next word 
    TrieNode* next[26]; 
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * p = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!p->next[index]) {
                TrieNode * tmp = new TrieNode();
                p->next[index] = tmp;
            }
            p = p->next[index];
        }
        p->count += 1;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * p = root;
        for(int i = 0; i < word.size(); ++i) {
            if (!p->next[word[i]-'a'])
                return false;
            p = p->next[word[i]-'a'];
        }
        if (p->count == 0)
            return false;
        else
            return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * p = root;
        for(int i = 0; i < prefix.size(); ++i) {
            if (!p->next[prefix[i]-'a'])
                return false;
            p = p->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
    
    
};


int main()
{
	Trie t;
    t.insert("somestring");
    std::cout << t.search("somestring") << t.startsWith("some")<< std::endl;
}