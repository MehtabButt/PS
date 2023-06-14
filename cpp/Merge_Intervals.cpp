#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        vector<int> newInterval = {-1, -1};
        sort(intervals.begin(), intervals.end());

        for(auto interval : intervals) {
            if(newInterval[0] == -1) {
                newInterval = interval;
            } else if(interval[0] <= newInterval[1]) {
                newInterval[1] = max(newInterval[1], interval[1]);
            } else {
                mergedIntervals.push_back(newInterval);
                newInterval = interval;
            }
        }
        if(newInterval[0] != -1) mergedIntervals.push_back(newInterval);

        return mergedIntervals;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,4}, {4,5}, {10,11}};
    Solution sol;

    auto res = sol.merge(intervals);
    return 0;
}
