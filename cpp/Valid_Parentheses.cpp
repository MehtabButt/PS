#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        unordered_map<char, char> bracket_pair = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for(char c : s) {
            if(c == '(' or c == '{' or c == '[') {
                bracket.push(c);
            }
            else {
                if(bracket.empty()) return false;
                if(bracket_pair[bracket.top()] != c) return false;
                bracket.pop();
            }
        }

        if(!bracket.empty()) return false;
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout <<sol.isValid(s) <<endl;
    return 0;
}
