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
    bool isSameNode(TreeNode* p, TreeNode* q) {
        if((p == nullptr and q != nullptr) or (p != nullptr and q == nullptr) or (p != nullptr and q != nullptr and p->val != q->val)) return false;
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!isSameNode(p, q)) return false;

        if(p != nullptr) {
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }
        return true;
    }
};

TreeNode* getNode(string n) {
    if(n == "null") return nullptr;
    else return new TreeNode(stoi(n));
}

TreeNode* takeTreeInput(string inp) {
    string token;
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
        token = "null";

        getline(ss, token, ',');
        newNode = getNode(token);
        temp->right = newNode;
        q_inp.push(temp->right);
    }
    return root;
}

int main(){
    string inp;
    TreeNode* p;
    TreeNode* q;

    getline(cin, inp);
    p = takeTreeInput(inp);

    getline(cin, inp);
    q = takeTreeInput(inp);

    Solution sol;
    cout << sol.isSameTree(p, q) << endl;

    return 0;
}
