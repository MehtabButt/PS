#include <iostream>
#include <sstream>
#include <queue>
#include <limits>
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
    bool is_child_tree;
    int hash_of_tree(TreeNode* root) {
        int c_hash = hash<string>()(to_string(root->val));
        int l_hash = (root->left ? hash_of_tree(root->left) : hash<string>()("null")) - 100;
        int r_hash = (root->right ? hash_of_tree(root->right) : hash<string>()("null")) - 50;
        return c_hash ^ l_hash ^ r_hash;
    }
    int is_sub_tree(TreeNode* root, int sub_hash) {
        if(this->is_child_tree) return hash<string>()("null");
        int c_hash = hash<string>()(to_string(root->val));
        int l_hash = (root->left ? is_sub_tree(root->left, sub_hash) : hash<string>()("null")) - 100;
        int r_hash = (root->right ? is_sub_tree(root->right, sub_hash) : hash<string>()("null")) - 50;
        // l_hash = -l_hash / 10;
        // r_hash = r_hash / 10;
        this->is_child_tree = this->is_child_tree or (sub_hash == (c_hash ^ l_hash ^ r_hash));
        //testing
        // if(root->val == 4) {
        //     cout << c_hash << ' ' << l_hash << ' ' <<r_hash << endl;
        // }
        //
        return c_hash ^ l_hash ^ r_hash;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int sub_root_hash = hash_of_tree(subRoot);
        this->is_child_tree = false;
        is_sub_tree(root, sub_root_hash);
        return this->is_child_tree;
    }
};

TreeNode* getNode(string n) {
    if(n == "null") return nullptr;
    else return new TreeNode(stoi(n));
}

TreeNode* getTreeInput() {
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
    return root;
}

int main(){
    TreeNode* root = getTreeInput();
    TreeNode* subTreeRoot = getTreeInput();

    Solution sol;
    cout << sol.isSubtree(root, subTreeRoot);
    return 0;
}
