#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int v;
    list<int> *adj;

    bool dfs(int vertex, vector<bool>& visited, int parent, int& visits) {
        visited[vertex] = true;
        visits++;
        for(int neighbour : adj[vertex]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour, visited, vertex, visits)) return true;
            }
            else if(neighbour != parent) return true;
        }
        return false;
    }

    public:
    Graph(int v) {
        this->v = v;
        this->adj = new list<int>[v];
    }

    void add_edge(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    bool cyclic_or_disconnected() {
        vector<bool> visited = vector<bool>(v, false);
        int visits = 0;
        if(dfs(0, visited, -1, visits) or visits != v) return true;
        return false;
    }
};

bool checkgraph(vector<vector<int>> edges, int n, int m) {
    Graph g(n);
    for(auto e : edges) g.add_edge(e[0], e[1]);
    return !g.cyclic_or_disconnected();
}

int main(){
    vector<vector<int>> edges = {{0,1}, {0,2}, {0,3}, {1,4}};
    cout << checkgraph(edges, 5, 4) << endl;
    return 0;
}
