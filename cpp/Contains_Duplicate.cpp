#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums) {
            if(set.find(num) != set.end()) return true;
            set.insert(num);
        }
        return false;
    }
};

int main(){
    // vector<int> inp = {1,1,1,3,3,4,3,2,4,2};
    vector<int> inp = {1,2,3,4};
    Solution sol;
    cout <<sol.containsDuplicate(inp) <<endl;
    return 0;
}
