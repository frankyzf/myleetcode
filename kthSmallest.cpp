//
// Created by feng on 7/28/15.
//

#include "common.h"

class Solution {
public:


    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, res = 0;
        TreeNode* cur = root, * prev = nullptr;
        while(cur != nullptr && cnt < k)
        {
            if(cur->left == nullptr)
            {
                ++cnt;
                if(cnt == k)
                    res = cur->val;
                cur = cur->right;
            }
            else{
                prev = cur->left;
                while(prev->right != nullptr && prev->right != cur)
                    prev = prev->right;
                if(prev->right == nullptr)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = nullptr;
                    ++cnt;
                    if(cnt == k)
                        res = cur->val;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};


int main()
{
    TreeNode root(2);
    TreeNode node1(1);
    TreeNode node2(3);
    root.left = &node1;
    //root.right = &node2;
    cout << "res:" << Solution().kthSmallest(&root, 1);
    return 1;
}