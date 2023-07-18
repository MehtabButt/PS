#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    int spellLimit;
    string finalStr;
    unordered_map<string, bool> memo;
    bool getUniqWaysUtil(string a, int idx, int spellCount) {
        if(spellCount == spellLimit) {
            if(a == finalStr) return true;
            else return false;
        }


        if(memo.find(a+to_string(idx)+to_string(spellCount)) != memo.end()) {
            return memo[a+to_string(idx)+to_string(spellCount)];
        }

        string spelled = a.substr(idx) + a.substr(0, idx);
        for(int i=1; i<spelled.length(); i++) {
            if(getUniqWaysUtil(spelled, i, spellCount+1)) return memo[a+to_string(idx)+to_string(spellCount)] = true;
        }
        return memo[a+to_string(idx)+to_string(spellCount)] = false;
    }
    public:
    int getUniqWays(string a, string b, int n) {
        if(n == 0) {
            if(a == b) return 1;
            else return 0;
        }
        spellLimit = n;
        finalStr = b;
        int ways = 0;
        for(int i=1; i<a.length(); i++) {
            if(getUniqWaysUtil(a, i, 0)) ways++;
        }
        return ways;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a, b;
    int n;
    getline(cin, a);
    getline(cin, b);
    cin >> n;

    Solution sol;
    cout <<sol.getUniqWays(a, b, n) <<endl;
    return 0;
}
