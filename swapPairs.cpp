#include "common.h"
//not checked yet

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode** first = &head, **second;
        while(first && *first ){
            second =  &(*first)->next;
            if(*second){
                auto tmp1 = *first;
                auto tmp2 = *second;
                auto tmp3 = (*second)->next;
                *first = tmp2;
                tmp2->next = tmp1;
                tmp1->next = tmp3;
                first = &tmp1->next ;
            }
            else{
                first = nullptr;
            }
        }
        return head;
    }
};

int main() {
    vector<int> data{1,2};
    auto p = constructList(data);
    auto lp = Solution().swapPairs(p);
    while(lp) {
        cout << lp->val << "->";
        lp = lp->next;
    }
    return 1;
}