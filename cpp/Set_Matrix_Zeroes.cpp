#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col = true;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j == 0) col = false;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(!j) {
                    if(!col) matrix[i][j] = 0;
                }
                else if(!matrix[i][0] or !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){

    return 0;
}
