#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, int> memo;
    int num_decodings(string s, int idx) {
        if(memo.find(idx) != memo.end()) return memo[idx];
        if(idx == s.length()) return 1;
        if(s[idx] == '0') return 0;
        else if(idx == s.length()-1) return 1;

        int ways = 0;

        ways += num_decodings(s, idx+1);
        if(idx+1 < s.length() and (s[idx]=='1' or (s[idx]=='2' and s[idx+1]<'7'))) {
            ways += num_decodings(s, idx+2);
        }

        return memo[idx] = ways;
    }
public:
    int numDecodings(string s) {
        this->memo = {};
        return num_decodings(s, 0);
    }
};

int main(){
    Solution sol;
    string t;
    cin >> t;
    cout << sol.numDecodings(t);
    return 0;
}
