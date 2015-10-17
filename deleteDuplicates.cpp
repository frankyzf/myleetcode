#include "common.h"
//not checked yet


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* p = head;
        ListNode** prev = &head;
        while(p){
            bool bdup = false;
            while( p && p->next && p->val == p->next->val){
                auto tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                bdup = true;
            }
            if(bdup){
                *prev = p->next;
                auto tmp = p;
                p = p->next;
                delete tmp;
            }
            else{
                prev = &(p->next);
                p = p->next;
            }
        }
        return head;
    }
};



int main() {
    vector<int> data {1,2,3,3,4,4,5};
    auto root = constructList(data);
    root = Solution().deleteDuplicates(root);
    ListNode* p = root;
    while(p){
        cout << p->val << ",";
        p = p->next;
    }
    return 1;
}