#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int loop_count = 3;
        int i = 0;

        while(i <= loop_count && res.size() < n+1) {
            if(res.size() < 4) res.push_back(i < 2 ? i : i-1);
            else res.push_back(res[i] + 1);

            if(i == loop_count) {
                i = -1;
                loop_count = res.size() - 1;
            }
            i++;
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> res = sol.countBits(10);

    return 0;
}
