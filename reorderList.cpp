#include "common.h"
//not checked yet


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode** pp1 = &head;
        ListNode** pp2 = &head;
        for(int i = 0; i < 2 && *pp2 ; ++i)
            pp2  = &(*pp2)->next;
        while(*pp2){
            pp1 = &(*pp1)->next;
            pp2 = &(*pp2)->next;
            if(*pp2)
                pp2 = &(*pp2)->next;
        }
        ListNode* head2 = *pp1?(*pp1)->next: nullptr;
        ListNode* prev = nullptr, *after = nullptr;
        if(*pp1)
            (*pp1)->next = nullptr;
        if(head2)
            after = head2->next;
        while(after){
            head2->next = prev;
            prev = head2;
            head2 = after;
            after = after->next;
        }
        if(head2)
            head2->next = prev;
        pp1 = &head;
        ListNode* lp2 = head2;
        while(*pp1 && lp2){
            ListNode* tmpp1 = (*pp1)->next, *tmpp2 = lp2->next;
            (*pp1)->next = lp2;
            lp2->next = tmpp1;
            pp1 = &lp2->next;
            lp2 = tmpp2;
        }

    }
};


int main() {
    vector<int> data{1,2};
    auto root = constructList(data);
    Solution().reorderList(root);
    ListNode** pp = &root;
    while(*pp){
        cout << (*pp)->val << ",";
        pp = &(*pp)->next;
    }
    return 1;
}