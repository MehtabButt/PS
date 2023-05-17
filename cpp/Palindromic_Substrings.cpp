#include <iostream>
using namespace std;

class Solution {
    int expand_palindrome(string s, int r, int l) {
        int count = 1;
        while(r < s.length()-1 && l > 0) {
            if(s[r+1] == s[l-1]) {
                r += 1;
                l -= 1;
                count += 1;
            }
            else {
                break;
            }
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int l=0, r=0;
        int pssc = 0; // palindromic substrings count

        for(int i=0; i<s.length(); i++) {
            pssc += 1;
            if(i < s.length()-1 && s[i] == s[i+1]) {
                r = i+1;
                l = i;
                pssc += expand_palindrome(s, r, l);
            }
            if(i > 0 && i < s.length()-1 && s[i-1] == s[i+1]) {
                r = i+1;
                l = i-1;
                pssc += expand_palindrome(s, r, l);
            }
        }

        return pssc;
    }
};

int main() {
    string s = "abc";
    Solution sol;

    cout <<sol.countSubstrings(s) <<endl;

    return 0;
}
