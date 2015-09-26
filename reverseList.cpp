#include "common.h"
//not checked yet
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = head, *p2 = nullptr;
        ListNode* prev = nullptr;

        if(head == nullptr)
            return nullptr;
        p2 = p1->next;

        while(p2){
            p1->next = prev;
            prev = p1;
            p1 = p2;
            p2 = p2->next;
        }
        p1->next = prev;
        return p1;

    }
};

int main() {

    return 1;
}