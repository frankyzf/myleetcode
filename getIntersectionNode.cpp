//
// Created by feng on 8/10/15.
//

#include "common.h"

class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto getLength = [](ListNode* head){
            int cnt = 0;
            while(head){
                head = head->next;
                ++cnt;
            }
            return cnt;
        };
        auto f = [](ListNode* ha, int la, ListNode* hb, int lb){
            int dif = la - lb;
            while(dif > 0){
                ha = ha->next;
                -- dif;
            }
            for(int i = 0; i < lb; ++i){
                if(ha->val == hb->val)
                    return ha;
                else{
                    ha = ha->next;
                    hb = hb->next;
                }
            }
            return (ListNode* )nullptr;
        };
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if(lenA >= lenB){
            return f(headA, lenA, headB, lenB);
        }
        else
            return f(headB, lenB, headA, lenA);

    }
};


int main(){
    auto ff = [](vector<int> vv){
        ListNode* head = new ListNode(0);
        ListNode* h = head;
        for(auto v: vv){
            auto p = new ListNode(v);
            h->next = p;
            h = h->next;
        }
        return head->next;
    };

    auto ha = ff(vector<int> {1,3,5,7,9,11,13,15,17,19,21});
    auto hb = ff(vector<int>{2});

    auto r = Solution().getIntersectionNode(ha, hb);
    if(r == nullptr)
        cout << "nullptr" << endl;
    else
        cout << r->val << endl;

    return 1;
}