#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        pair<int, int> pos = {0, 0};
        int m = matrix.size(), n = matrix[0].size();
        int half_rows = ceil((float)m/2), half_cols = ceil((float)n/2);
        vector<int> out;

        while(pos.first < half_rows and pos.second < half_cols) {
            for(int j=pos.second; j<n-pos.second; j++) out.push_back(matrix[pos.first][j]);
            for(int i=pos.first+1; i<m-pos.first; i++) out.push_back(matrix[i][n-pos.second-1]);

            if(m - 2*pos.first - 1 <= 0) break;
            if(n - 2*pos.second - 1 <= 0) break;

            for(int j=n-pos.second-2; j>=pos.second; j--) out.push_back(matrix[m-pos.first-1][j]);
            for(int i=m-pos.first-2; i>pos.first; i--) out.push_back(matrix[i][pos.second]);

            pos.first++;
            pos.second++;
        }

        return out;
    }
};

int main(){
    // vector<vector<int>> inp = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> inp = {{1}};
    Solution sol;

    vector<int> out = sol.spiralOrder(inp);

    return 0;
}
