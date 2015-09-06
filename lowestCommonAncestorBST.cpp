//
// Created by feng on 7/26/15.
//

#include "common.h"

class Solution {
public:
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root && p && q) {
            TreeNode *pl = p->val < q->val? p : q;
            TreeNode *pr = pl == p? q:p;
            while (! (root->val>=pl->val && root->val<=pr->val)) {
                if (root->val > pr->val )
                    root = root->left;
                else
                    root = root->right;
            }
            return root;
        }
        return NULL;
    }
};


int main()
{
    return 1;
}