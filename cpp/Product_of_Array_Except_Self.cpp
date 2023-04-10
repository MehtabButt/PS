#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        vector<int> prod = vector(nums.size(), 1);

        for(int i=0; i<nums.size(); i++) {
            prod[i] = temp;
            temp *= nums[i];
        }

        temp = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            prod[i] *= temp;
            temp *= nums[i];
        }

        return prod;
    }
};

int main(){
    // vector<int> inp = {1,2,3,4};
    vector<int> inp = {-1,1,0,-3,3};

    Solution sol;
    vector<int> out = sol.productExceptSelf(inp);

    return 0;
}
