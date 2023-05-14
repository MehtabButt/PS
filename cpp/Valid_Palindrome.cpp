#include <iostream>
#include <regex>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() -1;

        while(left <= right) {
            if(!(s[left] >= 'A' and s[left] <= 'Z' or s[left] >= 'a' and s[left] <= 'z' or s[left] >= '0' and s[left] <= '9')) {
                left++;
                continue;
            }
            else if(!(s[right] >= 'A' and s[right] <= 'Z' or s[right] >= 'a' and s[right] <= 'z' or s[right] >= '0' and s[right] <= '9')) {
                right--;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    string s;
    Solution sol;

    cin >> s;
    cout << sol.isPalindrome(s);

    return 0;
}
