#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, bool> memo;
    bool can_jump(vector<int> &nums, int idx) {
        if(memo.find(idx) != memo.end()) return memo[idx];
        if(idx == nums.size()-1) return true;
        for(int j=nums[idx]; j>0; j--) {
            if(idx+j < nums.size()) if(can_jump(nums, idx+j)) return true;
        }
        return memo[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        this->memo = {};
        return can_jump(nums, 0);
    }
};

int main(){
    string inp, token;
    vector<int> arr_inp;
    getline(cin, inp);
    stringstream ss(inp);
    while(getline(ss, token, ',')) {
        arr_inp.push_back(stoi(token));
    }
    Solution sol;
    cout << sol.canJump(arr_inp) << endl;
    return 0;
}
