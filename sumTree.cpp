#include "common.h"
//not checked yet
class Solution {
public:

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        vector<int> res;
        function<void(TreeNode *, int)> f = [&res, &f](TreeNode *node, int path) {
            if (node == nullptr) {
                throw invalid_argument("should not happen for nullptr");
            }
            if(node->left) {
                f(node->left, path*10 + node->val);
            }
            if(node->right) {
                f(node->right, path*10 + node->val);
            }
            if (node->left == nullptr && node->right == nullptr) {
                res.push_back(path*10+ node->val);
            }
        };
        f(root, 0);
        auto t = accumulate(res.begin(), res.end(), 0);
        return t;
    }
};
int main() {
    vector<string> data = {"1", "2", "3"};
    auto root = constructTree(data);
    cout << Solution().sumNumbers(root);

    return 1;
}