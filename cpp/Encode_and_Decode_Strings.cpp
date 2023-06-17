#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(vector<string> &strs) {
        string encoded_str = "";

        for(string s : strs) {
            encoded_str += to_string(s.length()) + ':' + s;
        }

        return encoded_str;
    }

    vector<string> decode(string str) {
        vector<string> decoded_strs;
        string str_len = "";
        int len;
        string decoded_str;

        int i=0;
        while(i<str.length()) {
            str_len = "";
            decoded_str = "";
            while(str[i]!= ':') {
                str_len += str[i];
                i++;
            }

            len = stoi(str_len);
            for(int j=0; j<len; j++) {
                i++;
                decoded_str += str[i];
            }
            i++;
            decoded_strs.push_back(decoded_str);
        }

        return decoded_strs;
    }
};

int main() {
    vector<string> inp = {"we", "say", ":", "yes"};
    Solution sol;

    vector<string> out = sol.decode(sol.encode(inp));

    return 0;
}
