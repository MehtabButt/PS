#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int max_water = INT32_MIN;

        while(l < r) {
            if(height[l] < height[r]) {
                max_water = max(height[l]*(r-l), max_water);
                l++;
            }
            else {
                max_water = max(height[r]*(r-l), max_water);
                r--;
            }
        }

        return max_water;
    }
};

int main(){
    // vector<int> inp = {1,8,6,2,5,4,8,3,7};
    // vector<int> inp = {1, 5, 4, 3};
    vector<int> inp = {2,3,4,5,18,17,6};

    Solution sol;
    cout <<sol.maxArea(inp) <<endl;

    return 0;
}
