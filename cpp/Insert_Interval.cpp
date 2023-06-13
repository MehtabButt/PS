#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_s, new_e;
        vector<vector<int>> allIntervals(intervals);

        int s = -1, e = intervals.size();
        int mid = (s+e)/2;
        while(mid != s && mid != e) {
            if(newInterval[0] < intervals[mid][0]) {
                e = mid;
                mid = (s+e)/2;
            } else if(newInterval[0] > intervals[mid][0]) {
                s = mid;
                mid = (s+e)/2;
            } else {
                s = mid;
                e = mid;
            }
        }
        new_s = s;

        s = -1; e = intervals.size();
        mid = (s+e)/2;
        while(mid != s && mid != e) {
            if(newInterval[1] < intervals[mid][1]) {
                e = mid;
                mid = (s+e)/2;
            } else if(newInterval[1] > intervals[mid][1]) {
                s = mid;
                mid = (s+e)/2;
            } else {
                s = mid;
                e = mid;
            }
        }
        new_e = s;

        int erase_s = new_s, erase_e = new_e;
        if(new_e+1 < intervals.size() && newInterval[1] >= intervals[new_e+1][0] && newInterval[1] <= intervals[new_e+1][1]) erase_e++;
        erase_e++;

        if(new_s == -1) erase_s++;
        else if(newInterval[0] > intervals[new_s][1]) erase_s++;

        if(erase_e > erase_s) {
            newInterval[0] = min(newInterval[0], intervals[erase_s][0]);
            newInterval[1] = max(newInterval[1], intervals[erase_e-1][1]);
        }

        allIntervals.erase(allIntervals.begin()+erase_s, allIntervals.begin()+erase_e);
        allIntervals.insert(allIntervals.begin()+erase_s, newInterval);

        return allIntervals;
    }
};

int main() {
    vector<vector<int>> intervals = {{3,7}, {11,18}};
    vector<int> newInterval = {19,30};
    Solution sol;

    vector<vector<int>> res = sol.insert(intervals, newInterval);
    return 0;
}
