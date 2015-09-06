//
// Created by feng on 8/11/15.
//


#include "common.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int size = nums.size();
        int left = 0, right = size;
        if(size == 1)
            return 0;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] < nums[mid-1]){
                right = mid;
            }
            else if (mid < right -1 && nums[mid] < nums[mid+1]){
                left = mid+1;
            }
            else{
                return mid;
            }
        }
        return left;
    }
};

int main(){
    auto a = vector<int>{1,2,3,1};
    cout << Solution().findPeakElement(a);
    return 1;
}