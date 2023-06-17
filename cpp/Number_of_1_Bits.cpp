#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t mask = 1;

        while(mask != 0) {
            if(n & mask) count++;
            mask *= 2;
        }

        return count;
    }
};

int main() {
    Solution sol;
    cout <<sol.hammingWeight(11) <<endl;
    return 0;
}
