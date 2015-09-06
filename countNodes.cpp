//
// Created by feng on 8/11/15.
//

#include "common.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        if(root == nullptr)
            return 0;
        q.push(root);
        bool valid = true;
        while(valid){
            ++ level;
            queue<TreeNode*> tq;
            while(!q.empty()){
                TreeNode* node = q.front();
                if(node->left)
                    tq.push(node->left);

                if(node->right)
                    tq.push(node->right);

                if(node->left == nullptr || node->right == nullptr)
                    valid = false;
                q.pop();
            }
            q.swap(tq);
        }
        return pow(2, level) + q.size();

    }
};

int main(){
    return 1;
}