#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int getClustersCount(vector<pair<int,int>> &coords) {
        unordered_map<int, list<int>> ver_coord;
        unordered_map<int, list<int>> hor_coord;
        bool hasUp, hasDown, hasRight, hasLeft;
        int clustorsCount = 0;
        list<int> ver, hor;

        //ver_coord & hor_coord
        for(auto coord : coords) {
            ver_coord[coord.first].push_back(coord.second);
            hor_coord[coord.second].push_back(coord.first);
        }

        for(auto coord : coords) {
            hasUp = hasDown = hasRight = hasLeft = false;
            ver = ver_coord[coord.first];
            for(int y : ver) {
                if(y < coord.second) hasDown = true;
                else if(y > coord.second) hasUp = true;
                if(hasUp && hasDown) break;
            }

            hor = hor_coord[coord.second];
            for(int x : hor) {
                if(x < coord.first) hasLeft = true;
                else if(x > coord.first) hasRight = true;
                if(hasLeft && hasRight) break;
            }

            if(hasUp && hasDown && hasLeft && hasRight) clustorsCount++;
        }

        return clustorsCount;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, x, y;
    Solution sol;

    cin >> n;
    vector<pair<int, int>> coord;
    while(n > 0) {
        cin >> x >> y;
        coord.push_back({x,y});
        n--;
    }

    cout << sol.getClustersCount(coord) <<endl;
    return 0;
}
