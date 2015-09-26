#include "common.h"
//not checked yet


class Solution {
public:
    TreeNode* clone(TreeNode* root){
        if(root == nullptr)
            return nullptr;
        auto newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)
            return vector<TreeNode*>{nullptr};


        function<vector<TreeNode*>(int, int)> f = [this, &f](int start, int end){
            if(start > end)
              return vector<TreeNode*>{nullptr};
            else if (start == end){
              return vector<TreeNode*>{new TreeNode(start)};
            }
            vector<TreeNode*> res;
            for(int i = start; i <= end; ++i){
                auto leftvecpointer = f(start, i-1);
                auto rightvecpointer = f(i+1, end);

               for(int li = 0; li <leftvecpointer.size() -1; ++li){
                   for(int ri = 0; ri < rightvecpointer.size(); ++ri){
                       auto p = new TreeNode(i);
                       p->left = clone(leftvecpointer[li]);
                       p->right = clone(rightvecpointer[ri]);
                       res.push_back(p);
                   }
               }
                for(int ri = 0; ri < rightvecpointer.size()-1; ++ri){
                    auto p = new TreeNode(i);
                    p->left = clone(leftvecpointer.back());
                    p->right = rightvecpointer[ri];
                    res.push_back(p);
                }
                auto p = new TreeNode(i);
                p->left = leftvecpointer.back();
                p->right = rightvecpointer.back();
                res.push_back(p);
            }
            return res;
        };
        return f(1, n);
    }
};


int main() {

    return 1;
}