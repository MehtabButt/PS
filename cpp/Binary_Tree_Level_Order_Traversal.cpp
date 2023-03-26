#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        vector<int> sub_vec;
        queue<TreeNode*> q;
        TreeNode* temp;
        int s;
        if(root != nullptr) q.push(root);
        while (!q.empty()){
            s = q.size();
            while(s > 0) {
                temp = q.front();
                q.pop();
                sub_vec.push_back(temp->val);
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
                s -= 1;
            }
            vec.push_back(sub_vec);
            sub_vec.clear();
        }
        return vec;
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
    vector<vector<int>> out = sol.levelOrder(root);
    return 0;
}
