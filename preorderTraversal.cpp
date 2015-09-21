#include "common.h"
//not checked yet

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* n = st.top(); st.pop();
            if(n->right)
                st.push(n->right);
            if(n->left)
                st.push(n->left);
            res.push_back(n->val);
        }
        return res;
    }
};

int main() {

    return 1;
}