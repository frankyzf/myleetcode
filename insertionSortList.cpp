#include "common.h"
//not checked yet

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* p = head;
        ListNode* head2 = nullptr;

        while(p != nullptr){
            ListNode** pp2 = &head2;
            while(*pp2 && (*pp2)->val < p->val){
                pp2 = &(*pp2)->next;
            }

            if(*pp2 == nullptr){
                *pp2 = p;
                p = p->next;
                (*pp2)->next = nullptr;
            }
            else{
                ListNode* tp = *pp2;
                *pp2 = p;
                p = p->next;
                (*pp2)->next = tp;
            }
        }
        return head2;
    }
};



int main() {

    return 1;
}