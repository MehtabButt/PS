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
        if(nums.size() == 1) return nums[0];
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        int r1 = rob_wrapper(v1, 0);
        this->memo = {};
        int r2 = rob_wrapper(v2, 0);
        return max(r1, r2);
    }
};

int main(){
    vector<int> nums({1});
    Solution sol;
    cout << sol.rob(nums) << endl;
    return 0;
}
