#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true) {
            if(p->val < root->val and q->val < root->val) {
                if(root->left) root = root->left;
                else return nullptr;
            }
            else if(p->val > root->val and q->val > root->val) {
                if(root->right) root = root->right;
                else return nullptr;
            }
            else {
                return root;
            }
        }
    }
};

TreeNode* getNode(string n) {
    try
    {
        if(n == "null") return nullptr;
        else return new TreeNode(stoi(n));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return nullptr;
    }
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
    int p, q;
    cin >>p >>q;
    TreeNode *out = sol.lowestCommonAncestor(root, new TreeNode(p), new TreeNode(q));
    cout << out->val;
    return 0;
}
