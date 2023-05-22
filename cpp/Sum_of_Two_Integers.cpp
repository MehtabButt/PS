#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int sum;
        uint carry;

        do {
            sum = a^b;
            carry = a&b;
            a = sum;
            b = carry << 1;
        } while (b);

        return a;
    }
};

int main() {
    int a, b;
    Solution sol;

    cin >>a >>b;
    cout <<sol.getSum(a, b) <<endl;

    return 0;
}
