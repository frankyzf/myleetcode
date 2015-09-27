#include "common.h"
//not checked yet
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k ==1 || head == nullptr)
            return head;

        ListNode* prev = nullptr, *p = head, *after;
        ListNode** ppghead = &head;
        after = head?head->next: nullptr;
        bool bend = after == nullptr? true:false;
        while(!bend) {
            int i = 0;
            for(; i < k && after; ++i){
                p->next = prev;
                prev = p;
                p = after;
                after = after->next;
            }
            if(i == k ) {
                swap(prev, *ppghead);
                prev->next = p;
                ppghead = &prev->next;
                bend = after == nullptr;
            }
            else{
                if(i == k-1){
                    swap(p, *ppghead);
                    p->next = nullptr;
                    (*ppghead)->next = prev;
                }
                else{
                    while(after != *ppghead ){
                        p->next = after;
                        after = p;
                        p = prev;
                        prev = prev? prev->next : nullptr;
                    }
                    *ppghead = after;
                }
                bend = true;
            }

        }
        return head;
    }
};


int main() {
    vector<int> data{1,2};
    auto root = constructList(data);
    ListNode** pp = &root;
    cout << "begin" << endl;
    while (*pp) {
        cout << (*pp)->val << ",";
        pp = &(*pp)->next;
    }
    cout << "--" << endl;

    root = Solution().reverseKGroup(root, 3);
    pp = &root;
    while (*pp) {
        cout << (*pp)->val << ",";
        pp = &(*pp)->next;
    }

    return 1;
}