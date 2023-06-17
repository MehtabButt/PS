#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i=0; i<nums.size(); i++) missing ^= i ^ nums[i];
        missing ^= nums.size();
        return missing;
    }
};

int main() {
    vector<int> inp = {9,6,4,2,3,5,7,0,1};
    Solution sol;

    cout <<sol.missingNumber(inp) <<endl;
    return 0;
}
