//
// Created by feng on 7/28/15.
//


#include "common.h"

class Solution {
public:


    pair<TreeNode*, int>  findNode(TreeNode* root, TreeNode*p, TreeNode* q )
    {
        if (root)
        {
            TreeNode* pl, *pr;
            int il, ir; // 1 success, 2 left, 3 right, 0 none
            tie(pl, il) = findNode(root->left, p, q);
            if(il == 1)
                return make_pair(pl, il);
            tie(pr, ir) = findNode(root->right, p, q);
            if(ir == 1)
                return make_pair(pr, ir);

            if(il == 2&& ir == 3 || il == 3 && ir == 2 )
                return make_pair(root, 1);

            if(root == p)
                if (il == 3 || ir == 3)
                    return make_pair(root, 1);
                else
                    return make_pair(nullptr, 2);
            else if (root == q)
                    if (il == 2 || ir == 2)
                        return make_pair(root, 1);
                    else
                        return make_pair(nullptr, 3);
        }
        return make_pair(nullptr, 0);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* res;
        tie(res, ignore) = findNode(root, p, q);
        return res;
    }
};

int main()
{
    return 1;
}