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
    int kth, smallest;
    void kth_smallest(TreeNode* root, int& k) {
        if(root == nullptr or this->smallest != -1) return;
        kth_smallest(root->left, k);
        this->kth++;
        if(this->kth == k) {
            this->smallest = root->val;
            return;
        }
        kth_smallest(root->right, k);
    }
public:
    Solution() {
        this->kth = 0;
        this->smallest = -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        kth_smallest(root, k);
        return this->smallest;
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

    int k;
    cin >> k;

    Solution sol;
    cout << sol.kthSmallest(root, k);
    return 0;
}
