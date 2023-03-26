#include <iostream>
#include <queue>
#include <sstream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
    TreeNode* getNode(string s) {
        if(s == "null") return nullptr;
        else return new TreeNode(stoi(s));
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp;
        string s = "[";
        string null_s = "";

        if(root != nullptr) q.push(root);

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(temp == nullptr) null_s += "null,";
            else {
                s += null_s;
                null_s = "";
                s += to_string(temp->val) + ',';
            }
            if(temp != nullptr) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        if(s.back() == ',') s[s.length()-1] = ']';
        else s += ']';
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.length()-2);
        stringstream ss(data);
        string token;
        TreeNode* root = nullptr;
        TreeNode *newNode;
        queue<TreeNode*> q;
        while(getline(ss, token, ',')) {
            if(root == nullptr) {
                root = this->getNode(token);
                q.push(root);
                continue;
            }
            while(!q.empty() and q.front() == nullptr) q.pop();

            newNode = this->getNode(token);
            q.front()->left = newNode;
            q.push(q.front()->left);

            token = "null";

            getline(ss, token, ',');
            newNode = this->getNode(token);
            q.front()->right = newNode;
            q.push(q.front()->right);
            q.pop();
        }
        return root;
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

    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(root));
    return 0;
}
