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
#include <tuple>
#include <list>

#define DEBUG
using namespace std;




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

 struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

 struct UndirectedGraphNode {
         int label;
         vector<UndirectedGraphNode *> neighbors;
         UndirectedGraphNode(int x) : label(x) {};
     };

 struct RandomListNode {
         int label;
         RandomListNode *next, *random;
         RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


struct Point {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
    };


 struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };

RandomListNode* constructRandomList(vector<int> data){
    RandomListNode* root = nullptr;
    RandomListNode** pp = &root;
    for(auto i: data){
        *pp = new RandomListNode(i);
        pp = &(*pp)->next;
    }
    return root;
}



ListNode* constructList(vector<int> data){
    ListNode* root = nullptr;
    ListNode** pp = &root;
    for(auto i: data){
        *pp = new ListNode(i);
        pp = &(*pp)->next;
    }
    return root;
}

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
