//
// Created by feng on 7/28/15.
//

#include "common.h"

class Solution {
public:


    int kthSmallest(TreeNode* root, int k) {
        function<int(TreeNode*)> cn = [&cn](TreeNode* root){
            if(root == nullptr)
                return 0;
            else{
                return cn(root->left) + cn(root->right) + 1;
            }
        };
        function<TreeNode*(TreeNode*, int)> f = [&f, &cn](TreeNode* root, int k){
            if(k == 1){
              while(root->left){
                  root = root->left;
              }
              return root;
            }
            int ln = cn(root->left);
            if(ln > k-1){
                return f(root->left, k);
            }
            else if (ln ==  k-1){
                return root;
            }
            else{
                return f(root->right, k - ln -1);
            }
        };
        auto node = f(root, k);
        return node->val;
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