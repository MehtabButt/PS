#include <bits/stdc++.h>
#include <stdexcept>
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

// loops
#define For(a,b,s) for (int (i) = (a); (i) < (b); i+=s)

class Solution {
    int getNumberWithRem(int n, int rem, int adder) {
        if(rem == 0 && adder == 0) return n;

        rem -= (rem+adder)%n-rem;
        return rem;
    }
public:
    vector<int> solve(int n) {
        int t=n;
        int add=0;
        int sum = 0;
        vector<int> res;
        For(0,n,1) {
            t += add;
            if(add == 0) add = -1;
            else add = (abs(add)+1) * (-add/abs(add));

            res.push_back(getNumberWithRem(n, t%n, sum));
            sum += *res.rbegin();
        }
        if(sum == (n*(n+1))/2) return res;
        return vector<int>({-1});
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    vector<int> res;
    Solution sol;

    cin >>t;
    while(t > 0) {
        cin >>n;
        res = sol.solve(n);
        cout <<res <<endl;
        res.clear();
        t--;
    }

    return 0;
}
