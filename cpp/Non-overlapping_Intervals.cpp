#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> preInterval = intervals[0];
        int intervalsRemoved = 0;

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] < preInterval[1]) {
                intervalsRemoved++;
                if(preInterval[1] > intervals[i][1]) preInterval = intervals[i];
            } else {
                preInterval = intervals[i];
            }
        }

        return intervalsRemoved;
    }
};

int main() {
    // vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    // vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
    vector<vector<int>> intervals = {{0,2},{1,3},{2,4},{3,5},{4,6}};
    Solution sol;

    cout <<sol.eraseOverlapIntervals(intervals) <<endl;
    return 0;
}
