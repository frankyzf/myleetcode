#include "common.h"
class Solution {
public:
    pair<int,int> maxP(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }
        auto l = maxP(root->left);
        auto r = maxP(root->right);
        int hl = max(l.first, 0);
        int hr = max(r.first, 0);


        int subtreep = hr + hl + root->val;

        int branchp = max(hl, hr) + root->val;
        return make_pair(branchp, subtreep);
    }
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto r = maxP(root);
        return r.second;
    }
};


int main() {

    return 1;
}