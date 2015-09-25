#include "common.h"
//not checked yet
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode** pp1 = &head, **pp2 = &head;
        if((*pp2) == nullptr || (*pp2)->next == nullptr)
            return nullptr;

        int step = 0;
        do{
            pp1 = &(*pp1)->next;
            pp2 = &(*pp2)->next;
            if(*pp2)
                pp2 = &(*pp2)->next;
            ++step;
        }while(*pp1 && *pp2 && (*pp1) != (*pp2));

        if(*pp2 == nullptr)
            return nullptr;
        else{
            pp1 = &head;
            while(*pp1 != (*pp2)){
                pp1 = &(*pp1)->next;
                pp2 = &(*pp2)->next;
            }
            return *pp1;
        }

    }
};
int main() {

    return 1;
}