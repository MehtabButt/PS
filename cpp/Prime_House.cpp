#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    stack<int> t;
    unordered_map<int, bool> memo;

    bool is_prime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i <= sqrt(n); i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;

        return true;
    }

    int next_prime(int i) {
        while(true) {
            if(is_prime(i+1)) return i+1;
            i++;
        }
    }

    int pre_prime(int i) {
        while(true) {
            if(is_prime(i-1)) return i-1;
            i--;
        }
    }
public:

    bool travel_for(int m, int n) {
        if(memo[m]) return memo[m];
        if(m == n) return true;

        int i = m;
        bool prime = false;

        while(i < n) {
            i = next_prime(i);
            if(is_prime(i-m)) {
                if(travel_for(i, n)) {
                    t.push(i);
                    return memo[i] = true;
                }
                memo[i] = false;
            }
        }

        return memo[m] = false;
    }

    bool travel_back(int m, int n) {
        if(memo[m]) return memo[m];
        if(m == n) return true;

        int i = m;
        bool prime = false;

        while(i > n) {
            i = pre_prime(i);
            if(is_prime(m-i)) {
                if(travel_back(i, n)) {
                    t.push(i);
                    return memo[i] = true;
                }
                memo[i] = false;
            }
        }

        return memo[m] = false;
    }

    void travel(int m, int n) {
        if(m < n) travel_for(m, n);
        else travel_back(m, n);
        t.push(m);
        if(t.size() != 1) {
            while(!t.empty()) {
                cout << t.top() << ' ';
                t.pop();
            }
            return;
        }
        cout << "Sorry Ms. Agoji!";
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    Solution sol;
    sol.travel(m, n);
    return 0;
}
