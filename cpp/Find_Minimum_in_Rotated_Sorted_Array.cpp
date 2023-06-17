#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid = (r+l)/2;

        while(l != mid) {
            if(nums[l] < nums[mid] and nums[r] < nums[mid]) l = mid;
            else r = mid;

            mid = (r+l)/2;
        }

        if(nums[r] < nums[mid]) return nums[r];
        return nums[l];
    }
};

int main(){
    vector<int> inp = {3,4,5,1,2};

    Solution sol;
    cout <<sol.findMin(inp) <<endl;

    return 0;
}
