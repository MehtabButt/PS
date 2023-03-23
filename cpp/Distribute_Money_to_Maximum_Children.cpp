#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    int dist_money(int m, int c) {
        if(m < 8 or c == 0) {
            if(m == c) {
                return 0;
            }
            else if(m >= c) {
                return (m == 4 and c == 1) or c == 0 ? -1 : 0;
            }
            else {
                return -ceil((c-m)/(float)7);
            }
        }
        return 1 + dist_money(m-8, c-1);
    }
public:
    int distMoney(int money, int children) {
        int res = dist_money(money, children);
        return res < 0 ? -1 : res;
    }
};

int main(){
    int m, c;
    cin >> m;
    cin >> c;
    Solution sol;
    cout << sol.distMoney(m, c) << endl;
    return 0;
}
