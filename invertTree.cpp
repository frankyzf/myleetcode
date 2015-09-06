//
// Created by feng on 7/28/15.
//

#include "common.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
    }
};