#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void optimize(vector<int>& pos, int m, int r) {
        int r_ = r;
        int temp;
        int enlight = 0;
        int bulb = 0;

        int c = 0;

        while(c==0 or pos[c-1]+r < m) {

            while(c < pos.size()-1 and pos[c+1] <= r_) {
                c++;
            }

            bulb++;
            enlight += 2*r;
            enlight = min({pos[c]+r, enlight, m});

            temp = min(pos[c]+r, m);
            if(enlight < temp) {
                cout <<"IMPOSSIBLE" <<endl;
                return;
            }

            r_ = min(2*r+pos[c] , m);
            c++;
        }

        cout <<bulb <<endl;
    }
};

int main(){
    int t, m, r, n, temp;
    vector<int> pos;
    Solution sol;

    cin >>t;
    for(int i=0; i<t; i++) {
        cin >>m >>r >>n;
        for(int j=0; j<n; j++) {
            cin >>temp;
            pos.push_back(temp);
        }
        cout <<"Case #" <<i+1 <<": ";
        sol.optimize(pos, m, r);
        pos.clear();
    }
    return 0;
}
