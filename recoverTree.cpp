#include "common.h"
//not checked yet

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root == nullptr)
            return;
        TreeNode* n1 = nullptr, *n2 = nullptr;
        bool bfound = false;
        TreeNode* current = root, *prev = nullptr, *p = nullptr;
        while(current){
            if(current->left == nullptr){
                if(prev && prev->val > current->val){
                    if(!bfound){
                        bfound = true;
                        n1 = prev;
                    }
                    n2 = current;
                }
                prev = current;
                current = current->right;
            }
            else{
                p = current->left;
                while(p->right && p->right != current)
                    p = p->right;
                if(p->right == nullptr){
                    p->right = current;
                    current = current->left;
                }
                else{
                    p->right = nullptr;
                    if(prev->val > current->val){
                        if(!bfound){
                            bfound = true;
                            n1 = prev;
                        }
                        n2 = current;
                    }
                    prev = current;
                    current  = current->right;
                }
            }
        }
        if(n1 && n2){
            swap(n1->val, n2->val);
        }
    }
};



int main() {

    return 1;
}