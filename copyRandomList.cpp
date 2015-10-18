#include "common.h"
//not checked yet

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
            return nullptr;
        map<RandomListNode*, RandomListNode*> mm;
        RandomListNode* head2;
        RandomListNode** pp = &head;
        while(*pp){
            RandomListNode* tp = new RandomListNode((*pp)->label);
            mm[*pp] = tp;
            RandomListNode* tmp = (*pp)->next;
            (*pp)->next = tp;
            tp->next = tmp;
            pp = &tp->next;
        }
        pp = &head;
        RandomListNode** pp2 = &head2;
        while(*pp){
            auto p = (*pp)->next;
            auto random = (*pp)->random;
            p->random = mm[random];
            (*pp)->next = p->next;
            p->next = nullptr;
            (*pp2) = p;
            pp = &(*pp)->next;
            pp2 = &(*pp2)->next;
        }

        return head2;
    }
};

int main() {
    vector<int> data{-1, -1};
    auto root = constructRandomList(data);
    auto r2 = Solution().copyRandomList(root);

    return 1;
}