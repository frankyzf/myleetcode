#include "common.h"
//not checked yet

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        static map<UndirectedGraphNode*, UndirectedGraphNode*> mm;
        if(node == nullptr)
            return nullptr;
        auto it = mm.find(node);
        if(it != mm.end())
            return it->second;
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        mm[node] = newnode;
        for(auto child: node->neighbors){
            auto newchild = cloneGraph(child);
            newnode->neighbors.push_back(newchild);
        }
        return newnode;
    }
};


int main() {

    return 1;
}