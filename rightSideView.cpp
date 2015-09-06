#include "common.h"
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root)
            q.push(root);
        while(!q.empty()){
            queue<TreeNode*> t;
            while( q.size() > 1){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    t.push(node->left);
                if(node->right)
                    t.push(node->right);
            }
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if(node->left)
                t.push(node->left);
            if(node->right)
                t.push(node->right);
            q.swap(t);
        }
        return res;
    }
};


int main() {

    return 1;
}