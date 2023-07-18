#include <iostream>
#include <vector>
using namespace std;

template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, vector<T> &v) {
    for(auto &it : v) cout << it <<' ';
    return ostream;
}

class Solution {
    int depth;
    vector<string> par;
    void genParaUtil(int n, int d, string p) {
        if (n < 0 || n > depth/2) {
            return;
        }
        else if(d == depth) {
            if(n == 0) par.push_back(p);
            return;
        }

        genParaUtil(n+1, d+1, p+"(");
        genParaUtil(n-1, d+1, p+")");
    }
    public:
    vector<string> generateParenthesis(int n) {
        depth = 2*n;
        genParaUtil(0, 0, "");
        return par;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    Solution sol;
    cin >>n;
    vector<string> res = sol.generateParenthesis(n);
    cout <<res <<endl;

    return 0;
}
