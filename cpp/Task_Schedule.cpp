#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int v;
    list<int> *adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new list<int>[v+1];
    }

    void add_edge(int v1, int v2) {
        adj[v1].push_back(v2);
    }
    vector<int> top_sort() {
        vector<int> indegree(v+1, 0);
        vector<int> out;
        for(int i=1; i<v+1; i++) {
            for(int j : adj[i]) {
                indegree[j]++;
            }
        }
        priority_queue<int> pq;
        for(int i=1; i<v+1; i++) {
            if(indegree[i] == 0) pq.push(i);
        }

        int ver;
        while(!pq.empty()) {
            ver = pq.top();
            pq.pop();

            out.push_back(ver);
            for(int e : adj[ver]) {
                indegree[e]--;
                if(indegree[e] == 0) pq.push(e);
            }
        }
        if(out.size() == v) return out;
        return {-1};
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    Graph g(m);
    for(int i=0; i<n; i++) {
        cin >> m >> n;
        g.add_edge(n, m);
    }
    vector<int> out = g.top_sort();
    for(int o : out) cout << o << ' ';
    return 0;
}
