#include "common.h"
//not checked yet

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* h = head;
        while(h && m > 1){
            h = h->next;
            --m;
        }
        if(m > 1 || h == nullptr)
            return head;
        ListNode** pp = &h->next;
    }
};

int main() {

    return 1;
}