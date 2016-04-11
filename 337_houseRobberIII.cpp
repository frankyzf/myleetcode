//
// Created by fzhong on 4/11/2016.
//
#include "common.h"
using namespace std;



class Solution {
public:
    unordered_map<TreeNode*, int> selectmm;
    unordered_map<TreeNode*, int> unselectmm;

    int f(TreeNode* node, bool bParentSelect) {
        if(node == nullptr)
            return 0;
        else if(bParentSelect){
            if(this->selectmm.count(node) == 0){
                this->selectmm[node] = f(node->left, false) + f(node->right, false);
            }
            return this->selectmm[node];
        }
        else{
            if(this->unselectmm.count(node) == 0) {
                auto m = f(node->left, false) + f(node->right, false);
                auto n = f(node->left, true) + f(node->right, true) + node->val;
                this->unselectmm[node] = max(m, n);
//                if(this->unselectmm[node] == m)
//                    cout << " node:" << node->val << " not select" << endl;
//                else
//                    cout << " node:" << node->val << " got select!" << endl;
            }
            return this->unselectmm[node];
        }
    };

    int rob(TreeNode* root) {

        return f(root, false);

    }
};



int main() {
    auto v = vector<string>{"3","4","5","1","3","#","1"};
    auto root = constructTree(v);
    cout << "solution:" << Solution().rob(root);
    return 0;
}
