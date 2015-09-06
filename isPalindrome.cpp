//
// Created by feng on 8/5/15.
//

#include "common.h"

class Solution {
public:
    int count(ListNode* head)
    {
        int cnt = 0;
        while(head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }

    ListNode* move(ListNode* head, int step){
        while(step > 0){
            head = head->next;
            --step;
        }
        return head;
    }
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev, *p, *next;
        prev = head;
        p = prev?prev->next: nullptr;
        next = p? p->next:nullptr ;
        while(next != nullptr && next != tail)
        {
            p->next = prev;
            prev = p;
            p = next;
            next = next->next;
        }
        if(p)
            p->next = prev;
        return p;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr|| head->next == nullptr)
            return true;
        int size = count(head);
        ListNode* mid = move(head, (size-1)/2);
        ListNode* tailhead = reverse(mid, nullptr);
        ListNode* tail2 = tailhead;
        for (int i = 0; i < (size + 1) / 2; ++i) {
            if (tailhead->val != head->val) {
                break;
            }
            else {
                tailhead = tailhead->next;
                head = head->next;
            }
        }
        reverse(tail2, mid);
        tail2->next = nullptr;
        if (tailhead->val != head->val) {
            return false;
        }
        return true;
    }
};


int main()
{
    ListNode n1{1}, n2{2}, n3{8}, n4{1};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    cout << Solution().isPalindrome(&n1) << endl;
    return 1;
}