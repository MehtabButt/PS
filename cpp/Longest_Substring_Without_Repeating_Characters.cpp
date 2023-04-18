#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pre = 0, cur = 0;
        unordered_map<char, int> memo;
        int lols = 0;

        while(cur < s.length()) {
            if(memo.find(s[cur]) != memo.end() and memo[s[cur]] >= pre) {
                pre = memo[s[cur]] + 1;
            }
            memo[s[cur]] = cur;
            cur++;
            lols = max((int)s.substr(pre, cur-pre).length(), lols);
        }

        return lols;
    }
};

int main(){
    string s;
    cin >>s;

    Solution sol;
    cout <<sol.lengthOfLongestSubstring(s) <<endl;

    return 0;
}
