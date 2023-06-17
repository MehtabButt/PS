#include <iostream>
#include <limits>
#include <cmath>
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
    int max_path_sum(TreeNode* root, int& max_value) {
        if(root == nullptr) return 0;
        int l = max_path_sum(root->left, max_value);
        int r = max_path_sum(root->right, max_value);
        int m = max(
            r+l+root->val,
            max(
                l+root->val,
                max(
                    r+root->val,
                    root->val
                )
            )
        );
        if(m > max_value) max_value = m;
        return m==r+l+root->val ? root->val + max(r, l) : m;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max = numeric_limits<int>::min();
        max_path_sum(root, max);
        return max;
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
        token = "null";

        getline(ss, token, ',');
        newNode = getNode(token);
        temp->right = newNode;
        q_inp.push(temp->right);
    }

    Solution sol;
    cout << sol.maxPathSum(root) << endl;
    return 0;
}
