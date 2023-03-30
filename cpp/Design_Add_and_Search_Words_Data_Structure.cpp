#include <iostream>
using namespace std;

struct WordNode {
    bool is_word;
    string children;
    WordNode *child[26];
    WordNode() {
        is_word = false;
        children = "";
        for(int i=0; i<26; i++) child[i] = NULL;
    }
};

class WordDictionary {
    WordNode *root;
    bool search_char(string word, int idx, WordNode *cur) {
        if(idx == word.length()) return cur->is_word;
        if(word[idx] != '.') {
            int k = word[idx] - 'a';
            if(cur->child[k] == NULL) return false;
            return search_char(word, idx+1, cur->child[k]);
        }
        else {
            WordNode *new_cur = cur;
            for(char c : cur->children) {
                cur = new_cur->child[c-'a'];
                if(search_char(word, idx+1, cur)) return true;
            }
            return false;
        }
    }
public:
    WordDictionary() {
        root = new WordNode;
    }

    void addWord(string word) {
        int k;
        WordNode *cur = root;
        for(int i=0; i<word.length(); i++) {
            k = word[i] - 'a';
            if(cur->child[k] == NULL) {
                cur->child[k] = new WordNode();
                cur->children += word[i];
            }
            cur = cur->child[k];
        }
        cur->is_word = true;
    }

    bool search(string word) {
        return search_char(word, 0, root);
    }
};
