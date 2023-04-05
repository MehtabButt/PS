#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s = unordered_set(nums.begin(), nums.end());
        int lcs = 0;
        int temp;
        for(int el : s) {
            if(s.find(el-1) == s.end()) {
                temp = 1;
                while(s.find(++el) != s.end()) {
                    temp++;
                }
                if(temp > lcs) lcs = temp;
            }
        }
        return lcs;
    }
};

int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution sol;
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}
