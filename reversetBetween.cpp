#include "common.h"
//not checked yet

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = nullptr, *p = head, *after = nullptr;
        int i = 0;
        for(i = 0; i < m-2 && p; ++i ){
            p = p->next;
        }
        if(m >= 2)
            prev = p;
        if(m >= 2 && p)
            p = p->next;
        if(p == nullptr){
            return head;
        }
        auto midhead = prev;
        auto midtail = p;
        after = p->next;
        for (auto i = m; i < n && after; ++i) {
            p->next = prev;
            prev = p;
            p = after;
            after = after->next;
        }
        p->next = prev;
        if(midhead)
            midhead->next = p;
        else
            head = p;
        midtail->next = after;
        return head;
    }
};

int main() {
    vector<int> data {1,2,3};
    auto root = constructList(data);
    root = Solution().reverseBetween(root, 2, 3);
    ListNode** pp = &root;
    while(*pp){
        cout << (*pp)->val << ",";
        pp = &(*pp)->next;
    }
    return 1;
}