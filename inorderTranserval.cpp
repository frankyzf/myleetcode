#include "common.h"
//not checked yet

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        st.push(root);
        while(root->left){
            root = root->left;
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode* p = st.top();
            st.pop();
            res.push_back(p->val);
            if(p->right){
                p = p->right;
                st.push(p);
                while(p->left){
                    p = p->left;
                    st.push(p);
                }
            }
        }
        return res;
    }
};
int main() {
    vector<string> data {"1","#","2"};
    auto root = constructTree(data);
    auto r = Solution().inorderTraversal(root);
    for(auto i: r)
        cout << i <<", ";
    return 1;
}