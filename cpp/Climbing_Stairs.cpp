#include <unordered_map>

using namespace std;

class Solution {
    int stair_count;
    unordered_map<int, int> step_ways;
public:
    int climbing_ways_from(int step){
        if (step_ways.find(step) != step_ways.end()){
            return step_ways[step];
        }
        if(step == stair_count){
            return 1;
        }
        else if(step > stair_count){
            return 0;
        }
        int curr_step_ways = climbing_ways_from(step + 1) + climbing_ways_from(step + 2);
        step_ways[step] = curr_step_ways;
        return curr_step_ways;
    }

    int climbStairs(int n) {
        this->stair_count = n;
        this->step_ways = {};
        return climbing_ways_from(0);
    }
};
