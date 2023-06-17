#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int d = 1;
        return d += max(maxDepth(root->left), maxDepth(root->right));
    }
};

TreeNode* getNode(string n) {
    if(n == "null") return nullptr;
    else return new TreeNode(stoi(n));
}

int main(){
    string inp, token;
    getline(cin, inp);
    stringstream ss(inp);
    TreeNode *root = nullptr;
    TreeNode *temp = nullptr;
    TreeNode *newNode = nullptr;
    queue<TreeNode*> q_inp;
    while (getline(ss, token, ','))
    {
        if(root == nullptr) {
            root = getNode(token);
            q_inp.push(root);
            continue;
        }

        newNode = getNode(token);
        temp = q_inp.front();
        q_inp.pop();

        temp->left = newNode;
        q_inp.push(temp->left);

        getline(ss, token, ',');
        newNode = getNode(token);
        temp->right = newNode;
        q_inp.push(temp->right);
    }

    Solution sol;
    cout << sol.maxDepth(root) << endl;

    return 0;
}
