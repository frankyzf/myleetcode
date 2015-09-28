#include "common.h"
//not checked yet

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        function<TreeNode*(ListNode*, int)> f = [&f](ListNode* p, int len){
            if(p == nullptr || len == 0)
                return (TreeNode*) nullptr;
            int left = (len-1)/2;
            ListNode* root = p;
            for(int i = 0; i < left&& root; ++i){
                root = root->next;
            }
            TreeNode* treeroot = new TreeNode(root->val);
            treeroot->left = f(p, left);
            treeroot->right = f(root->next, len-left-1);
            return treeroot;
        };

        ListNode* visit = head;
        int cnt = 0;
        while(visit){
            ++cnt;
            visit = visit->next;
        }
        return f(head, cnt);
    }
};


int main() {

    return 1;
}