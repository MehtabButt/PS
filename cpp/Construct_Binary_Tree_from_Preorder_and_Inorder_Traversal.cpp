#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int> inorder) {
        if(inorder.empty()) return nullptr;
        int c = preorder[0];
        TreeNode* root = nullptr;
        vector<int> temp;
        preorder.erase(preorder.begin());

        vector<int>::iterator it = find(inorder.begin(), inorder.end(), c);
        if(it != inorder.end()) {
            root = new TreeNode(*it);
            temp = vector(inorder.begin(), it);
            root->left = buildTree(preorder, temp);
            temp = vector(it+1, inorder.end());
            root->right = buildTree(preorder, temp);
        }

        return root;
    }
};

vector<int> take_input() {
    string inp, token;
    vector<int> v;
    getline(cin, inp);
    stringstream ss(inp);

    while(getline(ss, token, ',')) {
        v.push_back(stoi(token));
    }

    return v;
}

int main(){
    vector<int> preorder = take_input();
    vector<int> inorder = take_input();
    TreeNode *root;

    Solution sol;
    root = sol.buildTree(preorder, inorder);
    return 0;
}
