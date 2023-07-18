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
    int getTaxiCount(vector<int> &gr) {
        int low = 0, high = sza(gr)-1;
        int taxiSpace = 4;
        int taxiCount = 0;
        int s;
        sort(all(gr));

        while(low <= high) {
            if(low == high) {
                taxiCount++;
                low++;
                high--;
                continue;
            }
            s = gr[low]+gr[high];
            if(s == taxiSpace) {
                low++;
                high--;
                taxiCount++;
                taxiSpace = 4;
            }
            else if(s > taxiSpace) {
                if(gr[high] <= taxiSpace) high--;
                else if(gr[low] <= taxiSpace) low++;
                taxiCount++;
                taxiSpace = 4;
            }
            else {
                taxiSpace -= gr[low];
                low++;
            }
        }

        return taxiCount;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, temp;
    vector<int> gr;
    Solution sol;

    cin >>n;
    while(n > 0) {
        cin >>temp;
        gr.push_back(temp);
        n--;
    }
    cout <<sol.getTaxiCount(gr) <<endl;


    return 0;
}
