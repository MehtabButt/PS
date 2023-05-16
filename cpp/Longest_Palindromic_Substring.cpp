#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    pair<int, int> expand_palindrome(string s, int r, int l) {
        while(r < s.length()-1 && l > 0) {
            if(s[r+1] == s[l-1]) {
                r += 1;
                l -= 1;
            }
            else {
                break;
            }
        }
        return {l, r};
    }
public:
    string longestPalindrome(string s) {
        int l=0, r=0;
        pair<int, int> lp = {0,0}, temp;

        for(int i=0; i<s.length(); i++) {
            if(i > 0 && s[i] == s[i-1]) {
                r = i;
                l = i-1;
                temp = expand_palindrome(s, r, l);
                if(temp.second-temp.first+1 > lp.second-lp.first+1) {
                    lp.first = temp.first;
                    lp.second = temp.second;
                }
            }
            if(i < s.length()-1 && s[i] == s[i+1]) {
                r = i+1;
                l = i;
                temp = expand_palindrome(s, r, l);
                if(temp.second-temp.first+1 > lp.second-lp.first+1) {
                    lp.first = temp.first;
                    lp.second = temp.second;
                }
            }
            if(i > 0 && i < s.length()-1 && s[i-1] == s[i+1]) {
                r = i+1;
                l = i-1;
                temp = expand_palindrome(s, r, l);
                if(temp.second-temp.first+1 > lp.second-lp.first+1) {
                    lp.first = temp.first;
                    lp.second = temp.second;
                }
            }
        }

        return s.substr(lp.first, lp.second-lp.first+1);
    }
};

int main() {
    string s = "aaaaa";
    Solution sol;

    string lpss = sol.longestPalindrome(s);
    cout << lpss <<endl;

    return 0;
}
