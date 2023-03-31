#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <stack>

using namespace std;

class Graph{
    bool depth_first_search(int v, bool is_visited[]){
        is_visited[v] = true;
        for(auto &e : adj[v]){
            if(!is_visited[e]){
                if(depth_first_search(e, is_visited)) return true;
            }
            else{
                return true;
            }
        }
        is_visited[v] = false;
        return false;
    }

    public:
    int v;
    list<int> *adj;

    Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void add_edge(int v, int e){
        adj[v].push_back(e);
    }

    bool detect_cycle(){
        bool is_visited[v];
        for(int i=0; i<v; i++) is_visited[i]=false;
        for(int i=0; i<v; i++){
            if(depth_first_search(i, is_visited)) return true;
        }
        return false;
    }
};

class Solution {
    public:
    static bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto &preq : prerequisites){
            g.add_edge(preq[1], preq[0]);
        }
        return !g.detect_cycle();
    }
};

int main(){
    int courses;
    vector<vector<int>> preqs;
    string input;
    stringstream s_input;
    string inp;

    cin >> courses;
    cin.ignore(256, '\n');
    while (getline(cin, input)){
        if(input.empty()) break;
        vector<int> preq;
        s_input.clear();
        s_input << input;
        while(getline(s_input, inp, ',')){
            preq.push_back(stoi(inp));
        }
        preqs.push_back(preq);
    }

    cout <<boolalpha << Solution::canFinish(courses, preqs);
    return 0;
}
