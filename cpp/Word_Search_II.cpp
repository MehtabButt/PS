#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TrieNode {
    bool is_word;
    TrieNode *child[26];
    TrieNode() {
        is_word = false;
        for(int i=0; i<26; i++) child[i]=nullptr;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    TrieNode* get_root() {
        return root;
    }
    void insert(string word) {
        TrieNode *cur = root;
        int k;
        for(int i=0; i<word.length(); i++) {
            k = word[i]-'a';
            if(cur->child[k] == nullptr) cur->child[k] = new TrieNode();
            cur = cur->child[k];
        }
        cur->is_word = true;
    }
    void run_dfs(vector<vector<char>>& board, int i, int j, string prefix, unordered_set<string>& out, TrieNode* cur, vector<vector<bool>>& visited) {
        if(i<0 or j<0 or i>board.size()-1 or j>board[0].size()-1 or visited[i][j]) return;

        visited[i][j] = true;
        int k = board[i][j] - 'a';
        string pref = prefix + board[i][j];


        if(cur->child[k] != nullptr) {
            TrieNode* new_cur = cur->child[k];
            if(new_cur->is_word) out.insert(pref);
            run_dfs(board, i-1, j, pref, out, new_cur, visited);

            new_cur = cur->child[k];
            run_dfs(board, i+1, j, pref, out, new_cur, visited);

            new_cur = cur->child[k];
            run_dfs(board, i, j-1, pref, out, new_cur, visited);

            new_cur = cur->child[k];
            run_dfs(board, i, j+1, pref, out, new_cur, visited);
        }

        visited[i][j] = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        unordered_set<string> out;
        vector<vector<bool>> visited;
        for(int i=0; i<board.size(); i++) {
            vector<bool> temp;
            for(int j=0; j<board[i].size(); j++) {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        for(auto word : words) trie.insert(word);

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                trie.run_dfs(board, i, j, "", out, trie.get_root(), visited);
            }
        }
        return vector(out.begin(), out.end());
    }
};

int main(){
    vector<vector<char>> board {{'o','a','b','n'},{'o','t','a','e'},{'a','h','k','r'},{'a','f','l','v'}};
    vector<string> words {"eat", "oath", "krv", "iflv", "aaen", "oa", "oaa"};

    Solution sol;
    vector<string> out = sol.findWords(board, words);
    return 0;
}
