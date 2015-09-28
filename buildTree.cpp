#include "common.h"
//not checked yet
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return nullptr;
        }
        TreeNode* head = nullptr;
        stack<tuple<TreeNode**, int, int>> st;
        int size = inorder.size();
        st.push(make_tuple(&head, 0, size));
        TreeNode** pp;
        int b, e;
        for (int i = postorder.size()-1; i >=0 ; --i) {
            int val = postorder[i];
            tie(pp, b, e) = st.top(); st.pop();
            *pp = new TreeNode(val);
            int index = distance(inorder.begin(), find(inorder.begin()+b, inorder.begin()+e, val));
            if(e-b>1){
                if(index == e-1){
                    st.push(make_tuple(&(*pp)->left, b, index));
                }
                else{
                    if(index != b){
                        st.push(make_tuple(&(*pp)->left, b, index));
                    }
                    st.push(make_tuple(&(*pp)->right, index+1, e));
                }
            }
        }
        return head;
    }
};

int main() {

    return 1;
}