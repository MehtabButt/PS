#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        queue<Node*> q;
        unordered_map<int, Node*> map;
        Node *temp;
        Node *newNode;
        Node *cur;

        q.push(node);
        Node *root = new Node(node->val);
        map[node->val] = root;

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            cur = map[temp->val];

            for(Node *n : temp->neighbors) {
                if(!map[n->val]) {
                    q.push(n);
                    newNode = new Node(n->val);
                    map[n->val] = newNode;
                }
                else {
                    newNode = map[n->val];
                }
                cur->neighbors.push_back(newNode);
            }
        }
        return root;
    }
};

int main(){
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);

    one->neighbors.push_back(two);
    one->neighbors.push_back(four);

    two->neighbors.push_back(one);
    two->neighbors.push_back(three);

    three->neighbors.push_back(two);
    three->neighbors.push_back(four);

    four->neighbors.push_back(three);
    four->neighbors.push_back(one);

    Solution sol;
    Node *clone =  sol.cloneGraph(one);
    return 0;
}
