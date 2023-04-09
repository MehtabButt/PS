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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* temp;
        // ListNode* another_head;

        //break list from middle
        while(cur->next and cur->next->next) {
            pre = pre->next;
            cur = cur->next->next;
        }

        cur = pre->next;
        // another_head = cur;
        pre->next = nullptr;
        pre = nullptr;

        //reverse cur
        while(cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        // cur = another_head;
        cur =  pre;
        pre = head;

        while(cur) {
            temp = pre->next;
            pre->next = cur;
            pre = pre->next;
            cur = temp;
        }
        return;
    }
};

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution sol;
    sol.reorderList(l1);
    return 0;
}
