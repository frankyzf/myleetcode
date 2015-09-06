//
// Created by feng on 9/6/15.
//
#include "common.h"

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0)
            return 0;
        unordered_map<int, bool> m;
        for(auto i : num)
            m[i] = true;
        int longest = 1;
        for(const auto& it: m)
        {
            int left = it.first -1;
            while(m.find(left) != m.end())
                --left;
            int right = it.first + 1;
            while(m.find(right) != m.end())
                ++right;
            int len = right - left - 1;
            //cout << it.first << ", " << len << endl;
            longest = std::max(longest, len);
            if(longest == num.size())
                return longest;
        }
        return longest;
    }
};