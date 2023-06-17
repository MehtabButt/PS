#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> memo;
public:
    Solution() {
        this->memo = {};
    }
    int combinationSum4(vector<int>& nums, int target) {
        if(memo.find(target) != memo.end()) return memo[target];
        if(target == 0) {
            return 1;
        }
        else if(target < 0) {
            return 0;
        }
        int res = 0;
        for(int num : nums) {
            res += combinationSum4(nums, target - num);
        }
        memo[target] = res;
        return memo[target];
    }
};

int main(){
    vector<int> nums({1,2,3});
    int t = 4;
    Solution sol;
    cout << sol.combinationSum4(nums, t) << endl;
    return 0;
}
