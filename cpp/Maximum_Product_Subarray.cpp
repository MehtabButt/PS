#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0], max_i = nums[0], min_i = nums[0];
        int temp;

        for(int i=1; i<nums.size(); i++) {
            temp = max({nums[i], max_i*nums[i], min_i*nums[i]});
            min_i = min({nums[i], max_i*nums[i], min_i*nums[i]});
            max_i = temp;

            max_prod = max(max_prod, max_i);
        }

        return max_prod;
    }
};

int main(){
    // vector<int> inp = {2,3,-2,4};
    vector<int> inp = {-2,0,-1};

    Solution sol;
    cout <<sol.maxProduct(inp) <<endl;

    return 0;
}
