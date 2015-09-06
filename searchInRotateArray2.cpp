#include "common.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int m = nums.size();
        if(m == 0)
            return false;
        int first = 0, last = m;
        while(first < last)
        {
            int mid = (first+last)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[first] < nums[mid])
            {
                if(nums[first]<= target && target < nums[mid])
                    last = mid ;
                else
                    first = mid +1;
            }
            else if (nums[first] > nums[mid])
            {
                if(nums[mid] <= target && target < nums[first])
                    first = mid + 1;
                else
                    last = mid;
            }
            else // equal
                ++first;
        }
        return false;

    }
};


int main() {

    return 1;
}