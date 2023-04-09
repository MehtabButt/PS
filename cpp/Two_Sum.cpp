#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        for(int i=0; i<nums.size(); i++) {
            if(memo.find(nums[i]) != memo.end()) return {memo[nums[i]], i};
            memo[target - nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> inp = {2,7,11,15};
    Solution sol;
    vector<int> out = sol.twoSum(inp, 9);
    return 0;
}
