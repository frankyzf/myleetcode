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
    if(con.size() > 0) {


        queue<TreeNode *> q;
        root = new TreeNode(atoi(con[0].c_str()));
        q.push(root);

        int ci = 1;
        while (ci < con.size()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *pp = q.front();
                q.pop();

                if( ci < con.size() && con[ci] != string("#")) {
                    pp->left = new TreeNode(atoi(con[ci].c_str()));
                    q.push(pp->left);
                }
                else {
                    pp->left = nullptr;
                }
                ++ci;


                if( ci < con.size() && con[ci] != string("#")) {
                    pp->right = new TreeNode(atoi(con[ci].c_str()));
                    q.push(pp->right);
                }
                else{
                    pp->right = nullptr;
                }
                ++ci;
            }
        }
    }
    return root;
}


#endif //NEW_LEETCODE_COMMON_H
