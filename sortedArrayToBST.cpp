#include "common.h"
//not checked yet

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int,int)> f = [&nums, &f](int start, int end){
            if(start>end)
                return (TreeNode*) nullptr;
            int mid = (start+end) >> 1;
            TreeNode* p = new TreeNode(nums[mid]);
            p->left = f(start, mid-1);
            p->right = f(mid+1, end);
            return p;
        };

        return f(0, nums.size()-1);
    }
};


int main() {
    vector<int> data{};
    auto root = Solution().sortedArrayToBST(data);
    cout << ((root == nullptr)? "nullptr": "valid") << endl;
    return 1;
}