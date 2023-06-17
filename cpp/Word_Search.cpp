#include <iostream>
#include <vector>
using namespace std;

#define dir 4

int x[] = {-1, 1,  0, 0};
int y[] = {0,  0, -1, 1};

class Solution {
    int m, n;
    bool exist_util(vector<vector<char>>& board, pair<int,int> pos, vector<vector<bool>>& visited, string word, int idx) {
        if(idx >= word.length()) return true;
        if(pos.first<0 or pos.first>=m or pos.second<0 or pos.second>=n or visited[pos.first][pos.second]) return false;
        if(board[pos.first][pos.second] != word[idx]) return false;

        pair<int, int> new_pos;
        visited[pos.first][pos.second] = true;
        int d;
        for(d=0; d<dir; d++) if(exist_util(board, {pos.first+y[d], pos.second+x[d]}, visited, word, idx+1)) break;
        visited[pos.first][pos.second] = false;
        return d < dir;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited = vector(board.size(), vector(board[0].size(), false));
        this->m = board.size(), this->n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    if(exist_util(board, {i,j}, visited, word, 0)) return true;
                }
            }
        }

        return false;
    }
};

int main(){
    vector<vector<char>> inp = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    Solution sol;
    cout <<sol.exist(inp, "ABCCED") <<endl;

    return 0;
}
