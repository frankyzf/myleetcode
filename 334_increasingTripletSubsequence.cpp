//
// Created by tjuzf_000 on 4/10/2016.
//

#include "common.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        vector<bool> larger{false};
        int minn = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] > minn){
                larger.push_back(true);
            }
            else{
                larger.push_back(false);
                minn = min(minn, nums[i]);
            }
        }
        int maxn = *nums.rbegin();
        for (int j = nums.size() -2; j >= 0; --j) {
            if(larger[j] && nums[j] < maxn)
                return true;
            else{
                maxn = max(maxn, nums[j]);
            }
        }
        return false;
    }
};