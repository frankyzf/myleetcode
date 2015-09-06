#include "common.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size();
        while(begin < end)
        {
            int mid = begin + (end-begin)/2;
            if(nums[mid] == target)
                return mid;
            else if (nums[begin] <= nums[mid]) //begin <= mid
            {
                if(nums[begin] <= target && target < nums[mid])
                    end = mid;
                else
                    begin = mid+1;
            }
            else // begin > mid
            {
                if(nums[begin] > target && target >= nums[mid])
                    begin = mid +1;
                else
                    end = mid ;
            }
        }
        return -1;
    }
};


int main() {

    return 1;
}