#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT32_MIN;
        int max_end_here = 0;

        for(int num : nums) {
            max_end_here += num;
            if(max_end_here > max_so_far) max_so_far = max_end_here;
            if(max_end_here < 0) max_end_here = 0;
        }

        return max_so_far;
    }
};

int main(){
    // vector<int> inp = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> inp = {1};
    vector<int> inp = {-5,-4,-1,-7,-8};

    Solution sol;
    cout <<sol.maxSubArray(inp) <<endl;

    return 0;
}
