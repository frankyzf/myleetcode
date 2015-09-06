#include "common.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(l1 && l2)
        {
            int val = l1->val + l2->val + carry;
            if(val >= 10)
            {
                val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            tail->next = new ListNode(val);
            tail = tail->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1)
        {
            int val = l1->val + carry;
            if(val == 10)
            {
                carry = 1;
                val = 0;
            }
            else
                carry = 0;
            tail->next = new ListNode(val);
            tail = tail->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int val = l2->val + carry;
            if(val == 10)
            {
                carry = 1;
                val = 0;
            }
            else
                carry = 0;
            tail->next = new ListNode(val);
            tail = tail->next;
            l2 = l2->next;
        }
        if(carry)
        {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head->next;
    }
};


int main() {

    return 1;
}