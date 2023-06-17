#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = -1;
        int buy = prices[0];
        int p;

        for(int i=1; i<prices.size(); i++) {
            p = prices[i] - buy;
            if(p > profit) profit = p;

            if(prices[i] < buy) buy = prices[i];
        }

        if(profit < 0) return 0;
        return profit;
    }
};

int main(){
    // vector<int> inp = {7,1,5,3,6,4};
    vector<int> inp = {7,6,4,3,1};
    Solution sol;
    cout <<sol.maxProfit(inp) <<endl;
    return 0;
}
