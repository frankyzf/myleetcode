#include "common.h"
//not checked yet

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        int val = head->val;
        ListNode* left = nullptr,  *right = nullptr,  *mid = nullptr;
        ListNode** pplefttail = &left, **pprighttail = &right, **ppmidtail = &mid;
        ListNode** pp = &head;
        while(*pp){
            if((*pp)->val < val){
                *pplefttail = *pp;
                pplefttail = &(*pplefttail)->next;
            }
            else if((*pp)->val > val){
                *pprighttail = *pp;
                pprighttail = &(*pprighttail)->next;
            }
            else{
                *ppmidtail = *pp;
                ppmidtail = &(*ppmidtail)->next;
            }
            pp = &(*pp)->next;
        }
        *pplefttail = nullptr;
        *pprighttail = nullptr;
        *ppmidtail = nullptr;


        left = sortList(left);
        right = sortList(right);
        pp = &mid;
        ListNode* reshead = *pp;
        if(left != nullptr){
            pp = &left;
            reshead = *pp;
            while(*pp){
                pp = &(*pp)->next;
            }
            *pp = mid;
        }
        *ppmidtail = right;
        return reshead;
    }
};


int main() {
    vector<int> data {1};
    auto root = constructList(data);
    root = Solution().sortList(root);
    ListNode** pp = &root;
    while(*pp){
        cout << (*pp)->val << ";";
        pp = &(*pp)->next;
    }

    return 1;
}