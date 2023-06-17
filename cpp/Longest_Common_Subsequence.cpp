#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> memo;
    int LCS(string text1, string text2, int i, int j) {
        if(i<0 or j<0) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(text1[i] == text2[j]) {
            return memo[i][j] = 1 + LCS(text1, text2, i-1, j-1);
        }
        else {
            return memo[i][j] = max(
                LCS(text1, text2, i, j-1),
                LCS(text1, text2, i-1, j)
            );
        }
    }

    int max(int v1, int v2) {
        return v1 > v2 ? v1 : v2;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        this->memo = vector(text1.length(), vector<int>(text2.length(), -1));
        return this->LCS(text1, text2, text1.length()-1, text2.length()-1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("ezupkr", "ubmrapg") << endl;
    return 0;
}
