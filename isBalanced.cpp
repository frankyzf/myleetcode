#include "common.h"
//not checked yet

class Solution{
public:
    bool isBalanced(TreeNode* root){
        if(root == nullptr){
            return tree;
        }
        function<pair<bool, int>(TreeNode*)> f = [](TreeNode* p){
          if(p == nullptr){
              return make_pair(true, 0);
          }
          else {
            auto left = f(p->left);
              auto right = f(p->right);
              if(!left->first || !right->first){
                  return make_pair(false, 0);
              }
              else{
                  if(abs(left->second - right->second) > 1)
                      return make_pair(false, 0);
                  else{
                      auto m = max(left->second, right->second);
                      return make_pair(true, m);
                  }
              }
          }
        };
        return f(root).first;
    }
};


int main() {

    return 1;
}