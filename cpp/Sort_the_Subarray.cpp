#include <bits/stdc++.h>
#include <iostream>
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
public:
    pair<int,int> solve(vector<int> &a, vector<int> &a_prime) {
        int low = 0;
        int high = sza(a)-1;

        while(low <= high && (a[low] == a_prime[low] || a[high] == a_prime[high])) {
            if(a[low] == a_prime[low]) low++;
            if(a[high] == a_prime[high]) high--;
        }
        while((low > 0 || high < sza(a)-1) && ((low > 0 && a_prime[low-1] <= a_prime[low]) || (high < sza(a)-1 && a_prime[high+1] >= a_prime[high]))) {
            if(low > 0 && a_prime[low-1] <= a_prime[low]) low--;
            if(high < sza(a)-1 && a_prime[high+1] >= a_prime[high]) high++;
        }

        return {++low, ++high};
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    Solution sol;
    int n, temp;
    vector<int> a;
    vector<int> a_prime;
    pair<int,int> res;

    cin >> t;
    while(t > 0) {
        cin >>n;
        a.resize(n);
        a_prime.resize(n);
        cin >>a >>a_prime;
        res = sol.solve(a, a_prime);
        cout <<res <<endl;
        a.clear();
        a_prime.clear();
        t--;
    }

    return 0;
}
