#include "common.h"
//not checked yet


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        function<void(TreeNode*, int, vector<int>&)> f = [&res, &f](TreeNode* root, int sum, vector<int>& path){
            if(root == nullptr) {
                return;
            }
            path.push_back(root->val);
            sum -= root->val;
            if(sum == 0 && (root->left == nullptr && root->right == nullptr))
            {
                res.push_back(path);
            }
            else{
                if(root->left){
                    f(root->left, sum, path);
                }
                if(root->right) {
                    f(root->right, sum, path);
                }
            }
            path.pop_back();
        };
        auto v = vector<int>{};
        f(root, sum, v);
        return res;
    }
};


int main() {
    vector<string> data{"1","2"};
    auto root = constructTree(data);
    auto res = Solution().pathSum(root, 3);
    for (const auto &r: res) {
        for(auto i:r )
            cout << i << ",";
        cout << endl;
    }


    return 1;
}