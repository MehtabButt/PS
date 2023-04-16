#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string cliding_encoding(vector<int>& enc, vector<string>& words) {
        string temp = "";
        unordered_set<string> s;
        for(string word : words) {
            for(char& c : word) {
                temp += to_string(enc[int(c) - 65]);
            }
            s.insert(temp);
            temp = "";
        }

        if(s.size() == words.size()) return "NO";
        return "YES";
    }
};

int main(){
    int t, temp, n;
    string s;
    vector<int> enc;
    vector<string> words;
    Solution sol;

    cin >>t;

    for(int i=0; i<t; i++) {
        for(int e=0; e<26; e++) {
            cin >>temp;
            enc.push_back(temp);
        }
        cin >>n;
        for(int j=0; j<n; j++) {
            cin >>s;
            words.push_back(s);
        }
        cout <<"Case #" <<i+1 <<": ";
        cout <<sol.cliding_encoding(enc, words) <<endl;
        enc.clear();
        words.clear();
    }
    return 0;
}
