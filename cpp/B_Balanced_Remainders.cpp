#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int balance_remainders(int n, vector<int> a){
    map<int, int> r = {{0,0}, {1,0}, {2,0}};
    int limit = n/3;
    int need;
    int back;
    int front;
    int cost = 0;

    for(int &i : a){
        r[i % 3] += 1;
    }
    for(auto &[k,v] : r){
        if(v < limit){
            need = limit - v;
            back = r[(((k-1) % 3)+3)%3] - limit;
            front = r[(((k+1) % 3)+3)%3] - limit;
            if(back > 0){
                v += back;
                r[(((k-1) % 3)+3)%3] -= back;
                cost += back;
                need -= back;
            }
            if(need > 0 && front >= need){
                v += need;
                r[(((k+1) % 3)+3)%3] -= need;
                cost += need*2;
                need = 0;
            }
        }
    }
    return cost;
}

int main(){
    int t;
    int n;
    vector<int> a;
    string input;
    stringstream s_input;
    string inp;
    cin >> t;


    for(int i=0; i<t; i++){
        cin >> n;
        cin.ignore(255, '\n');
        getline(cin, input);
        s_input.clear();
        s_input << input;
        while(getline(s_input, inp, ' ')){
            a.push_back(stoi(inp));
        }
        //call
        cout << balance_remainders(n, a) << endl;
        a.clear();
    }
    return 0;
}
