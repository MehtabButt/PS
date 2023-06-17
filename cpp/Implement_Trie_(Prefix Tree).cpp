#include <iostream>
using namespace std;

struct TrieNode {
    bool is_word;
    TrieNode *child[26];
    TrieNode() {
        is_word = false;
        for(int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        int k;
        TrieNode *cur = this->root;
        for(int i=0; i<word.length(); i++) {
            k = word[i] - 'a';
            if(cur->child[k] == nullptr) cur->child[k] = new TrieNode();
            cur = cur->child[k];
        }
        cur->is_word = true;
    }

    bool search(string word) {
        int k;
        TrieNode *cur = root;
        for(int i=0; i<word.length(); i++) {
            k = word[i] - 'a';
            if(cur->child[k] == nullptr) return false;
            cur = cur->child[k];
        }
        return cur->is_word;
    }

    bool startsWith(string prefix) {
        int k;
        TrieNode *cur = root;
        int i=0;
        for(; i<prefix.length(); i++) {
            k = prefix[i] - 'a';
            if(cur == nullptr) break;
            cur = cur->child[k];
        }
        return i != 0 and cur != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // return True
    cout << trie.search("app") << endl;     // return False
    cout << trie.startsWith("app") << endl; // return True
    trie.insert("app");
    cout << trie.search("app") << endl;     // return True
    return 0;
}
