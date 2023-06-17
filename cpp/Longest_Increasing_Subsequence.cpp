#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    int max_lis;
    unordered_map<int, int> memo;
    int lis(vector<int>& nums, int idx) {
        if(memo.find(idx) != memo.end()) return memo[idx];
        if(idx == 1) return 1;
        int res;
        int max_res = 1;
        for(int i=1; i<idx; i++) {
            res = lis(nums, i) + 1;
            if (nums[idx - 1] > nums[i - 1] and res > max_res) {
                max_res = res;
            }
        }
        if(max_res > max_lis) max_lis = max_res;
        memo[idx] = max_res;
        return max_res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        this->max_lis = 1;
        this->memo = {};
        lis(nums, nums.size());
        return this->max_lis;
    }
};

int main() {
    Solution sol;
    vector<int> test({1,3,6,7,9,4,10,5,6});
    cout << sol.lengthOfLIS(test) << endl;
    return 0;
}
