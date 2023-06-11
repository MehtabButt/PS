#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0; i<32; i++) {
            if((uint32_t)pow(2, i) & n) res |= 1 << (31-i);
        }
        return res;
    }
};

int main() {
    uint32_t n = 43261596;
    Solution sol;

    cout <<sol.reverseBits(n) <<endl;
    return 0;
}
