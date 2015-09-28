#include "common.h"
//not checked yet
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> qt;
        if(root == nullptr)
            return;
        qt.push(root);
        while(!qt.empty()){
            queue<TreeLinkNode*> tmpq;
            while(!qt.empty()){
                auto node = qt.front(); qt.pop();
                if(node->left)
                    tmpq.push(node->left);
                if(node->right)
                    tmpq.push(node->right);
                node->next = qt.empty()? nullptr:qt.front();
            }
            qt.swap(tmpq);
        }
    }
};

int main() {

    return 1;
}