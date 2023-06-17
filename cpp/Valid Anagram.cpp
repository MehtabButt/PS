#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.length();
        if(len != t.length()) return false;

        unordered_map<wchar_t, int> count(0);

        for(int i=0; i<len; i++) {
            count[s[i]]++;
            count[t[i]]--;
        }

        for(auto c : count) {
            if(c.second) return false;
        }

        return true;
    }
};

int main() {
    int t;
    string s1, s2;
    Solution sol;

    cin >>t;
    while(t > 0) {
        cin >>s1 >>s2;
        cout <<sol.isAnagram(s1, s2) <<endl;
        t--;
    }

    return 0;
}
