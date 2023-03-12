#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> maping;
public:
    int sol(vector<int>& coins, int amount) {
        if(maping.find(amount) != maping.end()) return maping[amount];
        if(amount == 0) {
            return 0;
        }
        else if (amount < 0) {
            return INT32_MAX;
        }

        int count = INT32_MAX;
        for(auto coin : coins){
            count = min(sol(coins, amount-coin), count) ;
        }
        maping[amount] = count == INT32_MAX ? INT32_MAX : count + 1;
        return maping[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        this->maping = {};
        int sol = this->sol(coins, amount);
        return sol == INT32_MAX ? -1 : sol;
    }
};
