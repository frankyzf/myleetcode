#include "common.h"
//not checked yet
class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        st.push(root);
        TreeNode* head = root;
        while(!st.empty()){
            auto p = st.top();
            if(p->left == head || p->right == head || (p->left == nullptr && p->right == nullptr)){
                st.pop();
                res.push_back(p->val);
                head = p;
            }
            else {
                if (p->right) {
                    st.push(p->right);
                }
                if (p->left) {
                    st.push(p->left);
                }
            }
        }

        return res;
    }
};


int main() {
    vector<string> data {"1","#","2","3"};
    auto root = constructTree(data);
    auto r = Solution().postorderTraversal(root);
    for(auto i: r)
        cout << i << ";";
    cout << endl;
    return 1;
}