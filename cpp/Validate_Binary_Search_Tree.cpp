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
    TreeNode* getMax(TreeNode* root) {
        while(root and root->right != nullptr) root = root->right;
        return root;
    }

    TreeNode* getMin(TreeNode* root) {
        while(root and root->left != nullptr) root = root->left;
        return root;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode* l_max = getMax(root->left);
        TreeNode* r_min = getMin(root->right);

        return  (l_max ? l_max->val < root->val : true) and
                (r_min ? r_min->val > root->val : true) and
                isValidBST(root->left) and isValidBST(root->right);
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
    TreeNode *newNode = nullptr;
    queue<TreeNode*> q_inp;
    while (getline(ss, token, ','))
    {
        if(root == nullptr) {
            root = getNode(token);
            q_inp.push(root);
            continue;
        }

        while(!q_inp.empty() and q_inp.front() == nullptr) q_inp.pop();

        newNode = getNode(token);
        q_inp.front()->left = newNode;
        q_inp.push(q_inp.front()->left);

        token = "null";

        getline(ss, token, ',');
        newNode = getNode(token);
        q_inp.front()->right = newNode;
        q_inp.push(q_inp.front()->right);
        q_inp.pop();
    }

    Solution sol;
    cout << sol.isValidBST(root);
    return 0;
}
