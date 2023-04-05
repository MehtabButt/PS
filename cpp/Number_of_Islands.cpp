#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

class Solution {
    int islands;

    void dfs(vector<vector<char>>& grid, pair<int, int> idx, vector<vector<bool>>& visited, pair<int, int> dim) {
        islands += 1;
        stack<pair<int, int>> s;
        s.push(idx);
        visited[idx.first][idx.second] = true;
        int new_i, new_j;
        pair<int, int> temp;

        while(!s.empty()) {
            temp = s.top();
            s.pop();

            for(int i=0; i<4; i++) {
                new_i = temp.first + y[i], new_j = temp.second + x[i];
                if(new_i >= 0 and new_i < dim.first and new_j >= 0 and new_j < dim.second and !visited[new_i][new_j] and grid[new_i][new_j]=='1') {
                    s.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
    }
public:
    Solution() {
        islands = 0;
    }

    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<bool>> visited = vector(r, vector(c, false));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!visited[i][j] and grid[i][j]=='1') dfs(grid, {i, j}, visited, {r, c});
            }
        }

        return islands;
    }
};

int main(){
    vector<vector<char>> grid = {{'1','1','1'},
                                {'0','1','0'},
                                {'1','1','1'}};
    Solution sol;
    int out = sol.numIslands(grid);
    cout << out << endl;
    return 0;
}
