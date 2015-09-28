#include "common.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (inorder.size() == 0) {
            return nullptr;
        }
        TreeNode* head = nullptr;

        int begin = 0;
        auto end = inorder.size();
        TreeNode** pp = &head;

        stack<tuple<TreeNode**, int, int>> st;
        st.push(make_tuple( pp ,begin, end));
        for(int i = 0; i < preorder.size(); ++i){
            tie(pp, begin, end) = st.top(); st.pop();
            int value = preorder[i];
            *pp = new TreeNode(value);

            int index = distance(inorder.begin(), find(inorder.begin()+begin, inorder.begin() + end, value));
            if(end-begin > 1) {
                if (index == begin) {
                    st.push(make_tuple(&(*pp)->right, index + 1, end));
                }
                else {
                    if (index != end - 1) {
                        st.push(make_tuple(&(*pp)->right, index + 1, end));
                    }
                    st.push(make_tuple(&(*pp)->left, begin, index));
                }
            }
        }
        return head;
    }
};


int main() {
    vector<int> pre{1,2,3};
    vector<int> inorder{2,1,3};
    auto root = Solution().buildTree(pre, inorder);
    cout << endl;
    return 1;
}