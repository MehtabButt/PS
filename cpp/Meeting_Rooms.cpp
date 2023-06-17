#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        int preEndTime = meetings[0][1];

        for(int i=1; i<meetings.size(); i++) {
            if(meetings[i][0] < preEndTime) return false;
            preEndTime = meetings[i][1];
        }

        return true;
    }
};

int main() {
    // vector<vector<int>> inp = {{0,30},{5,10},{15,20}}; //no
    vector<vector<int>> inp = {{5,8},{9,15}}; //yes
    Solution sol;

    cout <<(sol.canAttendMeetings(inp) ? "yes" : "no") <<endl;
    return 0;
}
