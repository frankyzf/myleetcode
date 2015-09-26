#include "common.h"
//not checked yet

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
       stack<TreeNode*> st;
        long long prev = numeric_limits<long long>::min();

        do{
            st.push(root);
        }while((root = root->left) != nullptr);
        while(!st.empty()){
            auto p = st.top(); st.pop();
            if(p->val <= prev)
                return false;
            prev = p->val;
            if(p->right){
                p = p->right;
                do{
                    st.push(p);
                }while((p = p->left)!= nullptr);
            }
        }
        return true;
    }
};


int main() {
    vector<string> data{"10","5","15","#","#", "6","20"};
    auto root = constructTree(data);
    cout << Solution().isValidBST(root);
    return 1;
}