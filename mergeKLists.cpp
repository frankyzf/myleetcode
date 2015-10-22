#include "common.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = nullptr;
        ListNode* tail = nullptr;
        auto cmp  = [](ListNode* p1, ListNode* p2){
            return p1->val > p2->val;
        };
        auto pit = lists.begin();
       while(pit != lists.end()){
            if(*pit == nullptr){
                pit = lists.erase(pit);
            }
           else{
                ++pit;
            }
        }

        make_heap(lists.begin(), lists.end(), cmp);
        while(lists.size()){
            auto p = *lists.begin();
            pop_heap(lists.begin(), lists.end(), cmp);
            if(root == nullptr){
                root = p;
                tail = root;
            }
            else{
                tail->next = p ;
                tail = tail->next;
            }
            auto pnext = p->next;
            tail->next = nullptr;
            if(pnext){
                lists.back() = pnext;
                push_heap(lists.begin(), lists.end(), cmp);
            }else{
                lists.pop_back();
            }
        }
        return root;
    }
};



int main() {
    vector<int> data1{-10,-9,-8,-7,-2,-1,0,1};
    vector<int> data2{1};
    auto pl1 = constructList(data1);
    auto pl2 = constructList(data2);
    vector<ListNode*> data{nullptr, pl1, pl2, nullptr};
    auto pr = Solution().mergeKLists(data);
    while(pr!= nullptr){
        cout << pr->val << "->";
        pr = pr->next;
    }
    cout << endl;

    return 1;
}