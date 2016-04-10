//
// Created by tjuzf_000 on 4/10/2016.
//

#include "common.h"


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode** pp = &head;
        ListNode* pevenheader = new ListNode(1);
        ListNode* peventail = pevenheader;
        while(*pp && (*pp)->next){
            peventail->next = (*pp)->next;
            peventail = peventail->next;
            (*pp)->next = (*pp)->next->next;
            pp = &(*pp)->next;
            peventail->next = nullptr;
        }
        if(*pp){
            pp = &(*pp)->next;
        }
        *pp = pevenheader->next;
        delete pevenheader;
        return head;
    }
};


