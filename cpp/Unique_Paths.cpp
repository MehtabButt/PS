#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> memo;
    int unique_paths(int m, int n, int i, int j) {
        if(memo[i][j] != -1) return memo[i][j];

        if(i==m-1 and j==n-1) return 1;

        int ways = 0;
        if(i < m-1) ways += unique_paths(m, n, i+1, j);
        if(j < n-1) ways += unique_paths(m, n, i, j+1);

        return memo[i][j] = ways;
    }
public:
    int uniquePaths(int m, int n) {
        this->memo = vector(m, vector(n, -1));
        return unique_paths(m, n, 0, 0);
    }
};

int main(){
    Solution sol;
    int m, n;
    cin >>m >>n;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}
