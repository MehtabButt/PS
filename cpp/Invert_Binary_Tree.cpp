#include <iostream>
#include <sstream>
#include <queue>
#include <cmath>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        TreeNode *temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};

TreeNode* getNode(string n) {
    if(n == "null") return nullptr;
    else return new TreeNode(stoi(n));
}

void printTree(TreeNode *root, int h) {
    queue<TreeNode*> q_out;
    TreeNode *temp;
    int s;

    if(root != nullptr) q_out.push(root);
    while(!q_out.empty()) {
        s = q_out.size();
        h -= 1;
        cout << string(h, ' ');
        while(s > 0) {
            temp = q_out.front();
            q_out.pop();

            cout << temp->val << ' ';

            if(temp->left != nullptr) q_out.push(temp->left);
            if(temp->right != nullptr) q_out.push(temp->right);
            s -= 1;
        }
        cout << endl;
    }
}

int main(){
    string inp, token;
    int nodes = 0;
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
            nodes += 1;
            continue;
        }

        newNode = getNode(token);
        temp = q_inp.front();
        q_inp.pop();

        temp->left = newNode;
        q_inp.push(temp->left);
        if(newNode != nullptr) nodes += 1;
        token = "null";

        getline(ss, token, ',');
        newNode = getNode(token);
        temp->right = newNode;
        q_inp.push(temp->right);
        if(newNode != nullptr) nodes += 1;
    }

    cout << endl;
    printTree(root, ceil(log(nodes)/log(2)));

    Solution sol;
    root = sol.invertTree(root);
    cout << endl;
    printTree(root, ceil(log(nodes)/log(2)));
    return 0;
}
