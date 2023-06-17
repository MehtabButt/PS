#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    string get_counter_string(string s) {
        vector<int> counter(26, 0);
        string count = "";
        string temp;

        for(char c : s) {
            counter[int(c)-97]++;
        }

        for(int c : counter) {
            temp = to_string(c);
            count += temp.length() < 2 ? '0'+temp : temp;
        }

        return count;
    }
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        vector<vector<string>> groups;

        for(string s : strs) {
            res[get_counter_string(s)].push_back(s);
        }

        for(auto cat : res) {
            groups.push_back(cat.second);
        }

        return groups;
    }
};

int main() {
    Solution sol;
    // vector<string> inp = {"eat","tea","tan","ate","nat","bat"};
    vector<string> inp = {"ddddddddddg","dgggggggggg"};

    vector<vector<string>> res = sol.groupAnagrams(inp);

    return 0;
}
