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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* pre = head;

        while(n > 0) {
            cur = cur->next;
            n--;
        }

        if(!cur) return pre->next;

        while(cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

int main(){
    return 0;
}
