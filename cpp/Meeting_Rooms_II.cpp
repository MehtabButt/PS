#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> endTimes;
        endTimes.push(meetings[0][1]);
        int rooms = 1;
        int temp;

        for(int i=1; i<meetings.size(); i++) {
            if(meetings[i][0] < endTimes.top()) {
                rooms++;
                endTimes.push(meetings[i][1]);
            } else {
                endTimes.pop();
                endTimes.push(meetings[i][1]);
            }
        }

        return rooms;
    }
};

int main() {
    vector<vector<int>> inp = {{0, 30},{5, 10},{15, 20}}; //2
    // vector<vector<int>> inp = {{1, 18},{18, 23},{15, 29},{4, 15},{2, 11},{5, 13}}; //4
    // vector<vector<int>> inp = {{0, 14},{6, 25},{12, 19},{13, 19},{5, 9}}; //4
    // vector<vector<int>> inp =  {{17, 26},{14, 22},{7, 29},{2, 29},{11, 14},{5, 24},{1, 14},{13, 14}}; //6
    Solution sol;

    cout <<sol.minMeetingRooms(inp) <<endl;
    return 0;
}
