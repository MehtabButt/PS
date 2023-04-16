#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int remove_prefix(vector<string>& arr_strings, int arr_size) {
    int size = arr_size;
     string str = arr_strings[0];
     if(size == 1)
        return 0;

    int result = -1;
    int j = 1;
    for(int i=0; i<str.length(); i++){
        while(j < size){
            if(i < arr_strings[j].length() and str[i] == arr_strings[j][i]){
                j++;
            }
            else{
                return result;
            }
        }
        result = i;
        j = 1;
    }
    return result;
}

bool arrange(vector<string>& par, int s, int l) {
    l++;
    int idx;
    char last = '@';
    char temp = '@';
    if(l < par[0].length()) {
        last = par[0][l];
        swap(par[0][0], par[0][l]);
    }

    for(int i=1; i<s; i++) {
        idx = l;
        temp = '@';
        while(idx < par[i].length()) {
            if(par[i][idx] >= last) {
                temp = par[i][idx];
                break;
            }
            idx++;
        }
        if(temp >= last) {
            last = temp;
            if(last != '@') swap(par[i][0], par[i][idx]);
        }
        else return false;
    }

    return true;
}

void print_orders(vector<string> par) {
    for(string s : par) {
        cout <<s <<' ';
    }
    cout <<endl;
}

int main(){
    int t, p, l;
    string temp;
    vector<string> par;

    cin >>t;
    for(int i=0; i<t; i++) {
        cin >>p;
        for(int j=0; j<p; j++) {
            cin >>temp;
            sort(temp.begin(), temp.end());
            par.push_back(temp);
        }
        l = remove_prefix(par, p);
        cout <<"Case #" <<i+1 <<": ";
        if(arrange(par, p, l)) {
            cout <<"POSSIBLE\n";
            print_orders(par);
        }
        else cout <<"IMPOSSIBLE\n";
        par.clear();
    }

    return 0;
}
