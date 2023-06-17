#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> memo;
    int rob_wrapper(vector<int>& nums, int idx) {
        if(memo.find(idx) != memo.end()) return memo[idx];
        if(idx >= nums.size()) return 0;
        return memo[idx] = max(nums[idx] + rob_wrapper(nums, idx+2), rob_wrapper(nums, idx+1));
    }
public:
    Solution() {
        this->memo = {};
    }
    int rob(vector<int>& nums) {
        return rob_wrapper(nums, 0);
    }
};

int main(){
    vector<int> nums({2,7,9,3,1});
    Solution sol;
    cout << sol.rob(nums) << endl;
    return 0;
}
