#include "common.h"
//not checked yet



class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        function<TreeNode*(TreeNode *)> f = [&f](TreeNode *root) {
            TreeNode* ptail = root;
            TreeNode* right = root->right;
            TreeNode* left = root->left;
            if (left != nullptr){
                root->right = left;
                root->left = nullptr;
                ptail = f(left);
                ptail->right = right;
            }
            if(right != nullptr){
                ptail = f(right);
            }
            return ptail;
        };
        f(root);
    }
};




int main() {

    return 1;
}