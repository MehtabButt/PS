#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <iterator>

using namespace std;

int make_dense_array(int n, list<int> a){
    int insertion = 0;
    for(auto it=a.begin(); it != a.end(); it++){
        if(next(it,1) == a.end()) continue;
        if(*it > *(next(it,1)) && *it > (*(next(it,1)))*2){
            a.insert(next(it,1), ceil((float)*it/2));
            insertion++;
        }
        else if(*next(it,1) > *it && *next(it,1) > (*it)*2){
            a.insert(next(it,1), (*it)*2);
            insertion++;
        }
    }
    return insertion;
}

int main(){
    int t;
    int n;
    list<int> a;
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
        cout << make_dense_array(n, a) << endl;
        a.clear();
    }
    return 0;
}


