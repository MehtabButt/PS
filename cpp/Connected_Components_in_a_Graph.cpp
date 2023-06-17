#include <iostream>
#include <vector>
using namespace std;

// via union-find algo using disjoint-set ds

int find(vector<int>& graph, int node) {
    if(graph[node] == node) {
        return node;
    }
    return graph[node] = find(graph, graph[node]);
}

int edge_union(vector<int>& graph, vector<int>& rank, pair<int, int> edge) {
    int p1 = find(graph, edge.first), p2 = find(graph, edge.second);

    if(p1 != p2) {
        if(rank[p1] == rank[p2]) {
            graph[p2] = p1;
            rank[p1]++;
        }
        else if(rank[p1] > rank[p2]) graph[p2] = p1;
        else graph[p1] = p2;
        return -1;
    }
    return 0;
}

int count_components(int nodes, vector<pair<int, int>>& edges) {
    vector<int> rank = vector(nodes+1, 0);
    vector<int> graph(nodes+1);
    int subsets = nodes;
    for(int i=1; i<=nodes; i++) graph[i]=i;

    for(auto edge : edges) {
        subsets += edge_union(graph, rank, edge);
    }

    return subsets;
}

int main(){
    int n, e, n1, n2;
    vector<pair<int, int>> edges;
    cin >>n >>e;
    for(int i=0; i<e; i++) {
        cin >>n1 >>n2;
        edges.push_back({n1, n2});
    }

    cout <<count_components(n, edges) <<endl;
    return 0;
}
