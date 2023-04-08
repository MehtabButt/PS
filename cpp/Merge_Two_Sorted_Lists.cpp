#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* temp;
        ListNode* root = nullptr;

        if(l1 and !l2) root = l1;
        else if (!l1 and l2) root = l2;
        else if(!l1 and !l2) root = nullptr;
        else if(l1->val <= l2->val) root = l1;
        else root = l2;

        while(l1 and l2) {
            if(l1->val <= l2->val) {
                while(l1->next and l1->next->val <= l2->val) l1 = l1->next;
                temp = l1->next;
                l1->next = l2;
                l1 = temp;
            }
            else {
                while(l2->next and l2->next->val <= l1->val) l2 = l2->next;
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
        }
        return root;
    }
};

int main(){
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    // ListNode *l1 = nullptr;
    // ListNode *l2 = nullptr;

    // ListNode *l1 = new ListNode(0);
    // ListNode *l2 = nullptr;

    Solution sol;
    ListNode* res = sol.mergeTwoLists(l1, l2);
    return 0;
}
