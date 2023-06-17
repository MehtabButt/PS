#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int pre = 0, cur = 0;
        int t_sum = 0, s_sum = 0;
        unordered_map<char, int> t_count(0);
        unordered_map<char, int> s_count(0);
        int len = INT32_MAX;
        string res = "";

        for(char tc : t) {
            t_sum++;
            t_count[tc]++;
        }

        while(cur < s.length()) {
            while(pre < s.length() and t_count[s[pre]] == 0) {
                pre++;
            }
            while(pre < s.length() and s_count[s[pre]] > t_count[s[pre]]) {
                s_count[s[pre]]--;
                pre++;
            }
            if(pre >= s.length()) break;
            else if(cur < pre) cur = pre;

            s_count[s[cur]]++;
            if(s_count[s[cur]] <= t_count[s[cur]]) s_sum++;

            if(s_sum == t_sum) {
                if(cur - pre + 1 < len) {
                    len = cur - pre + 1;
                    res = s.substr(pre, len);
                }
                s_count[s[pre]]--;
                if(s_count[s[pre]] < t_count[s[pre]]) s_sum--;
                pre++;
            }

            cur++;
        }

        return res;
    }
};

int main() {
    int t;
    string s1, s2;
    Solution sol;

    cin >>t;
    while(t > 0) {
        cin >>s1 >>s2;
        cout <<sol.minWindow(s1, s2) <<endl;
        t--;
    }

    return 0;
}
