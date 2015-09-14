//
// Created by feng on 7/26/15.
//

#include "common.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        TreeNode* res;
        function<bool(TreeNode*, TreeNode*)>f= [&f](TreeNode* root, TreeNode* p){
            if(root == nullptr)
                return false;
            if(root == p)
                return true;
            else
                return f(root->left, p) || f(root->right, p);
        };

        if (p == root){
            if(f(root, q))
                return root;
            else
                return nullptr;
        }
        else if(q == root){
            if(f(root, p))
                return root;
            else
                return nullptr;
        }
        else if(( res = lowestCommonAncestor(root->left, p, q) ) != nullptr){
            return res;
        }
        else if(( res = lowestCommonAncestor(root->right, p, q) ) != nullptr){
            return res;
        }
        else if (f(root->left, p) && f(root->right, q) ){
            return root;
        }
        else if (f(root->left, q) && f(root->right, p)){
            return root;
        }
        return nullptr;
    }
};


int main()
{
    return 1;
}