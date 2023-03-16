#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, bool> memo;
public:
    Solution() {
        this->memo = {};
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if(memo.find(s) != memo.end()) return memo[s];
        if(s.length() == 0) return true;

        int idx;
        bool res = false;

        for(string word : wordDict) {
            if((idx = s.find(word)) != -1) {
                res = res or (wordBreak(s.substr(0, idx), wordDict) and wordBreak(s.substr(idx + word.length()), wordDict));
            }
        }
        memo[s] = res;
        return memo[s];
    }
};

int main() {
    vector<string> wordDict({"bc", "cb"});
    string s = "ccbb";

    Solution sol;
    string res =  sol.wordBreak(s, wordDict) ? "true" : "false";
    cout << res << endl;

    return 0;
}
