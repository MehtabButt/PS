#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

//Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {
    for(auto &it : v) cin >> it;
    return istream;
}

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, pair<T1, T2> &p) { return (ostream << p.first << ' ' << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, vector<T> &v) {
    for(auto &it : v) cout << it <<' ';
    return ostream;
}

// Utility functions
template<typename T>
void print(T &&t) { cout <<t <<'\n'; }
template<typename T, typename... Args>
void print(T &&t, Args &&... args) {
    cout <<t <<' ';
    print(forward<Args>(args)...);
}

class Solution {
public:
    int solve(int n, int k) {
        int skipCount = 0;
        int kthInt = k;
        int mul, diff=MAX_N;

        while(diff) {
            mul = k/n;
            diff = mul-skipCount;
            if(diff) k += diff;
            skipCount += diff;
        }

        return k;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n,k;
    Solution sol;

    cin >>t;
    while(t > 0) {
        cin >>n >>k;
        cout <<sol.solve(n, k) <<endl;
        t--;
    }

    return 0;
}
