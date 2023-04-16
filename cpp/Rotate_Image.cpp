#include <iostream>
#include <vector>
#include <utility>
using namespace std;

enum direction {Right, Down, Left, Up};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        pair<int, int> pos = {0, 0};
        pair<int, int> start;
        int rows = matrix.size(), cols = matrix[0].size();
        int m = matrix.size()-1, n = matrix[0].size()-1;
        int pre, temp, row_steps, back_row_steps, col_steps, back_col_steps;
        direction dir;
        int step = rows-1;

        if(rows*cols == 1) return;

        while(m >= 0 and n >= 0) {
            for(int i=0; i<step; i++) {
                pos.second += min(1, i);
                pre = matrix[pos.first][pos.second];
                if(pos.first == rows-1-m and pos.second == cols-1-n) dir = Right;
                else dir = Down;
                start = pos;
                while(true) {
                    row_steps = n - pos.second;
                    back_row_steps = pos.second - (cols-1-n);
                    col_steps = m - pos.first;
                    back_col_steps = pos.first - (rows-1-m);

                    if(row_steps+col_steps >= step and (dir==Right or dir==Down)) {
                        temp = abs(min(0, row_steps-step));
                        pos.first += temp;
                        pos.second += step - temp;
                    }
                    else if(col_steps+back_row_steps >= step and (dir==Down or dir==Left)) {
                        temp = min(0, col_steps-step);
                        pos.second += temp;
                        pos.first += step - abs(temp);
                    }
                    else if(back_row_steps+back_col_steps >= step and (dir==Left or dir==Up)) {
                        temp = min(0, back_row_steps-step);
                        pos.first += temp;
                        pos.second += abs(temp) - step;
                    }
                    else if(back_col_steps+row_steps >= step and (dir==Up or dir==Right)) {
                        temp = abs(min(0, back_col_steps-step));
                        pos.second += temp;
                        pos.first += temp - step;
                    }

                    if(pos.second==n and pos.first>=cols-1-n and pos.first<n) dir = Down;
                    else if(pos.first==m and pos.second<=n and pos.second>rows-1-m) dir = Left;
                    else if(pos.second==rows-1-m and pos.first<=m and pos.first>cols-1-n) dir = Up;

                    temp = matrix[pos.first][pos.second];
                    matrix[pos.first][pos.second] = pre;
                    pre = temp;

                    if(pos.first == start.first and pos.second == start.second) break;
                }
            }

            m -= 1;
            n -= 1;
            pos.first = cols-1-n;
            pos.second = rows-1-m;
            step -= 2;
        }
    }
};

int main(){
    // vector<vector<int>> inp = {{5,1},{2,4}};
    // vector<vector<int>> inp = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> inp = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> inp = {{1, 2, 3, 4, 5},
                               {6, 7, 8, 9, 10},
                               {11,12,13,14,15},
                               {16,17,18,19,20},
                               {21,22,23,24,25}};

    Solution sol;
    sol.rotate(inp);

    return 0;
}
