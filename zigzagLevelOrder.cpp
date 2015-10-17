#include "common.h"
//not checked yet

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> q;
        bool bverse = false;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> v;
            vector<int> r;
            TreeNode* p;
            while(!q.empty()){
                p = q.front();
                r.push_back(p->val);
                q.pop();
                if (!bverse) {
                    if(p->left)
                        v.push_back(p->left);
                    if(p->right)
                        v.push_back(p->right);
                }
                else{
                    if(p->right)
                        v.push_back(p->right);
                    if(p->left)
                        v.push_back(p->left);
                }
            }
            res.push_back(move(r));
            reverse(v.begin(), v.end());
            for(auto node: v){
                q.push(node);
            }
            bverse = !bverse;
        }
    }
};


int main() {
    vector<string> con = {"3", "9", "20", "#", "#", "15", "7"};
    auto root = constructTree(con);
    auto res = Solution().zigzagLevelOrder(root);
    for(auto v: res){
        for(auto i: v){
            cout << i << ",";
        }
        cout << endl;
    }
    return 1;
}