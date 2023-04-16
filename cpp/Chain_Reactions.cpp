#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Chain {
public:
    int v;
    vector<int> nodes;
    list<int> *adj;
    vector<int> abyss;

    Chain(int v) {
        this->v = v;
        adj = new list<int>[v];
    }

    void add_node(int n) {
        nodes.push_back(n);
    }

    void add_edge(int n1, int n2) {
        if(n1 >= 0) adj[n1].push_back(n2);
        else abyss.push_back(n2);
    }

    pair<long long, int> dfs(int n) {

        if(adj[n].size() == 0) return {nodes[n], nodes[n]};

        long long sum = nodes[n];
        int min_val = INT32_MAX;
        pair<long long, int> p;

        for(int neighbour : adj[n]) {
            p = dfs(neighbour);
            sum += p.first;
            if(p.second < min_val) min_val = p.second;
        }

        if(min_val < nodes[n]) {
            sum -= min_val;
            min_val = nodes[n];
        }
        else {
            sum -= nodes[n];
        }

        return {sum, min_val};
    }

    long long chain_reaction() {
        long long total = 0;

        for(int n : abyss) {
            total += dfs(n).first;
        }

        return total;
    }

    ~Chain() {
        delete[] adj;
    }
};

class Solution {

};

int main(){
    int t, n, temp;
    Chain *chain;
    cin >>t;

    for(int i=0; i<t; i++) {
        cin >>n;
        chain = new Chain(n);
        for(int j=0; j<n; j++) {
            cin >>temp;
            chain->add_node(temp);
        }
        for(int j=0; j<n; j++) {
            cin >>temp;
            chain->add_edge(temp-1, j);
        }
        cout <<"Case #" <<i+1 <<": ";
        cout <<chain->chain_reaction() <<endl;
    }
    return 0;
}
