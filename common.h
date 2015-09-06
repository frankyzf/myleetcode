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


#endif //NEW_LEETCODE_COMMON_H
