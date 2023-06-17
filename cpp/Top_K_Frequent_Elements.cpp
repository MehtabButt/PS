#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto comparator = [](pair<int,int> &p1, pair<int,int> &p2) {
            return p1.second < p2.second;
        };

        unordered_map<int, int> freq(0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comparator)> freqQueue(comparator);
        vector<int> topKFrequents;

        for(int num : nums) freq[num]++;
        for(auto f : freq) freqQueue.push(f);
        for(int i=0; i<k; i++) {
            if(!freqQueue.empty()) {
                topKFrequents.push_back(freqQueue.top().first);
                freqQueue.pop();
            }
        }

        return topKFrequents;
    }
};

int main() {
    // vector<int> inp = {1,2, 1, 1, 3, 2};
    vector<int> inp = {1};
    Solution sol;

    vector<int> res = sol.topKFrequent(inp, 2);
    return 0;
}
