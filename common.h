//
// Created by feng on 7/26/15.
//

#ifndef NEW_LEETCODE_COMMON_H
#define NEW_LEETCODE_COMMON_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <queue>
#include <functional>
#include <sstream>
#include <ctype.h>
#include <tuple>
#include <functional>
#include <cstring>
#include <bitset>
#include <assert.h>

#define DEBUG
using namespace std;




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

TreeNode* constructTree(vector<string>& con){
    TreeNode* root = nullptr;
    queue<TreeNode*> q;
    root = new TreeNode(atoi(con[0].c_str()));
    q.push(root);

    int ci = 1;
    while(ci < con.size()){
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* pp = q.front(); q.pop();
            if (con[ci] == "#") {
                pp->left = nullptr;
            }
            else {
                pp->left = new TreeNode(atoi(s.c_str()));
                q.push(pp->left);
            }
            ++ci;

            if(con[ci] == "#")
                pp->right = nullptr;
            else{
                pp->right = new TreeNode(atoi(s.c_str()));
                q.push(pp->right);
            }
            ++ci;
        }
    }
    return root;
}


#endif //NEW_LEETCODE_COMMON_H
