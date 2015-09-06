#include "common.h"
class BSTIterator {
private:
    TreeNode* cur;
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        if(root){
            cur = root;
            while(cur->left){
                st.push(cur);
                cur = cur->left;
            }
            st.push(cur);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int r = node->val;
        node = node->right;
        if(node){
            while(node->left){
                st.push(node);
                node = node->left;
            }
            st.push(node);
        }
        return r;
    }
};


int main() {

    return 1;
}