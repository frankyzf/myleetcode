#include "common.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;
        ListNode* p = head;
        int n = 0;
        while(p->next)
        {
            p = p->next;
            ++n;
        }
        ++n;
        k = (k)%n + 1;


        ListNode* newtail = head;
        for(int i = 0; i < n -k; ++i)
            newtail = newtail->next;
        p->next = head;
        head = newtail->next;
        newtail->next = NULL;
        return head;

    }
};


int main() {

    return 1;
}