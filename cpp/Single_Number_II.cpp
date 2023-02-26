#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int thn=-1, thnp1=0, thnp2=0;
    for(int &num : nums){
      int thn_mask = thn & num;
      int thnp1_mask = thnp1 & num;
      int thnp2_mask = thnp2 & num;

      thnp1 |= thn_mask;
      thn &= ~(thn_mask);

      thnp2 |= thnp1_mask;
      thnp1 &= ~(thnp1_mask);

      thn |= thnp2_mask;
      thnp2 &= ~(thnp2_mask);
    }
    return thnp1;
  }
};

int main(){
  vector<int> vec;
  string input, inp;
  getline(cin, input);
  stringstream input_stream(input);
  while (getline(input_stream, inp, ',')){
    vec.push_back(stoi(inp));
  }
  Solution sol;
  cout <<sol.singleNumber(vec) <<endl;
  return 0;
}
