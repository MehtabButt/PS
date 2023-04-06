#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph {
    unordered_map<char, list<char>> adj;
    unordered_map<char, int> indegree;

public:
    Graph() {
        this->adj = {};
        this->indegree = {};
    }

    void add_edge(char n1, char n2=' ') {
        if(indegree.find(n1) == indegree.end()) indegree[n1] = 0;
        if(n2 == ' ') {
            adj[n1] = list<char>();
            return;
        }
        if(adj.find(n1) == adj.end()) adj[n1] = list<char>();
        adj[n1].push_back(n2);
        indegree.find(n2) != indegree.end() ? indegree[n2]++ : indegree[n2] = 1;
    }

    string topological_sort() {
        queue<char> q;
        for(auto m : indegree) {
            if(m.second == 0) q.push(m.first);
        }

        char temp;
        string out;

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            out += temp;
            for(auto neighbour : adj[temp]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        return out;
    }
};

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        Graph g;
        if(N > 0) g.add_edge(dict[0][0]);

        for(int i=0; i<N-1; i++) {
            for(int c=0; c<dict[i].length(); c++) {
                try{
                    if(dict[i][c] != dict[i+1][c]) {
                        g.add_edge(dict[i][c], dict[i+1][c]);
                        break;
                    }
                } catch(...) {}
            }
        }

        return g.topological_sort();
    }
};

int main(){
    string dict[] = {"bac", "abcd", "abca", "cab", "cad"};
    Solution sol;
    cout << sol.findOrder(dict, 5, 4) << endl;
    return 0;
}
