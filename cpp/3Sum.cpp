#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int a, l, r, temp;
        vector<vector<int>> out;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==temp) continue;
            a = -nums[i];
            l = i+1, r = nums.size()-1;
            while(l < r) {
                if((nums[l] + nums[r]) < a) l++;
                else if ((nums[l] + nums[r]) > a) r--;
                else {
                    out.push_back({nums[l], nums[r], nums[i]});
                    temp = nums[l];
                    while(l<nums.size()-1 and nums[l]==temp) l++;
                    temp = nums[r];
                    while(r>0 and nums[r]==temp) r--;
                }
            }
            temp = nums[i];
        }

        return out;
    }
};

int main(){
    vector<int> inp = {-1,0,1,2,-1,-4};
    // vector<int> inp = {0,1,1};
    // vector<int> inp = {0,0,0};
    // vector<int> inp = {-1,0,1};

    Solution sol;
    vector<vector<int>> out = sol.threeSum(inp);

    return 0;
}
