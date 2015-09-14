#include "common.h"


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr){
            return res;
        }
        function<void(TreeNode*, string)> f = [&res, &f](TreeNode* node, string base){
            stringstream ss ;
            ss<< base  << "->" << node->val;
            if(node->left ) {
                f(node->left, ss.str());
            }
            if(node->right) {
                f(node->right, ss.str());
            }
            if(!node->left && !node->right ){
                res.push_back(ss.str());
            }
        };

        stringstream ss;
        ss << root->val ;
        if(root->left ) {
            f(root->left, ss.str());
        }
        if(root->right) {
            f(root->right, ss.str());
        }
        if(!root->left && !root->right ){
            res.push_back(ss.str());
        }
        return res;
    }
};

int main() {
    TreeNode node1(1), node2(2);
    node1.left = &node2;
    auto r = Solution().binaryTreePaths(&node1);
    for(auto& s: r)
        cout << s << endl;

    return 1;
}