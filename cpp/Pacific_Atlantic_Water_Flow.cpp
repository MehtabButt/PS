#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

class Solution {
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, stack<pair<int, int>>& s) {
        pair<int, int> p;
        int new_i, new_j;
        int r = heights.size(), c = heights[0].size();
        while(!s.empty()) {
            p = s.top();
            s.pop();

            for(int i=0; i<4; i++) {
                new_i = p.first + x[i], new_j = p.second + y[i];
                if(new_i >= 0 and new_j >= 0 and new_i < r and new_j < c and !visited[new_i][new_j] and heights[new_i][new_j] >= heights[p.first][p.second]) {
                    s.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        stack<pair<int, int>> s_p, s_a;
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> visited_p = vector(r, vector(c, false));
        vector<vector<bool>> visited_a = vector(r, vector(c, false));
        vector<vector<int>> out;

        for(int i=0; i<r; i++) {
            visited_p[i][0] = true;
            visited_a[i][c-1] = true;
            s_p.push({i, 0});
            s_a.push({i, c-1});
        }
        for(int j=0; j<c-1; j++) {
            visited_p[0][j+1] = true;
            visited_a[r-1][j] = true;
            s_p.push({0, j+1});
            s_a.push({r-1, j});
        }

        dfs(heights, visited_p, s_p);
        dfs(heights, visited_a, s_a);

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(visited_p[i][j] and visited_a[i][j]) out.push_back({i, j});
            }
        }

        return out;
    }
};

int main(){
    vector<vector<int>> inp = {{10,10,10},{10,1,10},{10,10,10}};
    Solution sol;
    vector<vector<int>> out = sol.pacificAtlantic(inp);
    return 0;
}
